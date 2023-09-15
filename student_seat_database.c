#include <stdio.h>
#include <string.h>

int editStudentDatabase();
int initializeAppData();
int initializeApp();
int renderStudentDatabase();

int main() {
    initializeAppData();
    initializeApp();
}

char seatArr[5][4][64];

int renderStudentDatabase()
{
    for(int i = 0; i < 5; i++)
    {
        printf("\n[Room #%d Seating Assignments]\n", i + 1);
        for(int d = 0; d < 4; d++)
        {
            printf("S#%d: %s\n", d+1, seatArr[i][d]);
        }
    }
    initializeApp();
    return 1;
}

int initializeAppData() {
    for(int i = 0; i < 5; i++) {
        for(int d = 0; d < 4; d++) {
            strcpy(seatArr[i][d], "Unassigned");
            // printf("seatArr[%d][%d] = %s\n", i, d, seatArr[i][d]);
            // printf("For loop #1");
        }
        // printf("For loop #2");
    }   
    // printf("Outside for loop");
    
}

int editStudentDatabase() {
    printf("\n[EDIT STUDENT DATABASE]\n");

    int seatAssignedCount[5] = {4, 4, 4, 4, 4};
    for(int i = 0; i < 5; i++)
    {
        for(int d = 0; d < 4; d++) {
            if(strcmp("Unassigned", seatArr[i][d])) seatAssignedCount[i]--;
        }
    }
    for(int i = 0; i < 5; i++) {
        printf("%d.) Room %d [Unassigned: %d]\n", i + 1, i + 1, seatAssignedCount[i]);
    }
    printf("\nSelect Room to edit assigned student seat:\n> ");

    int roomNumber = 0;
    scanf("%d", &roomNumber);

    if(roomNumber < 1 || roomNumber > 5) {
        editStudentDatabase();
        printf("\n[ERROR]: Invalid room number. Please try again.");
    }

    printf("\n[Room #%d Seating Assignments]\n", roomNumber);
    for(int d = 0; d < 4; d++)
    {
        printf("S#%d: %s\n", d+1, seatArr[roomNumber - 1][d]);
    }
    printf("\n[APP]: You have selected room number (#%d). Select seat number:\n> ", roomNumber);

    int seatNumber = 0;
    scanf("%d", &seatNumber);

    if(seatNumber < 1 || seatNumber > 4) {
        editStudentDatabase();
        printf("\n[ERROR]: Invalid seat number. Please try again.");
    }

    printf("Room %d - S#%d: %s\n", roomNumber, seatNumber, seatArr[roomNumber - 1][seatNumber - 1]);
    printf("\nSet name of student to assign in seat (64 char max):\n> ");

    char studentName[64];
    scanf("%s", &studentName);
    strcpy(seatArr[roomNumber - 1][seatNumber - 1], studentName);
    initializeApp();
}

int initializeApp() {
    printf("\n\n[Student Seat Database]\n");
    printf("Choose an action:\n\n");
    printf("[1]: View student database\n");
    printf("[2]: Edit student database\n");
    printf("\n> ");


    int inputFunction = 0;
    scanf("%d", &inputFunction);
        
    if(inputFunction == 1) {
        printf("[APP]: Attempting to renderStudentDatabase()...\n");
        renderStudentDatabase();
    }
    else if(inputFunction == 2) {
        printf("[APP]: Attempting to initialize editStudentDatabase()...\n");
        editStudentDatabase();
    }
    else {
        printf("Invalid choice.\n");
        initializeApp();
        return 0;
    }
}
