/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
//#include <bits/extc++.h>
#include <bits/stdc++.h>
//#pragma pack(0)
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

int t, n, m, sa, sb, a[1005], b[1005];
bitset<250005> dp[505], tr[505];

void calc(int n, int sum, int *arr, bitset<250005> dp[], bitset<250005> tr[])
{
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
        dp[i].reset(), tr[i].reset();
    for (int i = 1; i <= n; i++)
    {
        dp[i] = dp[i - 1] | (dp[i - 1] << arr[i]);
        tr[i] = dp[i - 1] << arr[i];
    }
}

vector<int> rev(int n, int sum, int *arr, bitset<250005> tr[])
{
    vector<int> ans;
    while (n)
    {
        if (tr[n][sum])
        {
            ans.emplace_back(arr[n]);
            sum -= arr[n];
        }
        else
            ans.emplace_back(-arr[n]);
        n--;
    }
    return ans;
}

signed main()
{
    fast;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        cin >> m;
        for (int i = 1; i <= m; i++)
            cin >> b[i];
        if (n != m)
        {
            cout << "No\n";
            continue;
        }
        sa = 0;
        sb = 0;
        for (int i = 1; i <= n; i++)
            sa += a[i];
        for (int i = 1; i <= m; i++)
            sb += b[i];

        if (sb % 2 == 1 || sa % 2 == 1)
        {
            cout << "No\n";
            continue;
        }
        sa /= 2, sb /= 2;

        calc(n, sa, a, dp, tr);
        if (!dp[n][sa])
        {
            cout << "No\n";
            continue;
        }
        vector<int> h = rev(n, sa, a, tr);
        calc(m, sb, b, dp, tr);
        if (!dp[m][sb])
        {
            cout << "No\n";
            continue;
        }
        vector<int> v = rev(m, sb, b, tr);
        int nh = 0, nv = 0;
        for (int i : h)
            if (i < 0)
                nh++;
        for (int i : v)
            if (i < 0)
                nv++;
        if (nv < nh)
        {
            for (int &i : v)
                i = -i;
            for (int &i : h)
                i = -i;
        }
        sort(h.begin(), h.end(), [](int a, int b)
             {if(a * b < 0) return a > 0; return abs(a) < abs(b); });
        sort(v.begin(), v.end(), [](int a, int b)
             {if(a * b < 0) return a > 0; return abs(a) > abs(b); });

        cout << "Yes\n";
        int x = 0, y = 0;
        for (int i = 0; i < n; i++)
        {
            y += v[i];
            cout << x << ' ' << y << '\n';
            x += h[i];
            cout << x << ' ' << y << '\n';
        }
    }
}