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
        int n, k, a[105] = {0};
        vector<int> stop;
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i < n; i++)
            if (a[i] < a[i + 1])
            {
                int times = a[i + 1] - a[i];
                while (times--)
                    for (int j = i; j >= 1; j--)
                    {
                        if (a[j] < a[j + 1])
                        {
                            stop.emplace_back(j);
                            a[j]++;
                        }
                        else
                            break;
                    }
            }
        if(stop.size() >= k)
            cout << stop[k-1] << '\n';
        else
            cout << "-1\n";
    }
}