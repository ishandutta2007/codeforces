#include <cstdio>
#include <set>
using namespace std;

const int N = 200005, LOG = 19;

int n, q, u, v, cur = 0, cnt = 0, in[N], out[N], h[N] = {-1}, par[N][LOG];
set<int> adj[N];

struct SNode
{
    int mx, cnt, lz;

    inline SNode operator+(const SNode &b)
    {
        if (mx > b.mx)
            return (SNode){mx, cnt, 0};
        else if (mx < b.mx)
            return (SNode){b.mx, b.cnt, 0};
        else
            return (SNode){mx, cnt + b.cnt, 0};
    }
};

class CTree
{
#define lc i * 2
#define rc i * 2 + 1
#define m (l + r) / 2

private:
    SNode tr[4 * N];

    void down(int i)
    {
        tr[lc].mx += tr[i].lz;
        tr[rc].mx += tr[i].lz;
        tr[lc].lz += tr[i].lz;
        tr[rc].lz += tr[i].lz;
        tr[i].lz = 0;
    }

public:
    void build(int l, int r, int i)
    {
        if (l == r)
        {
            tr[i] = (SNode){0, 1, 0};
            return;
        }
        build(l, m, lc);
        build(m + 1, r, rc);
        tr[i] = tr[lc] + tr[rc];
    }

    void upd(int l, int r, int i, int L, int R, int v)
    {
        if (l > R || r < L)
            return;
        if (L <= l && r <= R)
        {
            tr[i].lz += v;
            tr[i].mx += v;
            return;
        }
        down(i);
        upd(l, m, lc, L, R, v);
        upd(m + 1, r, rc, L, R, v);
        tr[i] = tr[lc] + tr[rc];
    }

    SNode que() { return tr[1]; }

#undef lc
#undef rc
#undef m
} seg;

void DFS(int u, int p = 0)
{
    in[u] = ++cnt;
    h[u] = h[p] + 1;
    par[u][0] = p;
    for (int i = 1; (1 << i) <= h[u]; i++)
        par[u][i] = par[par[u][i - 1]][i - 1];
    for (const int &v : adj[u])
        if (v != p)
            DFS(v, u);
    out[u] = cnt;
}

int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d", &u, &v);
        adj[u].insert(v);
        adj[v].insert(u);
    }
    DFS(1);
    seg.build(1, n, 1);
    while (q--)
    {
        scanf("%d%d", &u, &v);
        if (in[u] > in[v])
            swap(u, v);
        int val;
        if (adj[u].find(v) == adj[u].end())
        {
            val = 1;
            adj[u].insert(v);
            adj[v].insert(u);
        }
        else
        {
            val = -1;
            adj[u].erase(v);
            adj[v].erase(u);
        }
        cur += val;
        if (out[u] < out[v])
        {
            seg.upd(1, n, 1, in[u], out[u], val);
            seg.upd(1, n, 1, in[v], out[v], val);
        }
        else
        {
            seg.upd(1, n, 1, in[v], out[v], val);
            seg.upd(1, n, 1, 1, n, val);
            for (int i = 31 - __builtin_clz(h[v]); i >= 0; i--)
                if (h[par[v][i]] > h[u])
                    v = par[v][i];
            seg.upd(1, n, 1, in[v], out[v], -val);
        }
        printf("%d\n", seg.que().mx == cur ? seg.que().cnt : 0);
    }
}