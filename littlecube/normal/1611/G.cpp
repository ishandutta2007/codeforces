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
// using namespace __gnu_pbds;

int t, n, m;
vector<pii> odd, even;

int solve(vector<pii> v)
{
    sort(v.begin(), v.end());
    multiset<int> st;
    for (pii p : v)
    {
        auto iter = st.lower_bound(p.F - p.S);
        if (iter != st.end())
            st.erase(iter);
        st.insert(p.F - p.S);
    }
    return st.size();
}

signed main()
{
    fast;
    cin >> t;
    while (t--)
    {
        odd.clear();
        even.clear();
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                char c;
                cin >> c;
                if (c == '1')
                {
                    if ((i + j) & 1)
                        odd.emplace_back(pii{(i + j) / 2, i});
                    else
                        even.emplace_back(pii{(i + j) / 2, i});
                }
            }
        cout << solve(odd) + solve(even) << '\n';
    }
}