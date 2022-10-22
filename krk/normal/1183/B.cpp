#include <bits/stdc++.h>
using namespace std;

int q;
int n, k;

int main()
{
    scanf("%d", &q);
    while (q--) {
        scanf("%d %d", &n, &k);
        int mn = 1000000000, mx = -1000000000;
        for (int i = 0; i < n; i++) {
            int a; scanf("%d", &a);
            mn = min(mn, a);
            mx = max(mx, a);
        }
        if ((mx - mn + 1) / 2 > k) printf("-1\n");
        else printf("%d\n", mn + k);
    }
    return 0;
}