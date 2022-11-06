#include <utility>
#include <bitset>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <time.h>
#include <iostream>
#include <vector>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define y1 dskgj
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
#define PI 3.14159265359
#define MOD 1000003
typedef long long ll;
using namespace std;

ll a[300500], x, y, z, n, m;
vector<ll> f;
ll Abs(ll x) {
    return (x > 0 ? x : -x);
}
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a%b);
}
bool prime(ll x) {
    for (int i = 2; i < x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}
ll binpow(ll x, ll y) {
    if (y == 0) {
        return 1;
    }
    ll tmp = binpow(x, y/2);
    tmp = tmp * tmp % MOD;
    if (y % 2) {
        return x * tmp % MOD;
    }
    return tmp;
}

ll inv(ll x) {
    return binpow(x, MOD - 2);
}
ll dp[300500][3];
ll b[55][12];
ll cnt(ll y) {
    return (y * y + 1000002) % MOD;
}
ll query(ll x) {
    ll y;
    cout << "? " << x << endl;
    fflush(stdout);
    cin >> y;
    //y = cnt(x);
    if (y == 0) {
        cout << "! " << x << endl;
        exit(0);
    }
    return y;
}
vector<pii> g;
ll ans[15];
int main() {
    for (int i = 2; i < 1000; i++) {
        if (prime(i)) {
            f.push_back(i);
        }
    }

    ll x = query(0);
    g.push_back(mp(0, x));
    for (int i = 0; i < 49; i++) {
        ll x = query(f[i]);
        g.push_back(mp(f[i], x));
    }

    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 11; j++) {
            b[i][j] = binpow(g[i].X, j);
        }
        b[i][11] = g[i].Y;
    }
    for (int j = 0; j < 11; j++) {
        for (int i = j; i < 50; i++) {
            if (b[i][j] != 0) {
                for (int k = 0; k < 12; k++) {
                    swap(b[i][k], b[j][k]);
                }
                break;
            }
        }
        ll pp = inv(b[j][j]);
        for (int k = 0; k < 12; k++) {
            b[j][k] = b[j][k] * pp % MOD;
        }
        for (int i = j + 1; i < 50; i++) {
            ll div = b[i][j];
            for (int k = 0; k < 12; k++) {
                b[i][k] = ((b[i][k] - div * b[j][k]) % MOD + MOD) % MOD;
            }
        }
    }

    for (int i = 10; i >= 0; i--) {
        ll cur = b[i][11];
        for (int j = i + 1; j < 11; j++) {
            cur -= b[i][j] * ans[j];
        }
        cur = (cur % MOD + MOD) % MOD;
        ans[i] = cur * inv(b[i][i]) % MOD;
    }
    for (int i = 0; i < MOD; i++) {
        ll tot = 0;
        for (int j = 0; j < 11; j++) {
            tot += ans[j] * binpow(i, j);
        }
        if (tot % MOD == 0) {
            cout << "! " << i << endl;
            return 0;
        }
    }
    cout << "! " << -1 << endl;
    return 0;
}