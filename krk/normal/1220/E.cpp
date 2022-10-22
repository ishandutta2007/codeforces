#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n, m;
int w[Maxn];
vector <int> neigh[Maxn];
int s;
int cur, tim[Maxn], low[Maxn];
ll add[Maxn];
ll res;

bool Traverse(int v, int p)
{
    cur++; tim[v] = low[v] = cur;
    bool success = false;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        if (!tim[u]) {
            bool win = Traverse(u, v);
            low[v] = min(low[v], low[u]);
            success |= win;
            add[v] = max(add[v], add[u]);
        } else low[v] = min(low[v], tim[u]);
    }
    success |= low[v] < tim[v];
    if (success) res += w[v];
    else add[v] += w[v];
    return success;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    scanf("%d", &s);
    Traverse(s, 0);
    res += add[s];
    cout << res << endl;
    return 0;
}