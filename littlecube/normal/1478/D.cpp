#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

ll gcd(ll a, ll b)
{
    if (a * b == 0)
        return max(abs(a), abs(b));
    return gcd(b, a % b);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k, a[200005], g = 0;
        cin >> n >> k;
        for (ll i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        for (ll i = 1; i < n; i++)
        {
            g = gcd(g, a[i] - a[i - 1]);
            if (g == 1)
                break;
        }
        if (((k % g) + g) % g == ((a[0] % g) + g) % g)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}