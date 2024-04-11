#include <bits/stdc++.h>

using namespace std;

int x;
char buf[256];

int main() {
    
    scanf("%d of %s", &x, buf);
    
    if (strcmp(buf, "month") == 0) {
        if (x <= 29) {
            printf("12\n");
            return 0;
        } else if(x == 30) {
            printf("11\n");
            return 0;
        } else {
            printf("7\n");
            return 0;
        }
    } else {
        if (x >= 5 && x <= 6) {
            printf("53\n");
        } else {
            printf("52\n");
        }
    }
    
    return 0;
}