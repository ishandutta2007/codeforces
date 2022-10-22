#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

ll binpow(ll n, ll p) {
    if(p == 0) return 1ll;
    ll q = binpow(n, p / 2);
    q = min(ll(inf), 1ll * q * q);
    if(p % 2) q = min(ll(inf), 1ll * q * n);
    return q;
}

int const MAX_VAL = 10 * 1000 * 1000 + 5;

ll pref[MAX_VAL];

ll gcd(ll x, ll y) {
    return !x ? y : gcd(y % x, x);
}

int is_sqrt[MAX_VAL];

int main() {

    ll c, l, r;

    cin >> c >> l >> r;

    if(c == 1) {
        cout << r - l + 1 << "\n";
        return 0;
    }

    if(c == 2) {
        ll len = r - l + 1;
        cout << len * (len - 1) << "\n";
        return 0;
    }

    if(0 && c == 3) {
        for(int i = 1;i * i < MAX_VAL;i++) is_sqrt[i * i] = i;
        ll result = 0;
        for(int z = l;z <= r;z++) {
            int delt = is_sqrt[z] * is_sqrt[z] != z ? z : is_sqrt[z];
            for(int x = delt;x < MAX_VAL;x += delt) {
                if(z < x && x * x % z == 0) {
                    ll y = 1ll * x * x / z;
                    if(l <= z && z < x && x < y && y <= r) {
                        result++;
                    }
                }
            }
        }
        cout << 2 * result << "\n";
        return 0;
    }

    // pref[i] -> max x ^ (c - 1) <= i
    // suff[i] -> min x ^ (c - 1) >= i

    pref[0] = 0ll;
    pref[1] = 1ll;

    for(ll x = 2;x < MAX_VAL;x++) {
        pref[x] = pref[x - 1];
        while(binpow(pref[x] + 1, c - 1) <= x) {
            pref[x]++;
        }
    }

    ll result = 0;

    for(ll value, m, n = 1;(value = binpow(n, c - 1)) < MAX_VAL;n++) {
        for(ll b0 = value;b0 < MAX_VAL;b0 += value) {
            if(b0 < l) continue;
            if(b0 > r) break;
            m = pref[int(ll(r) * ll(value) / ll(b0))];
            for(ll tmp_m = n + 1;tmp_m <= m;tmp_m++) {
                result += gcd(tmp_m, n) == 1;
            }
        }
    }

    cout << 2ll * result << "\n";

    return 0;
}