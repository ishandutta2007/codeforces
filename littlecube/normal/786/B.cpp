/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/extc++.h>
//#include <bits/stdc++.h>
//#pragma pack(0)
//#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define pii128 pair<__int128, __int128>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
//using namespace __gnu_pbds;

int N, Q, s;
ll dis[400005], leaf[100005];
vector<pll> E[400005];
priority_queue<pll, vector<pll>, greater<pll>> pq;

// 1 ~ 2N: down, 2N + 1 ~ 4N: up
void build(int i = 1, int L = 1, int R = N)
{
    if (L == R)
    {
        leaf[L] = i;
        E[i + 2 * N].emplace_back(pll{i, 0});
        E[i].emplace_back(pll{i + 2 * N, 0});
    }
    else
    {
        int mid = (L + R) / 2;
        E[i].emplace_back(pll{i + 1, 0});
        E[i].emplace_back(pll{i + 2 * (mid - L + 1), 0});
        E[2 * N + i + 1].emplace_back(pll{2 * N + i, 0});
        E[2 * N + i + 2 * (mid - L + 1)].emplace_back(pll{2 * N + i, 0});
        build(i + 1, L, mid);
        build(i + 2 * (mid - L + 1), mid + 1, R);
    }
}

// 1 ~ 2N: down, 2N + 1 ~ 4N: up
void modify_to(int v, int l, int r, ll w, int i = 1, int L = 1, int R = N)
{
    if (l <= L && R <= r)
        E[leaf[v] + 2 * N].emplace_back(pll{i, w});
    else if (r < L || R < l)
        return;
    else
    {
        int mid = (L + R) / 2;
        modify_to(v, l, r, w, i + 1, L, mid);
        modify_to(v, l, r, w, i + 2 * (mid - L + 1), mid + 1, R);
    }
}

// 1 ~ 2N: down, 2N + 1 ~ 4N: up
void modify_from(int v, int l, int r, ll w, int i = 1, int L = 1, int R = N)
{
    if (l <= L && R <= r)
        E[i + 2 * N].emplace_back(pll{leaf[v], w});
    else if (r < L || R < l)
        return;
    else
    {
        int mid = (L + R) / 2;
        modify_from(v, l, r, w, i + 1, L, mid);
        modify_from(v, l, r, w, i + 2 * (mid - L + 1), mid + 1, R);
    }
}

signed main()
{
    fast;
    cin >> N >> Q >> s;
    build();
    for (int i = 1; i <= Q; i++)
    {
        int t, v, l, r;
        ll w;
        cin >> t >> v >> l;
        if (t == 1)
        {
            cin >> w;
            modify_to(v, l, l, w);
        }
        else if (t == 2)
        {
            cin >> r >> w;
            modify_to(v, l, r, w);
        }
        else if (t == 3)
        {
            cin >> r >> w;
            modify_from(v, l, r, w);
        }
    }
    for (int i = 1; i <= 4 * N; i++)
        dis[i] = 1e18;
    dis[leaf[s]] = 0;
    pq.push(pll{0, leaf[s]});
    while (!pq.empty())
    {
        pll p = pq.top();
        pq.pop();
        if (dis[p.S] < p.F)
            continue;
        for (auto [u, w] : E[p.S])
            if (p.F + w < dis[u])
            {
                dis[u] = p.F + w;
                pq.push(pll{dis[u], u});
            }
    }
    for (int i = 1; i <= N; i++)
        cout << (dis[leaf[i]] > 9e17 ? -1 : dis[leaf[i]]) << " \n"[i == N];
}