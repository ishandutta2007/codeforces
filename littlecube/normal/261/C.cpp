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

ll n, t, ans;
ll cnt[45][45];

signed main()
{
    fast;
    cin >> n >> t;
    if (t != (t & -t))
    {
        cout << 0;
        return 0;
    }
    t = (int)log2(t);
    for (int i = 0; i < 42; i++)
        cnt[i][0] = 1;
    for (int i = 1; i < 42; i++)
        for (int j = 1; j < 42; j++)
            cnt[i][j] = cnt[i - 1][j] + cnt[i - 1][j - 1];
    stack<ll> st;
    n += 2;
    while (n != (n & -n))
        st.push(n & -n), n -= (n & -n);
    //cout << n << '\n';
    n--;
    for (ll i = n; i > 0; i -= (i & -i))
    {
        ans += cnt[(int)log2(i & -i)][t];
        //cout << "Cal " << (i & -i) << " " << t << '\n';
    }
    for (ll i = 0; !st.empty() && t - i >= 0; i++)
    {
        //cout << "Cal* " << st.top() << " " << t - i << '\n';
        ans += cnt[(int)log2(st.top())][t - i], st.pop();
    }
    if (t == 0)
        ans--;
    cout << ans;
}