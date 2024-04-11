#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 100005;

int n, L, W;
vector <ii> neigh[Maxn];
bool er[Maxn];
int siz[Maxn];
int N;
vector <int> BIT[Maxn];
vector <int> unBIT[Maxn];
ll res;

void Count(int v, int p)
{
    siz[v] = 1;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i].first;
        if (u == p || er[u]) continue;
        Count(u, v);
        siz[v] += siz[u];
    }
}

int getCentroid(int v, int p, int sz)
{
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i].first;
        if (u == p || er[u]) continue;
        if (siz[u] > sz / 2) return getCentroid(u, v, sz);
    }
    return v;
}

void Create(int ind, int w)
{
    ind++;
    for (int i = ind; i <= N; i += i & -i)
        unBIT[i].push_back(w);
}

void Add(int l, int w)
{
    for (int i = l + 1; i <= N; i += i & -i) {
        int ind = lower_bound(unBIT[i].begin(), unBIT[i].end(), w) - unBIT[i].begin();
        for (int j = ind + 1; j < BIT[i].size(); j += j & -j)
            BIT[i][j]++;
    }
}

int Get(int l, int w)
{
    if (l > L || w > W) return 0;
    l = min(N, L - l + 1);
    w = W - w;
    int res = 0;
    for (int i = l; i > 0; i -= i & -i) {
        int ind = upper_bound(unBIT[i].begin(), unBIT[i].end(), w) - unBIT[i].begin() - 1;
        for (int j = ind + 1; j > 0; j -= j & -j)
            res += BIT[i][j];
    }
    return res;
}

void createAll(int v, int p, int l, int w)
{
    Create(l, w);
    for (int i = 0; i < neigh[v].size(); i++) {
        ii u = neigh[v][i];
        if (u.first == p || er[u.first]) continue;
        createAll(u.first, v, l + 1, w + u.second);
    }
}

void addAll(int v, int p, int l, int w)
{
    Add(l, w);
    for (int i = 0; i < neigh[v].size(); i++) {
        ii u = neigh[v][i];
        if (u.first == p || er[u.first]) continue;
        addAll(u.first, v, l + 1, w + u.second);
    }
}

ll getAll(int v, int p, int l, int w)
{
    ll res = Get(l, w);
    for (int i = 0; i < neigh[v].size(); i++) {
        ii u = neigh[v][i];
        if (u.first == p || er[u.first]) continue;
        res += getAll(u.first, v, l + 1, w + u.second);
    }
    return res;
}

void Solve(int v)
{
    Count(v, 0);
    int C = getCentroid(v, 0, siz[v]);
    N = siz[v];
    for (int i = 0; i <= N; i++) {
        unBIT[i].clear();
        BIT[i].clear();
    }
    createAll(C, 0, 0, 0);
    for (int i = 0; i <= N; i++) {
        sort(unBIT[i].begin(), unBIT[i].end());
        unBIT[i].erase(unique(unBIT[i].begin(), unBIT[i].end()), unBIT[i].end());
        BIT[i].resize(unBIT[i].size() + 1, 0);
    }
    Add(0, 0);
    for (int i = 0; i < neigh[C].size(); i++) {
        ii u = neigh[C][i];
        if (er[u.first]) continue;
        res += getAll(u.first, C, 1, u.second);
        addAll(u.first, C, 1, u.second);
    }
    er[C] = true;
    for (int i = 0; i < neigh[C].size(); i++) {
        ii u = neigh[C][i];
        if (er[u.first]) continue;
        Solve(u.first);
    }
}

int main()
{
    scanf("%d %d %d", &n, &L, &W);
    for (int i = 2; i <= n; i++) {
        int p, w; scanf("%d %d", &p, &w);
        neigh[p].push_back(ii(i, w));
        neigh[i].push_back(ii(p, w));
    }
    Solve(1);
    printf("%I64d\n", res);
    return 0;
}