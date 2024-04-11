#include<bits/stdc++.h>
using namespace std;

bool read () {
    int k;
    scanf("%d", &k);

    if (k == 1) {
        printf("done\n");
        fflush(stdout);
        exit(0);
    }

    bool x = false;

    static char s[25];

    for (int i = 0 ; i < k ; ++ i) {
        scanf("%s", s);
        if (s[0] == '0' && s[1] == '1') x = true;
    }

    return x;
}

int main () {

    while (true) {
        printf("next 0\n");
        fflush(stdout);
        read();
        printf("next 0 1\n");
        fflush(stdout);

        if (read()) break;
    }

    while (true) {
        printf("next ");
        for (int i = 0 ; i < 10 ; ++ i)
            printf("%d ", i);
        printf("\n");
        fflush(stdout);

        read();
    }
}