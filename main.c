#include <stdio.h>
#include <string.h>
#include <ctype.h>

void rot13(char* message) {
    for (int i = 0; message[i] != '\0'; i++) {
        if (isalpha(message[i])) {
            char base = isupper(message[i]) ? 'A' : 'a';
            message[i] = (message[i] - base + 13) % 26 + base;
        }
    }
}

int main() {
    char message[100];

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0';  // Remove newline

    rot13(message);
    printf("ROT13 Encoded: %s\n", message);

    rot13(message); // Apply ROT13 again to decode
    printf("Decoded (ROT13 again): %s\n", message);

    return 0;
}
