#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int n;
vector <int> neigh[Maxn];
int dist[Maxn];
queue <int> Q;
bool er[Maxn];
int cnt[Maxn], L[Maxn];
int res[Maxn];
map <int, int> M;

void Add(int key, int val)
{
    auto it = M.lower_bound(key);
    if (it != M.end()) {
        if (it->second >= val) return;
        if (it->first == key) it++;
    }
    while (it != M.begin()) {
        it--;
        if (val >= it->second) M.erase(it++);
        else break;
    }
    M.insert(make_pair(key, val));
}

int Get(int key)
{
    auto it = M.upper_bound(key);
    return it == M.end()? 0: it->second;
}

void Count(int v, int p = 0)
{
    cnt[v] = 1;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p || er[u]) continue;
        Count(u, v);
        cnt[v] += cnt[u];
    }
}

int getCentroid(int v, int p, int lim)
{
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p || er[u]) continue;
        if (cnt[u] > lim) return getCentroid(u, v, lim);
    }
    return v;
}

void addAll(int v, int p = 0)
{
    Add(dist[v] - L[v], dist[v]);
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p || er[u]) continue;
        L[u] = L[v] + 1;
        addAll(u, v);
    }
}

void checkAll(int v, int p = 0)
{
    res[v] = max(res[v], Get(L[v]));
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p || er[u]) continue;
        checkAll(u, v);
    }
}

void Solve(int v)
{
    Count(v);
    int C = getCentroid(v, 0, cnt[v] / 2);
    M.clear();
    L[C] = 0;
    addAll(C);
    checkAll(C);
    er[C] = true;
    for (int i = 0; i < neigh[C].size(); i++) {
        int u = neigh[C][i];
        if (er[u]) continue;
        Solve(u);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    fill(dist + 1, dist + n + 1, Maxn);
    int k; scanf("%d", &k);
    while (k--) {
        int v; scanf("%d", &v);
        dist[v] = 0;
        Q.push(v);
    }
    while (!Q.empty()) {
        int v = Q.front(); Q.pop();
        for (int i = 0; i < neigh[v].size(); i++) {
            int u = neigh[v][i];
            if (dist[v] + 1 < dist[u]) {
                dist[u] = dist[v] + 1;
                Q.push(u);
            }
        }
    }
    Solve(1);
    for (int i = 1; i <= n; i++)
        printf("%d%c", res[i], i + 1 <= n? ' ': '\n');
    return 0;
}