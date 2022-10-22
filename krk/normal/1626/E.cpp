#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;

int n;
int c[Maxn];
vector <int> neigh[Maxn];
int cnt[Maxn];
vector <int> reach[Maxn];
int tk[Maxn];

void Traverse(int v, int p)
{
    cnt[v] = c[v];
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Traverse(u, v);
        if (cnt[u] >= 2) reach[u].push_back(v);
        cnt[v] += cnt[u];
    }
}

void Traverse2(int v, int p, int tp)
{
    if (tp >= 2) reach[p].push_back(v);
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Traverse2(u, v, tp + cnt[v] - cnt[u]);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &c[i]);
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    Traverse(1, 0);
    Traverse2(1, 0, 0);
    vector <int> Q;
    for (int i = 1; i <= n; i++) if (c[i] == 1) {
        tk[i] = 1; Q.push_back(i);
        for (int j = 0; j < neigh[i].size(); j++) {
            int u = neigh[i][j];
            if (!tk[u]) {
                tk[u] = 1; Q.push_back(u);
            }
        }
    }
    for (int i = 0; i < Q.size(); i++) {
        int v = Q[i];
        for (int j = 0; j < reach[v].size(); j++) {
            int u = reach[v][j];
            if (!tk[u]) {
                tk[u] = 1; Q.push_back(u);
            }
        }
    }
    for (int i = 1; i <= n; i++)
        printf("%d%c", tk[i], i + 1 <= n? ' ': '\n');
    return 0;
}