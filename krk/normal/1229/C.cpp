#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n, m;
vector <int> upd[Maxn];
int lef[Maxn], rig[Maxn];
ll cur;
int q;

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        if (a > b) swap(a, b);
        upd[a].push_back(b);
        lef[b]++; rig[a]++;
    }
    for (int i = 1; i <= n; i++)
        cur += ll(lef[i]) * rig[i];
    printf("%I64d\n", cur);
    int q; scanf("%d", &q);
    while (q--) {
        int v; scanf("%d", &v);
        cur -= ll(lef[v]) * rig[v];
        lef[v] += int(upd[v].size());
        rig[v] -= int(upd[v].size());
        for (int i = 0; i < upd[v].size(); i++) {
            int u = upd[v][i];
            upd[u].push_back(v);
            cur -= ll(lef[u]) * rig[u];
            lef[u]--; rig[u]++;
            cur += ll(lef[u]) * rig[u];
        }
        upd[v].clear();
        printf("%I64d\n", cur);
    }
    return 0;
}