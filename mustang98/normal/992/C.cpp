#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1, inf = 1000111222;

ll mod = 1000000007;

ld my(ll a, ll b) {
    ll res2 = a * (1 << b);
    ll res1 =  res2 - (1LL << b) + 2;
    cout << res1 << ' ' << res2 << endl;
    return 1.0 * (res1 + res2) / 2;
}

ld dumb(ll a, ll b) {
    if (b == 1) {
        return a * 2;
    }
    return 0.5 * dumb(a * 2 - 1, b - 1) + 0.5 * dumb(a * 2, b - 1);
}

ll powm(ll a, ll b) {
    if (b == 0) return 1;
    if (b % 2 == 0) {
        return powm((a * a) % mod, b / 2);
    } else {
        return (a * powm(a, b - 1)) % mod;
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    ll x, k;
    cin >> x >> k;
    if (x == 0) {
        cout << 0;
        return 0;
    }
    ++k;
    //cout << dumb(x, k) << endl;
    x %= mod;
    ll ans = x * powm(2, k) - powm(2, k - 1) + 1;
    while(ans < 0) ans += mod;
    ans %= mod;
    cout << ans;
    return 0;
}