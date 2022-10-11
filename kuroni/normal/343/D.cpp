#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 5E5 + 5;

struct TNode
{
    int v[2];
} tree[4 * N];
vector<int> adj[N];
int n, u, v, q, p[N], in[N], out[N], cur = 0, t, x;

void upd(int l, int r, int i, int L, int R, int v, int t)
{
    if (l > R || r < L)
        return;
    if (L <= l && r <= R)
        return void(tree[i].v[t] = v);
    if (t)
        tree[i].v[t] = v;
    int m = (l + r) >> 1;
    upd(l, m, i << 1, L, R, v, t);
    upd(m + 1, r, (i << 1) + 1, L, R, v, t);
}

int que(int l, int r, int i, int L, int R, int t)
{
    if (l > R || r < L)
        return 0;
    if (L <= l && r <= R)
        return tree[i].v[t];
    int m = (l + r) >> 1;
    return max(tree[i].v[t] * (1 - t), max(que(l, m, i << 1, L, R, t), que(m + 1, r, (i << 1) + 1, L, R, t)));
}

void DFS(int u, int p)
{
    in[u] = ++cur;
    for (int v : adj[u])
        if (v != p)
            DFS(v, u);
    out[u] = cur;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1, 0);
    scanf("%d", &q);
    for (int i = 1; i <= q; i++)
    {
        scanf("%d%d", &t, &x);
        if (t == 1)
            upd(1, n, 1, in[x], out[x], i, 0);
        else if (t == 2)
            upd(1, n, 1, in[x], in[x], i, 1);
        else
        {
            int ad = que(1, n, 1, in[x], in[x], 0), re = que(1, n, 1, in[x], out[x], 1);
            printf("%d\n", ad > re);
        }
    }
    return 0;
}