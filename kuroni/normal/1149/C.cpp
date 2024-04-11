#include <iostream>
#include <cstdio>
using namespace std;

const int N = 200005;

int n, q, u, v;
char s[N];

struct TNode
{
    int dep, mi, ma;
    int ab, bc, abc;

    TNode(int _dep = 0)
    {
        dep = mi = ma = _dep;
        ab = bc = -dep;
        abc = 0;
    }

    TNode operator+(TNode oth) const
    {
        oth.dep += dep; oth.mi += dep; oth.ma += dep;
        oth.ab -= dep; oth.bc -= dep;
        TNode ans(oth.dep);
        ans.mi = min(mi, oth.mi); ans.ma = max(ma, oth.ma);
        ans.ab = max(ma - 2 * oth.mi, max(ab, oth.ab));
        ans.bc = max(-2 * mi + oth.ma, max(bc, oth.bc));
        ans.abc = max(max(ma + oth.bc, ab + oth.ma), max(abc, oth.abc));
        return ans;
    }
};

struct TTree
{
#define m (l + r) / 2
#define lc i * 2
#define rc i * 2 + 1

    TNode tr[4 * N];

    void build(int l, int r, int i)
    {
        if (l == r)
        {
            tr[i] = TNode(s[l] == '(' ? 1 : -1);
            return;
        }
        build(l, m, lc);
        build(m + 1, r, rc);
        tr[i] = tr[lc] + tr[rc];
    }

    void upd(int l, int r, int i, int u)
    {
        if (l == r)
        {
            tr[i] = TNode(s[l] == '(' ? 1 : -1);
            return;
        }
        if (u <= m)
            upd(l, m, lc, u);
        else
            upd(m + 1, r, rc, u);
        tr[i] = tr[lc] + tr[rc];
    }

#undef m
#undef lc
#undef rc
} seg;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q >> (s + 1);
    n = 2 * n - 2;
    seg.build(1, n, 1);
    cout << seg.tr[1].abc << '\n';
    while (q--)
    {
        cin >> u >> v;
        swap(s[u], s[v]);
        seg.upd(1, n, 1, u);
        seg.upd(1, n, 1, v);
        cout << seg.tr[1].abc << '\n';
    }
}