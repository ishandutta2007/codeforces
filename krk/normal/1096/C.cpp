#include <bits/stdc++.h>
using namespace std;

int t;
int ang;

int gcd(int x, int y) { return x? gcd(y % x, x): y; }

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &ang);
        int g = gcd(ang, 180);
        int a = ang / g;
        int b = 180 / g;
        if (a + 1 == b) b *= 2;
        printf("%d\n", b);
    }
    return 0;
}