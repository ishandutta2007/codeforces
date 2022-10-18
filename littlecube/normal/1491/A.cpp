#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n, q, arr[500005], cnt;
signed main()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        cnt += arr[i];
    }
    for (int i = 1; i <= q; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a == 1)
        {
            if (arr[b] == 1)
                cnt--;
            if (arr[b] == 0)
                cnt++;
            arr[b] = 1 - arr[b];
        }
        if (a == 2)
        {
            if (cnt >= b)
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
    }
}