#include <bits/stdc++.h>
using namespace std;

const int Maxn = 42;

int T;
int n;
int a[Maxn];

int gcd(int x, int y) { return x? gcd(y % x, x): y; }

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a, a + n);
        int g = 0;
        for (int i = 1; i < n; i++)
            g = gcd(g, a[i] - a[i - 1]);
        printf("%d\n", g == 0? -1: g);
    }
    return 0;
}