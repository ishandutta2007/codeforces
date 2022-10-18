#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, a[100005], res = 100000000;

        set<int> s;
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            s.insert(a[i]);
        }
        for (auto p : s)
        {
            int r = 0;
            for (int i = 0; i < n; i++)
            {
                if (a[i] != p)
                {
                    i += k - 1;
                    r++;
                }
            }
            res = min(r, res);
        }
        cout << res << '\n';

    }
}