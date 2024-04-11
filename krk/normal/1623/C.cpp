#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n;
int h[Maxn];
int nd[Maxn];

bool Solve(int x)
{
    fill(nd, nd + n + 1, x);
    for (int i = n; i >= 3; i--) {
        if (h[i] < nd[i]) return false;
        int g = (h[i] - nd[i]) / 3;
        nd[i - 1] = max(0, nd[i - 1] - g);
        nd[i - 2] = max(0, nd[i - 2] - 2 * g);
    }
    return h[1] >= nd[1] && h[2] >= nd[2];
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &h[i]);
        int lef = 0, rig = 1000000007;
        while (lef <= rig) {
            int mid = lef + rig >> 1;
            if (Solve(mid)) lef = mid + 1;
            else rig = mid - 1;
        }
        printf("%d\n", rig);
    }
    return 0;
}