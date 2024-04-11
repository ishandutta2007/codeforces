#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
const int maxlgn = 20;

vector<list<int> > graph;

long long sum[maxn], tot[maxn], dep[maxn], siz[maxn];
int f[maxn][maxlgn];

int LCA(int a, int b) {
    if (dep[a] < dep[b]) swap(a, b);
    for (int i = maxlgn - 1; ~i; i--)
        if (dep[f[a][i]] >= dep[b])
            a = f[a][i];
    if (a == b) return a;
    for (int i = maxlgn - 1; ~i; i--)
        if (f[a][i] != f[b][i])
            a = f[a][i], b = f[b][i];
    return f[a][0];
}

int LCA_(int a, int b) {
    if (dep[a] < dep[b]) swap(a, b);
    for (int i = maxlgn - 1; ~i; i--)
        if (dep[f[a][i]] > dep[b])
            a = f[a][i];
    return a;
}

void dfs(int p, int fa) {
    f[p][0] = fa;
    for (int i = 1; i < maxlgn; i++) f[p][i] = f[f[p][i - 1]][i - 1];
    siz[p] = 1;
    sum[p] = dep[p] = dep[fa] + 1;
    for (list<int>::iterator i = graph[p].begin(); i != graph[p].end(); i++)
        if (*i != fa) {
            dfs(*i, p);
            siz[p] += siz[*i], sum[p] += sum[*i];
        }
    return;
}

void dfs2(int p, int fa) {
    if (fa) tot[p] = tot[fa] + sum[fa] - sum[p] - ((siz[fa] - siz[p]) * dep[fa] * 1LL << 1);
    for (list<int>::iterator i = graph[p].begin(); i != graph[p].end(); i++)
        if (*i != fa) dfs2(*i, p);
    return;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    graph.resize(n + 1);
    for (int i = 1, from, to; i < n; i++) {
        scanf("%d%d", &from, &to);
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    dfs(1, 0);
    dfs2(1, 0);
    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (dep[a] > dep[b]) swap(a, b);
        int lca = LCA(a, b);
        long long left, right;
        if (lca == a) {
            int son = LCA_(a, b);
            long long siz1 = siz[b], siz2 = siz[1] - siz[son];
            left = (sum[b] - dep[b] * siz1) * siz2 +
                   (tot[son] + siz2 * dep[a]) * siz1 +
                   (right = siz1 * siz2) * (dep[b] - dep[a] + 1);
        } else {
            left = siz[a] * (sum[b] - dep[b] * siz[b]) +
                   siz[b] * (sum[a] - dep[a] * siz[a]) +
                   (right = siz[a] * siz[b]) * (dep[a] + dep[b] - (dep[lca] << 1) + 1);
        }
        printf("%.8lf\n", (double)left / right);
    }
    return 0;
}