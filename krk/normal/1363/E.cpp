#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n;
int a[Maxn], b[Maxn], c[Maxn];
vector <int> neigh[Maxn];
ll res;

int Traverse(int v, int p, int best)
{
    a[v] = min(a[v], best);
    int cur = 0;
    if (b[v] == 0 && c[v] == 1) cur++;
    else if (b[v] == 1 && c[v] == 0) cur--;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        int nw = Traverse(u, v, a[v]);
        if (nw > 0 && cur < 0) {
            int tk = min(nw, -cur);
            nw -= tk; cur += tk;
            res += ll(tk) * a[v] * 2ll;
        } else if (nw < 0 && cur > 0) {
            int tk = min(-nw, cur);
            nw += tk; cur -= tk;
            res += ll(tk) * a[v] * 2ll;
        }
        cur += nw;
    }
    return cur;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d %d %d", &a[i], &b[i], &c[i]);
    for (int i = 0; i < n - 1; i++) {
        int u, v; scanf("%d %d", &u, &v);
        neigh[u].push_back(v);
        neigh[v].push_back(u);
    }
    int st = Traverse(1, 0, a[1]);
    if (st != 0) printf("-1\n");
    else printf("%I64d\n", res);
    return 0;
}