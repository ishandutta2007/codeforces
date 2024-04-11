/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
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
#define LOCAL

int n, m;
vector<int> ans, E[200005], cur, old;

signed main()
{
    fast;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cur.emplace_back(i);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        E[u].emplace_back(v);
        E[v].emplace_back(u);
    }
    for (int i = 1; i <= n; i++)
        sort(E[i].begin(), E[i].end());
    while (!cur.empty())
    {
        queue<int> q;
        int cnt = 0;
        q.push(cur.back());
        cur.pop_back();
        while (!q.empty())
        {
            cnt++;
            int u = q.front(), idx = 0;
            //cout << u << '\n';
            q.pop();
            for (int v : E[u])
            {
                while (idx < cur.size() && cur[idx] < v)
                {
                    q.push(cur[idx]);
                    idx++;
                }
                if (idx < cur.size() && cur[idx] == v)
                {
                    old.push_back(v);
                    idx++;
                }
            }
            while (idx < cur.size())
            {
                q.push(cur[idx]);
                idx++;
            }
            cur.swap(old);
            old.clear();
        }
        ans.emplace_back(cnt);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (int i : ans)
        cout << i << " ";
}