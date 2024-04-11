#pragma GCC optimize("Ofast", "unroll-loops", "omit-frame-pointer", "fast-math")//, "rename-registers")//,"inline") //Optimization flags

#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1000111, inf = 1000111222;
long long mod = 998244353;

long long pm(ll a, ll b) {
    if (b == 0) {
        return 1;
    }
    if (b % 2 == 0) {
        return pm((a * a) % mod, b / 2);
    } else {
        return (a * pm(a, b - 1)) % mod;
    }
}

long long fact[max_n];
ll rfact[max_n];

void precalc() {
    fact[0] = 1;
    rfact[0] = 1;
    for (int i = 1; i < max_n; ++i) {
        fact[i] = (fact[i - 1] * i) % mod;
        rfact[i] = (rfact[i - 1] * pm(i, mod - 2)) % mod;
    }
}

ll C(int n, int k) {
    ll ans = (fact[n] * rfact[k]) % mod;
    ans *= rfact[n - k];
    return ans % mod;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    precalc();
    int n;
    cin >> n;
    ll ans = fact[n] * n;
    ans %= mod;
    for (int i = 1; i < n; ++i) {
        ll minn = (C(n, i) * fact[i]) % mod;
        ans -= minn;
        if (ans < 0) {
            ans += mod;
        }
    }
    ans += 2 * mod;
    ans %= mod;
    cout << ans << endl;

    return 0;
}