#include <bits/stdc++.h>
using namespace std;

int T;
int n, x, y;

int Get(int d, int x)
{
    int cur = n - d + 1;
    if (cur <= x) cur--;
    return cur;
}

int Better(int x, int y)
{
    int s = x + y;
    int lef = 1, rig = n - 1;
    while (lef <= rig) {
        int mid = lef + rig >> 1;
        if (Get(mid, x) + Get(1, y) > s &&
            Get(1, x) + Get(mid, y) > s)
            lef = mid + 1;
        else rig = mid - 1;
    }
    return rig;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &n, &x, &y);
        if (x > y) swap(x, y);
        int s = x + y;
        printf("%d %d\n", n - Better(x, y), min(n, s - 1));
    }
    return 0;
}