#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 300111, inf = 1000111222;

ll f[max_n];

ll n, m;

ll sqr(ll a) {
    return (a * a) % m;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    f[0] = 1;
    for (int i = 1; i < max_n; ++i) {
        f[i] = (f[i - 1] * i) % m;
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        ll cur = sqr(n - i + 1) * f[i];
        cur %= m;
        cur *= f[n - i];
        cur %= m;
        ans += cur;
        ans %= m;
    }
    cout << ans << endl;

    return 0;
}