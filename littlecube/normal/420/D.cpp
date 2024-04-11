/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/extc++.h>
#include <bits/stdc++.h>
//#pragma pack(0)
//#define int long long
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

int n, m, used[1000006], ans[1000006], front;
tree<int, pii, less<int>, rb_tree_tag, tree_order_statistics_node_update> st;

signed main()
{
    fast;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        st.insert({i, pii{i, 0}});
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        auto iter = st.find_by_order(y - 1);
        if (iter->S.S == 0)
            iter->S.S = x;
        else if (iter->S.S != x)
        {
            cout << -1 << '\n';
            return 0;
        }
        st.erase(iter);
        st.insert({front--, iter->S});
    }
    for (auto [u, v] : st)
    {
        ans[v.F] = v.S;
        used[v.S]++;
    }
    for (int i = 1; i <= n; i++)
        if(used[i] >= 2)
        {
            cout << -1 << '\n';
            return 0;
        }
    for (int i = 1, j = 1; i <= n; i++)
        if (!ans[i])
            for (; j <= n; j++)
                if(!used[j])
                {
                    ans[i] = j;
                    used[j] = 1;
                    break;
                }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " \n"[i == n];
}