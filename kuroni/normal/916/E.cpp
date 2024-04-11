#include <iostream>
#include <cstdio>
#include <vector>
#define ll I64
using namespace std;

const int N = 1E5 + 5;

vector<int> adj[N], par[N];
int a[N], in[N], out[N], h[N], n, q, u, v, r = 1, pt = 0, t, x;

class TTree
{
#define m ((l + r) >> 1)
#define ch (i << 1)
  private:
    struct TNode
    {
        long long v, lz;
    } tree[4 * N];

    inline void down(int i, int l, int r)
    {
        long long lz = tree[i].lz;
        tree[ch].lz += lz;
        tree[ch].v += lz * (m - l + 1);
        tree[ch + 1].lz += lz;
        tree[ch + 1].v += lz * (r - m);
        tree[i].lz = 0;
        return;
    }

  public:
    void upd(int l, int r, int i, int L, int R, long long v)
    {
        if (l > R || r < L)
            return;
        if (L <= l && r <= R)
        {
            tree[i].lz += v;
            tree[i].v += v * (r - l + 1);
            return;
        }
        down(i, l, r);
        upd(l, m, ch, L, R, v);
        upd(m + 1, r, ch + 1, L, R, v);
        tree[i].v = tree[ch].v + tree[ch + 1].v;
    }

    long long que(int l, int r, int i, int L, int R)
    {
        if (l > R || r < L)
            return 0;
        if (L <= l && r <= R)
            return tree[i].v;
        down(i, l, r);
        return que(l, m, ch, L, R) + que(m + 1, r, ch + 1, L, R);
    }
#undef m
#undef ch
} tr;

void DFS(int u, int p)
{
    h[u] = h[p] + 1;
    in[u] = ++pt;
    tr.upd(1, n, 1, in[u], in[u], a[u]);
    if (u != 1)
    {
        par[u].push_back(p);
        for (int i = 1; (1 << i) <= h[u]; i++)
            par[u].push_back(par[par[u][i - 1]][i - 1]);
    }
    for (int v : adj[u])
        if (v != p)
            DFS(v, u);
    out[u] = pt;
    return;
}

int LCA(int u, int v)
{
    if (h[u] < h[v])
        swap(u, v);
    for (int i = 16; i >= 0; i--)
        if ((h[u] - h[v]) >> i & 1)
            u = par[u][i];
    if (u == v)
        return u;
    for (int i = 16; i >= 0; i--)
        if ((1 << i) <= h[u] && par[u][i] != par[v][i])
        {
            u = par[u][i];
            v = par[v][i];
        }
    return par[u][0];
}

int dLCA(int u, int v)
{
    int x = LCA(u, v), y = LCA(u, r), z = LCA(v, r);
    y = (h[x] > h[y] ? x : y);
    return (h[y] > h[z] ? y : z);
}

int pro_chi(int u)
{
    int p = r;
    if (h[p] <= h[u])
        return -1;
    int dist = h[p] - h[u] - 1;
    for (int i = 16; i >= 0; i--)
        if (dist >> i & 1)
            p = par[p][i];
    return (par[p][0] == u ? p : -1);
}

int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    h[0] = -1;
    DFS(1, 0);
    while (q--)
    {
        scanf("%d", &t);
        if (t == 1)
            scanf("%d", &r);
        else if (t == 2)
        {
            scanf("%d%d%d", &u, &v, &x);
            int p = dLCA(u, v);
            if (p == r)
                tr.upd(1, n, 1, 1, n, x);
            else
            {
                int ch = pro_chi(p);
                if (ch == -1)
                    tr.upd(1, n, 1, in[p], out[p], x);
                else
                {
                    tr.upd(1, n, 1, 1, n, x);
                    tr.upd(1, n, 1, in[ch], out[ch], -x);
                }
            }
        }
        else
        {
            scanf("%d", &x);
            if (x == r)
                printf("%lld\n", tr.que(1, n, 1, 1, n));
            else
            {
                int ch = pro_chi(x);
                if (ch == -1)
                    printf("%lld\n", tr.que(1, n, 1, in[x], out[x]));
                else
                    printf("%lld\n", tr.que(1, n, 1, 1, n) - tr.que(1, n, 1, in[ch], out[ch]));
            }
        }
    }
    return 0;
}