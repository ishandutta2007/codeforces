#include <iostream>
#include <vector>
using namespace std;

struct TNode
{
    int s = 0;
    bool l = 0;
} tree[800005];
vector<int> adj[200005];
string s;
int n, m, i, u, in[200005], out[200005], cnt = 0;

void DFS(int u)
{
    in[u] = ++cnt;
    for (int v: adj[u])
        DFS(v);
    out[u] = cnt;
}

void down(int l, int r, int i, int m)
{
    if (tree[i].l)
    {
        tree[2 * i].l ^= 1;
        tree[2 * i].s = m - l + 1 - tree[2 * i].s;
        tree[2 * i + 1].l ^= 1;
        tree[2 * i + 1].s = r - m - tree[2 * i + 1].s;
    }
    tree[i].l = 0;
}

void upd(int l, int r, int i, int L, int R)
{
    if (l > R || r < L)
        return;
    else if (L <= l && r <= R)
    {
        tree[i].s = r - l + 1 - tree[i].s;
        tree[i].l ^= 1;
    }
    else
    {
        int m = (l + r) / 2;
        down(l, r, i, m);
        upd(l, m, 2 * i, L, R); upd(m + 1, r, 2 * i + 1, L, R);
        tree[i].s = tree[2 * i].s + tree[2 * i + 1].s;
    }
}

int que(int l, int r, int i, int L, int R)
{
    if (l > R || r < L)
        return 0;
    else if (L <= l && r <= R)
        return tree[i].s;
    else
    {
        int m = (l + r) / 2;
        down(l, r, i, m);
        return que(l, m, 2 * i, L, R) + que(m + 1, r, 2 * i + 1, L, R);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for (i = 2; i <= n; i++)
    {
        cin >> u;
        adj[u].push_back(i);
    }
    DFS(1);
    for (i = 1; i <= n; i++)
    {
        cin >> u;
        if (u)
            upd(1, n, 1, in[i], in[i]);
    }
    cin >> m;
    while (m--)
    {
        cin >> s >> u;
        if (s == "pow")
            upd(1, n, 1, in[u], out[u]);
        else cout << que(1, n, 1, in[u], out[u]) << '\n';
    }
}