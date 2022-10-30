#include <stdio.h>
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <set>
#include <cmath>
#include <cstdlib>
#include <map>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <stdlib.h>
#include <assert.h>
#include <complex>
#include <cstring>

using namespace std;

typedef long long ll;

typedef complex<double> cd;

const int inf = 1000000000;
const long long longinf = 1000000000000000000;
const double PI = 3.141592653589793;

ll pw(ll a, ll p, ll mod) {
    ll ans = 1;
    while (p > 0) {
        if (p % 2 == 1) {
            ans = (ans * a) % mod;
        }
        a = (a * a) % mod;
        p /= 2;
    }
    return ans;
}

const int chk = 30000;

const int MAXM = 2001000;

ll rfc[MAXM];
ll fc[MAXM];


ll c(ll n, ll k, ll mod) {

    return ((fc[n] * rfc[k]) % mod) * rfc[n - k] % mod;
}

void solve() {
    ll n, m, a, q;
    cin >> n >> m >> a >> q;
    ll st = pw(a, chk, q);
    ll bs = a;
    ll phi = 1;
    ll q1 = q;
    for (int i = 2; i < 1000000; ++i) {
        if (q1 % i == 0) {
            phi *= i - 1;
            q1 /= i;
            while (q1 % i == 0)
                q1 /= i, phi *= i;
        }
    }
    if (q1 > 1)
        phi *= q1 - 1;

    ll md = phi;
    for (ll i = 1; i < 1000000; ++i) {
        if (phi % i == 0) {
            if (pw(a, i, q) == 1) {
                md = min(i, md);
            }
            if (pw(a, phi / i, q) == 1) {
                md = min(phi / i, md);
            }
        }
    }
//    unordered_map<ll, ll> dl;
//    for (int i = 1; i < phi; i += chk) {
//        dl[bs] = i;
//        bs = (bs * st) % q;
//    }
//    ll j = 0;
//    bs = 1;
//    ll ra = pw(a, phi - 1, q);
//    while (dl.find(bs) == dl.end()) {
//        ++j;
//        bs = (bs * ra) % q;
//    }
//    ll md = dl[bs] + j;
    fc[0] = 1;
    for (int i = 1; i < md; ++i) {
        fc[i] = (fc[i - 1] * i) % md;
    }
    rfc[md - 1] = pw(fc[md - 1], md - 2, md);
    for (ll i = md - 2; i >= 0; --i) {
        rfc[i] = (rfc[i + 1] * (i + 1)) % md;
    }
    vector<ll> ans(n);
    ans[0] = 1;
    for (int i = 1; i < n; ++i) {
        ans[i] = c(m, i, md);
        ans[i] += ans[i - 1], ans[i] %= md;
    }
    for (int i = 0; i < n; ++i) {
        ans[i] = pw(a, ans[i], q);
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << endl;
}

int main() {
    cout.precision(20);
    cin.tie(0);
//    srand(time(0));
    iostream::sync_with_stdio(false);
    solve();
    return 0;
}