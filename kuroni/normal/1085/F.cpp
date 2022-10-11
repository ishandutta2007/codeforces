#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, q, u;
char c, s[N];

struct STree
{
#define m (l + r) / 2
#define lc i * 2
#define rc i * 2 + 1

    int tr[4 * N];

    void update(int l, int r, int i, int u, int v)
    {
        tr[i] += v;
        if (l == r)
            return;
        if (u <= m)
            update(l, m, lc, u, v);
        else
            update(m + 1, r, rc, u, v);
    }

    int query(int l, int r, int i, int L, int R)
    {
        if (l > R || r < L || L > R)
            return 0;
        if (L <= l && r <= R)
            return tr[i];
        return query(l, m, lc, L, R) + query(m + 1, r, rc, L, R);
    }

    int fpos(int l, int r, int i, bool fi = true)
    {
        if (l == r)
            return l;
        if (fi)
            return (tr[lc] >= 1 ? fpos(l, m, lc, fi) : fpos(m + 1, r, rc, fi));
        else
            return (tr[rc] >= 1 ? fpos(m + 1, r, rc, fi) : fpos(l, m, lc, fi));
    }

    int lpos(int l, int r, int i, bool fi = true)
    {
        if (l == r)
            return fi ? l - 1 : n - l;
        if (fi)
            return (tr[lc] == m - l + 1 ? lpos(m + 1, r, rc, fi) : lpos(l, m, lc, fi));
        else
            return (tr[rc] == r - m ? lpos(l, m, lc, fi) : lpos(m + 1, r, rc, fi));
    }

#undef m
#undef lc
#undef rc
} seg[3];

int conv(char c)
{
    if (c == 'R')
        return 0;
    else if (c == 'S')
        return 1;
    else
        return 2;    
}

int query(int typ)
{
    int nxt = (typ + 1) % 3;
    int l = seg[nxt].fpos(1, n, 1, true), r = seg[nxt].fpos(1, n, 1, false);
    if (l > r)
        return (seg[typ].query(1, n, 1, 1, n) == n ? n : 0);
    else
        return seg[typ].query(1, n, 1, l, r) + seg[typ].lpos(1, n, 1, true) + seg[typ].lpos(1, n, 1, false);
}

int find_ans()
{
    int ans = 0;
    for (int i = 0; i < 3; i++)
        ans += query(i);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q >> (s + 1);
    for (int i = 1; i <= n; i++)
        seg[conv(s[i])].update(1, n, 1, i, 1);
    cout << find_ans() << '\n';
    while (q--)
    {
        cin >> u >> c;
        seg[conv(s[u])].update(1, n, 1, u, -1);
        s[u] = c;
        seg[conv(s[u])].update(1, n, 1, u, 1);
        cout << find_ans() << '\n';
    }
}