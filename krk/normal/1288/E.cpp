#include <bits/stdc++.h>
using namespace std;

const int Maxn = 600006;

int n, m;
int lef[Maxn], rig[Maxn], pos[Maxn];
int BIT[Maxn];

void Update(int x, int val)
{
    for (int i = x; i > 0; i -= i & -i)
        BIT[i] += val;
}

int Get(int x)
{
    int res = 0;
    for (int i = x; i < Maxn; i += i & -i)
        res += BIT[i];
    return res;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        lef[i] = rig[i] = i;
        pos[i] = n + 1 - i;
        Update(pos[i], 1);
    }
    for (int i = n + 1; i <= n + m; i++) {
        int x; scanf("%d", &x);
        lef[x] = min(lef[x], 1);
        rig[x] = max(rig[x], Get(pos[x]));
        Update(pos[x], -1);
        pos[x] = i;
        Update(pos[x], 1);
    }
    for (int i = 1; i <= n; i++) {
        rig[i] = max(rig[i], Get(pos[i]));
        printf("%d %d\n", lef[i], rig[i]);
    }
    return 0;
}