#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N = 200005, D = 1150;

int n, q, u, t, x, d, cnt = -1, p[N], in[N], out[N];
int a[N], b[N], add[D], ind[N][2];
vector<int> adj[N];

struct SLine
{
    int a;
    long long b;

    SLine(int _a, long long _b): a(_a), b(_b) {}

    bool operator<(const SLine &oth) const
    {
        return a < oth.a || (a == oth.a && b < oth.b);
    }

    double intersect(SLine oth)
    {
        return 1.0 * (oth.b - b) / (a - oth.a);
    }

    long long at(int pos)
    {
        return 1LL * a * pos + b;
    }
};
vector<pair<SLine, int>> con[D];

struct SCHT
{
    vector<SLine> ve;
    int pt = 0;

    void push(SLine u)
    {
        if (!ve.empty() && u.a == ve.back().a)
        {
            u.b = max(u.b, ve.back().b);
            ve.pop_back();
        }
        while (ve.size() >= 2 && u.intersect(ve[ve.size() - 2]) >= u.intersect(ve[ve.size() - 1]))
            ve.pop_back();
        ve.push_back(u);
    }

    void build(vector<pair<SLine, int>> &upd)
    {
        ve.clear();
        pt = 0;
        for (pair<SLine, int> &v : upd)
            push(v.fi);
    }

    long long maxima(int pos)
    {
        while (pt + 1 < (int)ve.size() && ve[pt].at(pos) <= ve[pt + 1].at(pos))
            pt++;
        return ve[pt].at(pos);
    }
} cht[D];

void DFS(int u)
{
    in[u] = ++cnt;
    for (int &v : adj[u])
        DFS(v);
    out[u] = cnt;
}

void update(int l, int r, int u)
{
    int bl = l / d;
    for (; l <= r && l / d == bl; l++)
    {
        con[bl][ind[l][0]].fi.b += 1LL * a[l] * u;
        con[bl][ind[l][1]].fi.b -= 1LL * a[l] * u;
    }
    cht[bl].build(con[bl]);
    for (; l + d - 1 <= r; l += d)
        add[l / d] += u;
    if (l > r)
        return;
    bl = l / d;
    for (; l <= r; l++)
    {
        con[bl][ind[l][0]].fi.b += 1LL * a[l] * u;
        con[bl][ind[l][1]].fi.b -= 1LL * a[l] * u;
    }
    cht[bl].build(con[bl]);
}

long long query(int l, int r)
{
    long long ans = 0;
    int bl = l / d;
    for (; l <= r && l / d == bl; l++)
    {
        ans = max(ans, con[bl][ind[l][0]].fi.at(add[bl]));
        ans = max(ans, con[bl][ind[l][1]].fi.at(add[bl]));
    }
    for (; l + d - 1 <= r; l += d)
        ans = max(ans, cht[l / d].maxima(add[l / d]));
    bl = l / d;
    for (; l <= r; l++)
    {
        ans = max(ans, con[bl][ind[l][0]].fi.at(add[bl]));
        ans = max(ans, con[bl][ind[l][1]].fi.at(add[bl]));
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    d = sqrt((n - 1) / 6) + 1;
    for (int i = 2; i <= n; i++)
    {
        cin >> p[i];
        adj[p[i]].push_back(i);
    }
    DFS(1);
    for (int i = 1; i <= n; i++)
    {
        cin >> u;
        b[in[i]] = b[in[p[i]]] + u;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> u;
        a[in[i]] = a[in[p[i]]] + u;
    }
    for (int i = 0; i < n; i += d)
    {
        int bl = i / d;
        for (int j = i; j < (bl + 1) * d && j < n; j++)
        {
            con[bl].push_back({SLine(a[j], 1LL * a[j] * b[j]), j + 1});
            con[bl].push_back({SLine(-a[j], -1LL * a[j] * b[j]), -j - 1});
        }
        sort(con[bl].begin(), con[bl].end());
        for (int i = 0; i < (int)con[bl].size(); i++)
        {
            int u = con[bl][i].se;
            if (u > 0)
                ind[u - 1][0] = i;
            else
                ind[-u - 1][1] = i;
        }
        cht[bl].build(con[bl]);
    }
    while (q--)
    {
        cin >> t >> u;
        if (t == 1)
        {
            cin >> x;
            update(in[u], out[u], x);
        }
        else
            cout << query(in[u], out[u]) << '\n';
    }
}