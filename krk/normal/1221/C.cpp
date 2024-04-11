#include <bits/stdc++.h>
using namespace std;

int q;
int c, m, x;

int main()
{
    scanf("%d", &q);
    while (q--) {
        scanf("%d %d %d", &c, &m, &x);
        int res = 0;
        int lef = 0, rig = min(c, m);
        while (lef <= rig) {
            int mid = lef + rig >> 1;
            int a = mid, b = c - mid + m - mid + x;
            if (a <= b) { res = max(res, a); lef = mid + 1; }
            else { res = max(res, b); rig = mid - 1; }
        }
        printf("%d\n", res);
    }
    return 0;
}