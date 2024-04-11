#include <bits/stdc++.h>
using namespace std;

int n, m;

int main()
{
    scanf("%d %d", &n, &m);
    int l = 1, r = n;
    while (l < r) {
        for (int i = 1; i <= m; i++) {
            printf("%d %d\n", l, i);
            printf("%d %d\n", r, m - i + 1);
        }
        l++, r--;
    }
    if (l == r) {
        int l2 = 1, r2 = m;
        while (l2 < r2) {
            printf("%d %d\n", l, l2);
            printf("%d %d\n", l, r2);
            l2++, r2--;
        }
        if (l2 == r2) printf("%d %d\n", l, l2);
    }
    return 0;
}