#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 300005;
const int Maxm = 8;

int n, m;
int B[Maxn][Maxm];
int mask[Maxn];
int was[1 << Maxm];

ii Get(int x)
{
    fill(was, was + (1 << m), 0);
    for (int i = 1; i <= n; i++) {
        mask[i] = 0;
        for (int j = 0; j < m; j++)
            if (B[i][j] >= x) mask[i] |= 1 << j;
        was[mask[i]] = i;
    }
    for (int j = 0; j < m; j++)
        for (int i = 0; i < 1 << m; i++) if (i & 1 << j)
            if (was[i]) was[i ^ (1 << j)] = was[i];
    int all = (1 << m) - 1;
    for (int i = 1; i <= n; i++)
        if (was[mask[i] ^ all])
            return ii(i, was[mask[i] ^ all]);
    return ii(0, 0);
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &B[i][j]);
    int lef = 1, rig = 1000000007;
    while (lef <= rig) {
        int mid = lef + rig >> 1;
        ii got = Get(mid);
        if (got.first != 0) lef = mid + 1;
        else rig = mid - 1;
    }
    ii got = Get(lef - 1);
    printf("%d %d\n", got.first, got.second);
    return 0;
}