/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/extc++.h>
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
using namespace __gnu_pbds;

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

struct Q
{
    int u, v, w, id;
    Q(int u, int v, int w, int id) : u(u), v(v), w(w), id(id){};
};

ll N, M, dsu[200005], rk[200005], pre[200005][20], mxpre[200005][20], ans[200005], mst, t = 0;
pii ts[200005];
vector<pii> e[200005];
vector<Q> edge;
vector<Q> query;

int find(int k)
{
    return dsu[k] == k ? k : (dsu[k] = find(dsu[k]));
}

void merge(int rx, int ry)
{
    if (rk[rx] > rk[ry])
        rk[rx] += rk[ry], dsu[ry] = rx;
    else
        rk[ry] += rk[rx], dsu[rx] = ry;
}

void dfs(int k)
{
    ts[k].F = ++t;
    for (auto p : e[k])
        if (p.F != pre[k][0])
        {
            pre[p.F][0] = k;
            mxpre[p.F][0] = p.S;
            for (int i = 1; i < 20; i++)
            {
                pre[p.F][i] = pre[pre[p.F][i - 1]][i - 1];
                mxpre[p.F][i] = max(mxpre[p.F][i - 1], mxpre[pre[p.F][i - 1]][i - 1]);
            }
            dfs(p.F);
        }
    ts[k].S = ++t;
}

signed main()
{
    fast;
    cin >> N >> M;

    for (int i = 1; i <= M; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edge.emplace_back(Q(u, v, w, i));
    }

    sort(edge.begin(), edge.end(), [](Q q1, Q q2)
         { return q1.w < q2.w; });

    for (int i = 1; i <= N; i++)
        dsu[i] = i, rk[i] = 1;

    for (auto E : edge)
        if (find(E.u) != find(E.v))
        {
            e[E.u].pb(make_pair(E.v, E.w));
            e[E.v].pb(make_pair(E.u, E.w));
            merge(find(E.u), find(E.v));
            mst += E.w;
        }
        else
            query.pb(E);

    for (int i = 0; i < 20; i++)
    {
        pre[1][i] = 1;
        mxpre[1][i] = 0;
    }
    dfs(1);

    for (int i = 1; i <= M; i++)
        ans[i] = mst;
    for (auto q : query)
    {
        ll lca, mxw = 0;
        if ((ts[q.u].F <= ts[q.v].F && ts[q.v].S <= ts[q.u].S))
            lca = q.u;
        else if ((ts[q.v].F <= ts[q.u].F && ts[q.u].S <= ts[q.v].S))
            lca = q.v;
        else
        {
            lca = q.u;
            for (int p = 19; p >= 0; p--)
                if (!(ts[pre[lca][p]].F <= ts[q.v].F && ts[q.v].S <= ts[pre[lca][p]].S))
                    lca = pre[lca][p];

            if (!(ts[lca].F <= ts[q.v].F && ts[q.v].S <= ts[lca].S))
                lca = pre[lca][0];
        }


        for (int p = 19; p >= 0; p--)
            if (ts[lca].F <= ts[pre[q.u][p]].F && ts[pre[q.u][p]].S <= ts[lca].S)
            {
                mxw = max(mxw, mxpre[q.u][p]);
                q.u = pre[q.u][p];
            }
        
        for (int p = 19; p >= 0; p--)
            if (ts[lca].F <= ts[pre[q.v][p]].F && ts[pre[q.v][p]].S <= ts[lca].S)
            {
                mxw = max(mxw, mxpre[q.v][p]);
                q.v = pre[q.v][p];
            }

        ans[q.id] = mst - mxw + q.w;
    }
    for (int i = 1; i <= M; i++)
        cout << ans[i] << '\n';
}