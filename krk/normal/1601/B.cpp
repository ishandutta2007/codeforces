#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;
const int Maxm = 2097152;
const int Inf = 1000000000;

int n;
int a[Maxn];
vector <int> my[Maxn];
vector <int> st[Maxm];
int dist[Maxn], par[Maxn], res[Maxn];
queue <int> Q;

void Insert(int v, int l, int r, int a, int b, int ind)
{
    if (l == a && r == b) st[v].push_back(ind);
    else {
        int m = l + r >> 1;
        if (a <= m) Insert(2 * v, l, m, a, min(m, b), ind);
        if (m + 1 <= b) Insert(2 * v + 1, m + 1, r, max(m + 1, a), b, ind);
    }
}

void Check(int v, int l, int r, int x, int cpar, int cres)
{
    while (!st[v].empty()) {
        int u = st[v].back(); st[v].pop_back();
        if (dist[cpar] + 1 < dist[u]) {
            dist[u] = dist[cpar] + 1;
            par[u] = cpar;
            res[u] = cres;
            Q.push(u);
        }
    }
    if (l < r) {
        int m = l + r >> 1;
        if (x <= m) Check(2 * v, l, m, x, cpar, cres);
        else Check(2 * v + 1, m + 1, r, x, cpar, cres);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        Insert(1, 0, n, i - a[i], i, i);
    }
    my[0].push_back(0);
    for (int i = 1; i <= n; i++) {
        int b; scanf("%d", &b);
        my[i + b].push_back(i);
    }
    fill(dist, dist + n + 1, Inf); dist[0] = 0;
    Q.push(0);
    while (!Q.empty()) {
        int v = Q.front(); Q.pop();
        for (int i = 0; i < my[v].size(); i++)
            Check(1, 0, n, my[v][i], v, my[v][i]);
    }
    if (dist[n] >= Inf) {
        printf("-1\n");
        return 0;
    }
    int rep = dist[n];
    printf("%d\n", rep);
    int v = n;
    for (int i = 0; i < rep; i++) {
        printf("%d%c", res[v], i + 1 < rep? ' ': '\n');
        v = par[v];
    }
    return 0;
}