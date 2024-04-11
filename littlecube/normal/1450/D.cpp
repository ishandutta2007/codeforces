#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define ll long long
#define pii pair<ll, ll>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int t, n, arr[3000005], ans[3000005], x;
deque<int> dq;

signed main()
{
    fast;
    cin >> t;
    while (t--)
    {
        cin >> n;
        dq.clear();
        for (int i = 0; i <= n; i++)
            arr[i] = 0, ans[i] = 0;

        for (int i = 1; i <= n; i++)
        {
            cin >> x;
            arr[x]++;
            dq.push_back(x);
        }
        for (int i = 1; i <= n; i++)
            if (arr[i] != 1)
                break;
            else if (i == n)
                ans[1] = 1;

        if (arr[1])
            ans[n] = 1;

        for (int i = 1; i <= n; i++)
            if (arr[i] == 1 && arr[i + 1] > 0)
            {
                if (dq.front() == i)
                    dq.pop_front(), ans[n - i] = 1;
                else if (dq.back() == i)
                    dq.pop_back(), ans[n - i] = 1;
                else
                    break;
            }
            else
                break;

        for (int i = 1; i <= n; i++)
            cout << ans[i];
        cout << '\n';
    }
}