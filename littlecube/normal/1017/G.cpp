/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
//#include <bits/extc++.h>
#include <bits/stdc++.h>
//#pragma pack(0)
#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
// using namespace __gnu_pbds;

int in[100005], out[100005], order[100005];
vector<int> E[100005];

pii merge(pii L, pii R)
{
    return pii(L.F + R.F, max(L.S + R.F, R.S));
}

struct segTree
{
    int size = 1;
    vector<pii> seg = vector<pii>(2);
    vector<bool> lazy = vector<bool>(2);
    void updsize(int n)
    {
        size = max(size, n);
    }
    void init()
    {
        seg = vector<pii>(4 * size + 1, pii(0, 0));
        lazy = vector<bool>(4 * size + 1, 0);
    }
    pii getval(int i, int L, int R)
    {
        return (lazy[i] ? pii(L - R - 1, -1) : seg[i]);
    }
    void push(int i, int L, int R)
    {
        if (lazy[i])
        {
            if (L != R)
                lazy[i << 1] = lazy[i << 1 | 1] = 1;
            seg[i] = getval(i, L, R);
            lazy[i] = 0;
        }
    }
    void modify(int pos, int val, int i = 1, int L = 1, int R = -1)
    {
        if (R == -1)
            R = size;
        push(i, L, R);
        if (L == R)
            seg[i].F += val, seg[i].S += val;
        else
        {
            int mid = (L + R) / 2;
            if (pos <= mid)
                modify(pos, val, i << 1, L, mid);
            else
                modify(pos, val, i << 1 | 1, mid + 1, R);
            seg[i] = merge(getval(i << 1, L, mid), getval(i << 1 | 1, mid + 1, R));
        }
    }
    void reset(int mL, int mR, int i = 1, int L = 1, int R = -1)
    {
        if (R == -1)
            R = size;

        if (mL <= L && R <= mR)
            lazy[i] = 1;
        else if (R < mL || mR < L)
            return;
        else
        {
            int mid = (L + R) / 2;
            push(i, L, R);
            reset(mL, mR, i << 1, L, mid);
            reset(mL, mR, i << 1 | 1, mid + 1, R);
            seg[i] = merge(getval(i << 1, L, mid), getval(i << 1 | 1, mid + 1, R));
        }
    }
    pii query(int qL, int qR, int i = 1, int L = 1, int R = -1)
    {
        if (R == -1)
            R = size;
        if (qL <= L && R <= qR)
            return getval(i, L, R);
        else if (R < qL || qR < L)
            return {0, -1};
        else
        {
            int mid = (L + R) / 2;
            push(i, L, R);
            return merge(query(qL, qR, i << 1, L, mid), query(qL, qR, i << 1 | 1, mid + 1, R));
        }
    }
} hld[100005];

struct resetTree
{
    int size = 100005;
    vector<bool> seg = vector<bool>(size * 4 + 1, 0);

    void init(int n)
    {
        size = n;
    }
    void modify(int mL, int mR, int i = 1, int L = 1, int R = -1)
    {
        if (R == -1)
            R = size;

        if (mL <= L && R <= mR)
            seg[i] = 1;
        else if (R < mL || mR < L)
            return;
        else
        {
            int mid = (L + R) / 2;
            if (seg[i])
                seg[i << 1] = seg[i << 1 | 1] = 1;
            seg[i] = 0;
            modify(mL, mR, i << 1, L, mid);
            modify(mL, mR, i << 1 | 1, mid + 1, R);
        }
    }
    void check(int pos, int i = 1, int L = 1, int R = -1)
    {
        if (R == -1)
            R = size;
        // printf("checking: %d, at node %d: (%d, %d)\n", pos, i, L, R);
        if (L == R)
        {
            if (seg[i])
                hld[order[pos]].lazy[1] = 1;
            seg[i] = 0;
        }
        else
        {
            int mid = (L + R) / 2;
            if (seg[i])
                seg[i << 1] = seg[i << 1 | 1] = 1;
            seg[i] = 0;
            if (pos <= mid)
                check(pos, i << 1, L, mid);
            else
                check(pos, i << 1 | 1, mid + 1, R);
        }
    }
} reset;

int n, q, t, pre[100005], dep[100005], child[100005], head[100005], pos[100005];

void dfs(int u)
{
    in[u] = ++t;
    order[in[u]] = u;
    for (int v : E[u])
    {
        dfs(v);
        if (dep[v] + 1 > dep[u])
        {
            dep[u] = dep[v] + 1;
            child[u] = v;
        }
    }
    out[u] = t;
}

void decompose(int u, int h)
{
    head[u] = h;
    pos[u] = (u == h ? 1 : pos[pre[u]] + 1);

    for (int v : E[u])
        decompose(v, v == child[u] ? h : v);
}

pii query(int u)
{
    pii res = {0, -1};
    do
    {
        reset.check(in[head[u]]);
        res = merge(hld[head[u]].query(1, pos[u]), res);
        u = pre[head[u]];
    } while (u);
    return res;
}

signed main()
{
    // fast;
    cin >> n >> q;
    for (int i = 2; i <= n; i++)
    {
        cin >> pre[i];
        E[pre[i]].emplace_back(i);
    }

    dfs(1);
    decompose(1, 1);
    // cout << "dfs finish\n";
    reset.init(n);

    for (int i = 1; i <= n; i++)
        hld[head[i]].updsize(pos[i]);

    for (int i = 1; i <= n; i++)
        hld[i].init();

    reset.modify(1, n);

    for (int i = 1; i <= q; i++)
    {
        int type, node;
        cin >> type >> node;
        if (type == 1)
        {
            reset.check(in[head[node]]);
            hld[head[node]].modify(pos[node], 1);
        }
        else if (type == 2)
        {
            reset.modify(in[node], out[node]);
            reset.check(in[head[node]]);
            hld[head[node]].reset(pos[node], n);
            if (node != 1)
            {
                pii parent = query(pre[node]);
                if (parent.S > 0)
                    hld[head[node]].modify(pos[node], -parent.S);
            }
        }
        else if (type == 3)
             cout << (query(node).S >= 0 ? "black\n" : "white\n");
    }
}