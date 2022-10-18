#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n, m, a[100005], b[100005], err;
vector<int> v[100005], ans;
map<int, int> mp;

signed main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        err = 0;
        ans.clear();
        mp.clear();
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            v[i].clear();
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> b[i];
            if (a[i] != b[i])
            {
                v[b[i]].emplace_back(i);
                err++;
            }
            mp[b[i]] = i;
        }
        int sum = 0, i = 1;
        for (; i <= m; i++)
        {
            if (!err)
                break;
            int c;
            cin >> c;
            sum++;
            if (!v[c].empty())
            {
                while (sum--)
                    ans.emplace_back(v[c].back());
                sum = 0;
                v[c].pop_back();
                err--;
            }
        }
        for (; i <= m; i++)
        {

            int c;
            cin >> c;
            sum++;
            if (mp[c])
            {
                while (sum--)
                    ans.emplace_back(mp[c]);
                sum = 0;
            }
        }
        if (err || sum > 0)
            cout << "NO\n";
        else
        {
            cout << "YES\n";
            for (int i : ans)
                cout << i << " ";
            cout << '\n';
        }
    }
}