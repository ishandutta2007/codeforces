#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define ll long long
#define pii pair<ll, ll>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

string s, t;
int a[1000005], x, y, tx, ty, sum;

signed main()
{
    fast;
    cin >> s >> s >> t;
    for (int i = 0; i < s.length(); i++)
        a[i] = s[i] - t[i], sum += a[i];
    if(sum)
    {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < s.length(); i++)
    {
        tx = max(a[i], tx + a[i]);
        x = max(x, tx);
    }
    for (int i = 0; i < s.length(); i++)
    {
        ty = max(-a[i], ty - a[i]);
        y = max(y, ty);
    }
    cout << max(x, y) << '\n';
}