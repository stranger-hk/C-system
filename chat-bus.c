#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOTAL_SEATS 30
#define NAME_LENGTH 50

struct Passenger {
    char name[NAME_LENGTH];
    int seat_number;
    int is_reserved;
};

struct Passenger passengers[TOTAL_SEATS];

void initialize() {
    for (int i = 0; i < TOTAL_SEATS; i++) {
        passengers[i].is_reserved = 0;
    }
}

void bookSeat() {
    char name[NAME_LENGTH];
    int seat_number;

    printf("Enter passenger name: ");
    scanf("%s", name);

    printf("Enter preferred seat number (1-%d): ", TOTAL_SEATS);
    scanf("%d", &seat_number);

    if (seat_number < 1 || seat_number > TOTAL_SEATS) {
        printf("Invalid seat number\n");
        return;
    }

    if (passengers[seat_number - 1].is_reserved) {
        printf("Seat already reserved\n");
        return;
    }

    passengers[seat_number - 1].is_reserved = 1;
    passengers[seat_number - 1].seat_number = seat_number;
    strcpy(passengers[seat_number - 1].name, name);

    printf("Seat booked successfully for %s\n", name);
}

void modifyOrCancel() {
    int choice;
    printf("1. Modify reservation\n");
    printf("2. Cancel reservation\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        int seat_number;
        printf("Enter seat number to modify: ");
        scanf("%d", &seat_number);

        if (seat_number < 1 || seat_number > TOTAL_SEATS) {
            printf("Invalid seat number\n");
            return;
        }

        if (!passengers[seat_number - 1].is_reserved) {
            printf("No reservation found for seat number %d\n", seat_number);
            return;
        }

        printf("Enter new passenger name: ");
        scanf("%s", passengers[seat_number - 1].name);

        printf("Reservation modified successfully for seat %d\n", seat_number);
    } else if (choice == 2) {
        int seat_number;
        printf("Enter seat number to cancel reservation: ");
        scanf("%d", &seat_number);

        if (seat_number < 1 || seat_number > TOTAL_SEATS) {
            printf("Invalid seat number\n");
            return;
        }

        if (!passengers[seat_number - 1].is_reserved) {
            printf("No reservation found for seat number %d\n", seat_number);
            return;
        }

        passengers[seat_number - 1].is_reserved = 0;
        printf("Reservation canceled successfully for seat %d\n", seat_number);
    } else {
        printf("Invalid choice\n");
    }
}

void ticketHistory() {
    printf("Ticket History:\n");
    printf("Seat No.\tPassenger Name\n");
    for (int i = 0; i < TOTAL_SEATS; i++) {
        if (passengers[i].is_reserved) {
            printf("%d\t\t%s\n", passengers[i].seat_number, passengers[i].name);
        }
    }
}

int main() {
    int choice;

    initialize();

    while (1) {
        printf("\nBus Reservation System\n");
        printf("1. Book a seat\n");
        printf("2. Modify or cancel reservation\n");
        printf("3. Ticket history\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                bookSeat();
                break;
            case 2:
                modifyOrCancel();
                break;
            case 3:
                ticketHistory();
                break;
            case 4:
                printf("Exiting program\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
