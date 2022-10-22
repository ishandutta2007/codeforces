#include <bits/stdc++.h>
using namespace std;

int T;
int n, x, m;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &n, &x, &m);
        int l = x, r = x;
        for (int i = 0; i < m; i++) {
            int a, b; scanf("%d %d", &a, &b);
            if (max(a, l) <= min(b, r)) {
                l = min(l, a);
                r = max(r, b);
            }
        }
        printf("%d\n", r - l + 1);
    }
    return 0;
}