#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

vector<int> prime = {2};
bitset<20005> not_prime = 3;
int mp[20000005];

ll cal(ll n)
{
    ll m = n;
    if (mp[n] != 0)
        return mp[n];
    for (int i : prime)
    {
        if (i > sqrt(n))
            break;
        else if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            return mp[m] = cal(n) + 1;
        }
    }
    if (n > 1)
        return mp[n] = 1;
    return mp[n] = 0;
}

void solve()
{
    ll c, d, x, res = 0;
    cin >> c >> d >> x;
    vector<int> v;
    for (ll i = 1; i <= sqrt(x); i++)
    {
        if (x % i == 0)
        {
            v.emplace_back(i);
            if (i * i != x)
                v.emplace_back(x / i);
        }
    }
    for (ll i : v)
        if ((x / i + d) % c == 0)
        {
            ll k = (x / i + d) / c;
            res += (1 << cal(k));
        }
    cout << res << '\n';
}

signed main()
{
    fast;
    for (int i = 4; i <= 20000; i += 2)
        not_prime[i] = 1;
    for (int i = 3; i <= 500; i += 2)
        if (!not_prime[i])
            for (int j = i * i; j <= 20000; j += 2 * i)
                not_prime[j] = 1;
    for (int i = 3; i <= 20000; i += 2)
        if (!not_prime[i])
            prime.emplace_back(i);
    int t;
    cin >> t;
    while (t--)
        solve();
}