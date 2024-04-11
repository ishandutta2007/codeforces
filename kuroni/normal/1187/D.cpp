#include <bits/stdc++.h>
using namespace std;

const int N = 300005, INF = 1E9 + 7;

int n, t, u, b[N];
queue<int> q[N];

class CSegmentTree
{
#define m (l + r) / 2
#define lc i * 2
#define rc i * 2 + 1

  private:
    int tr[4 * N];

  public:
    void upd(int l, int r, int i, int u, int v)
    {
        if (l == r)
        {
            tr[i] = v;
            return;
        }
        if (u <= m)
            upd(l, m, lc, u, v);
        else
            upd(m + 1, r, rc, u, v);
        tr[i] = min(tr[lc], tr[rc]);
    }

    int que(int l, int r, int i, int L, int R)
    {
        if (l > R || r < L || L > R)
            return INF;
        if (L <= l && r <= R)
            return tr[i];
        return min(que(l, m, lc, L, R), que(m + 1, r, rc, L, R));
    }

#undef m
#undef lc
#undef rc
} seg;

bool solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        while (!q[i].empty())
            q[i].pop();
    for (int i = 1; i <= n; i++)
    {
        cin >> u;
        q[u].push(i);
        seg.upd(1, n, 1, i, u);
    }
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
    {
        u = b[i];
        if (q[u].empty())
            return false;
        int pos = q[u].front();
        q[u].pop();
        if (seg.que(1, n, 1, 1, pos) < u)
            return false;
        seg.upd(1, n, 1, pos, INF);
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--)
        cout << (solve() ? "YES\n" : "NO\n");
}