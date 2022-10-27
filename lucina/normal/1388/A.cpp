#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;

int main () {
    int T;

    for (scanf("%d", &T) ; T -- ; ) {
        int n;
        scanf("%d", &n);
        if (n <= 30) {
            puts("NO");
            continue;
        }

        int res = n - 30;
        puts("YES");
        if (res == 6 || res == 10 || res == 14) {
            printf("%d %d %d %d\n", res - 1, 6, 10, 15);
        } else printf("6 10 14 %d\n", res);

    }
}
/*
    Very hard game. :(
*/