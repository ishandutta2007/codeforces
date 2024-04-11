#include <bits/stdc++.h>
using namespace std;

int T;
int a, b, c, m;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d %d", &a, &b, &c, &m);
        int mx = a - 1 + b - 1 + c - 1;
        int mn = 0;
        if (a > b) swap(a, b);
        if (b > c) swap(b, c);
        if (a > b) swap(a, b);
        if (c > a + b + 1)
            mn = c - a - b - 1;
        printf("%s\n", mn <= m && m <= mx? "YES": "NO");
    }
    return 0;
}