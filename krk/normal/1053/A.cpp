#include <bits/stdc++.h>
using namespace std;

int n, m, k;

int gcd(int x, int y) { return x? gcd(y % x, x): y; }

int main()
{
    cin >> n >> m >> k;
    int nn = n, mm = m;
    int a = gcd(nn, k); nn /= a; k /= a;
    int b = gcd(mm, k); mm /= b; k /= b;
    if (k > 2) { printf("NO\n"); return 0; }
    printf("YES\n");
    if (k == 2) {
        printf("0 0\n");
        printf("%d 0\n", nn);
        printf("0 %d\n", mm);
        return 0;
    }
    if (nn < n) {
        printf("0 0\n");
        printf("%d 0\n", 2 * nn);
        printf("0 %d\n", mm);
    } else {
        printf("0 0\n");
        printf("0 %d\n", 2 * mm);
        printf("%d 0\n", nn);
    }
    return 0;
}