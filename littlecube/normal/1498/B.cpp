#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

signed main()
{
    fast;
    int t, n, w, x[100005];
    cin >> t;
    while (t--)
    {
        cin >> n >> w;
        for (int i = 1; i <= n; i++)
            cin >> x[i];
        map<int, int, greater<int>> mp;
        for (int i = 1; i <= n; i++)
            mp[x[i]]++;
        vector<int> v(1);
        v[0] = w;
        for (auto i : mp)
        {
            //cout << "(" << i.F << " " << i.S << ")\n";
            for (int j = 0; i.second > 0; i.second--)
            {
                while (j < v.size() && v[j] < i.first)
                    j++;
                if (j >= v.size())
                    v.emplace_back(w - i.first);
                else
                    v[j] -= i.first;
            }
           // cout << v.size() << '\n';
        }
        cout << v.size() << '\n';
    }
}