#include <bits/stdc++.h>
using namespace std;

int T;
int n, k;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        if (n % k == 0) printf("%d\n", n);
        else {
            int a = n / k;
            int sav = n % k;
            if (sav > k / 2) n -= (sav - k / 2);
            printf("%d\n", n);
        }
    }
    return 0;
}