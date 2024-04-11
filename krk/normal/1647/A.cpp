#include <bits/stdc++.h>
using namespace std;

int T;
int n;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int fir = n % 3 == 0? 2: n % 3;
        while (n > 0) {
            printf("%d", fir);
            n -= fir;
            fir = 3 - fir;
        }
        printf("\n");
    }
    return 0;
}