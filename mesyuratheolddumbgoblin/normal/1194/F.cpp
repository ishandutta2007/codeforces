#include <sstream>
#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <time.h>
#include <vector>
#include <algorithm>
#include <bitset>
#include <utility>
#include <map>
#include <set>

#define MOD 1000000007
#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
ll fac[205000], invfac[200500], a[200500], p2[200500], invp2[200500];
ll n, m;
ll binpow(ll x, ll y) {
    if (y == 0) {
        return 1;
    }
    ll tmp = binpow(x, y / 2);
    tmp = tmp * tmp % MOD;
    if (y % 2) {
        return x * tmp % MOD;
    }
    return tmp;
}

ll inv(ll x) {
    return binpow(x, MOD - 2);
}

ll C(ll n, ll m) {
    return fac[n] * invfac[m] % MOD * invfac[n-m] % MOD;
}

void su(ll &x, ll y) {
    x -= y;
    x %= MOD;
    x += MOD;
    x %= MOD;
}

int main() {
    cin >> n >> m;
    fac[0] = invfac[0] = 1;
    p2[0] = 1;
    for (int i = 1; i <= n + 20; i++) {
        fac[i] = fac[i-1] * i % MOD;
        invfac[i] = inv(fac[i]);
        p2[i] = p2[i-1] * 2 % MOD;
        invp2[i] = inv(p2[i]);
    }

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        //a[i] = 1;
    }

    ll p = 1;
    ll ans = 0;
    ll ls = MOD;
    for (int i = 0; i < n; i++) {
        m -= a[i];
        if (m < 0) {
            ans += p * i % MOD;
            p = 0;
            break;
        }
        if (m >= i + 1) {
            continue;
        }
        if (ls == MOD) {
            ls = m;
            for (int j = ls + 1; j <= i + 1; j++) {
                ans += C(i + 1, j) * invp2[i + 1] % MOD * i % MOD;
                su(p, C(i + 1, j) * invp2[i + 1]);
            }
        } else {
            for (int j = m + 1; j <= ls; j++) {
                ans += C(i + 1, j) * invp2[i + 1] % MOD * i % MOD;
                su(p, C(i + 1, j) * invp2[i + 1]);
            }
            ans += C(i, ls) * invp2[i + 1] % MOD * i % MOD;
            su(p, C(i, ls) * invp2[i + 1]);
            ls = m;
        }
    }
    ans += p * n % MOD;
    cout << ans % MOD << endl;

    return 0;
}