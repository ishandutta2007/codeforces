#include <bits/stdc++.h>
using namespace std;

int T;
int x, y, n;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &x, &y, &n);
        int cur = n % x;
        if (cur != y) n -= (cur - y + x) % x;
        printf("%d\n", n);
    }
    return 0;
}