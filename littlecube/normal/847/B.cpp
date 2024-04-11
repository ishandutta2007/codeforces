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
#define pii128 pair<__int128, __int128>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using namespace __gnu_pbds;

int N, idx = 1;
vector<int> v[200005];
set<pii, greater<pii>> st;

signed main()
{
    fast;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int a;
        cin >> a;
        auto iter = st.lower_bound({a, 0});
        if (iter == st.end())
        {
            v[idx].emplace_back(a);
            st.insert({a, idx});
            idx++;
        }
        else
        {
            v[iter->S].emplace_back(a);
            st.insert({a, iter->S});
            st.erase(iter);
        }
    }
    for (int i = 1; i < idx; i++)
    {
        for(int j : v[i])
            cout << j << " ";
        cout << '\n';
    }
}