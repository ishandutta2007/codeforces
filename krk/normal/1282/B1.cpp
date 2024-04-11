#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n, p, k;
int a[Maxn];

bool Solve(int x)
{
    int res = 0;
    while (x > 0) {
        res += a[x - 1];
        x -= k;
    }
    return res <= p;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &n, &p, &k);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a, a + n);
        int lef = 1, rig = n;
        while (lef <= rig) {
            int mid = lef + rig >> 1;
            if (Solve(mid)) lef = mid + 1;
            else rig = mid - 1;
        }
        printf("%d\n", lef - 1);
    }
    return 0;
}