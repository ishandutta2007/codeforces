#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int T;
int n;
int a[Maxn];
int b[Maxn];

int gcd(int x, int y) { return x? gcd(y % x, x): y; }

int lcm(int x, int y) { return x / gcd(x, y) * y; }

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for (int i = 0; i <= n; i++)
            if (i == 0) b[i] = a[i];
            else if (i == n) b[i] = a[i - 1];
            else b[i] = lcm(a[i], a[i - 1]);
        bool ok = true;
        for (int i = 0; i < n; i++)
            if (gcd(b[i], b[i + 1]) != a[i])
                ok = false;
        printf("%s\n", ok? "YES": "NO");
    }
    return 0;
}