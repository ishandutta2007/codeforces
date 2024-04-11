#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

signed main()
{

    fast;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        vector<int> v;
        cin >> n;
        for (int i = 0; i < n;i++)
        {
            int x;
            cin >> x;
            v.emplace_back(x);
        }
        sort(v.begin(), v.end());
        cout << (int)(v.end() - upper_bound(v.begin(), v.end(), v[0])) << '\n';
    }
}