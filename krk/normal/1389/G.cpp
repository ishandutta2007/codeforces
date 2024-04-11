#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 300005;

int n, m, k;
int root;
bool spec[Maxn];
ll c[Maxn];
int w[Maxn];
vector <ii> neigh[Maxn];
set <ii> tneigh[Maxn];
int in[Maxn];
bool valid[Maxn];
int speccnt[Maxn];
ll best[Maxn];
ll res[Maxn];

void Count(int v, int p)
{
    speccnt[v] = spec[v];
    for (auto u: tneigh[v]) {
        if (u.first == p) continue;
        Count(u.first, v);
        speccnt[v] += speccnt[u.first];
    }
}

ll Cost(const ii &u)
{
    if (speccnt[u.first] == 0 || speccnt[u.first] == speccnt[root]) return 0;
    return w[u.second];
}

void Traverse(int v, int p)
{
    best[v] = c[v];
    for (auto u: tneigh[v]) {
        if (u.first == p) continue;
        Traverse(u.first, v);
        best[v] += max(0ll, best[u.first] - Cost(u));
    }
}

void Solve(int v, int p, ll tp)
{
    res[v] = best[v] + tp;
    for (auto u: tneigh[v]) {
        if (u.first == p) continue;
        ll my = res[v] - max(0ll, best[u.first] - Cost(u));
        Solve(u.first, v, max(0ll, my - Cost(u)));
    }
}

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    while (k--) {
        int v; scanf("%d", &v);
        spec[v] = true;
    }
    for (int i = 1; i <= n; i++)
        scanf("%I64d", &c[i]);
    for (int i = 0; i < m; i++)
        scanf("%d", &w[i]);
    for (int i = 0; i < m; i++) {
        int x, y; scanf("%d %d", &x, &y);
        neigh[x].push_back(ii(y, i));
        neigh[y].push_back(ii(x, i));
        in[x]++;
        in[y]++;
    }
    vector <int> Q;
    for (int i = 1; i <= n; i++)
        if (in[i] == 1) Q.push_back(i);
    for (int i = 0; i < Q.size(); i++) {
        int v = Q[i]; valid[v] = true;
        for (int j = 0; j < neigh[v].size(); j++) {
            int u = neigh[v][j].first;
            if (--in[u] == 1) Q.push_back(u);
        }
    }
    root = n + 1;
    if (Q.size() == n) valid[Q.back()] = false;
    for (int i = 1; i <= n; i++) {
        if (!valid[i]) {
            spec[root] |= spec[i];
            c[root] += c[i];
        }
        for (int j = 0; j < neigh[i].size(); j++) {
            ii u = neigh[i][j];
            int a = valid[i]? i: root;
            int b = valid[u.first]? u.first: root;
            if (a != b)
                tneigh[a].insert(ii(b, u.second));
        }
    }
    Count(root, 0);
    Traverse(root, 0);
    Solve(root, 0, 0);
    for (int i = 1; i <= n; i++) {
        ll ans = valid[i]? res[i]: res[root];
        printf("%I64d%c", ans, i + 1 <= n? ' ': '\n');
    }
    return 0;
}