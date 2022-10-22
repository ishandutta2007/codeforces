#include <bits/stdc++.h>
using namespace std;

int t;
int a, b, k;

int gcd(int x, int y) { return x? gcd(y % x, x): y; }

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &a, &b, &k);
        if (a == b) printf("OBEY\n");
        else {
            if (a > b) swap(a, b);
            int g = gcd(a, b); a /= g; b /= g;
            int mx = 1 + (b - 2) / a;
            if (mx >= k) printf("REBEL\n");
            else printf("OBEY\n");
        }
    }
    return 0;
}