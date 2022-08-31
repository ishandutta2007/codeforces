#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>
#include <functional>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long long llong;
typedef long double ld;

using namespace std;

#ifndef LOCAL
#define cerr _cer
struct _cert
{
    template <typename T> _cert& operator << (T) { return *this; }
};
_cert _cer;
#endif

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
		cerr << (*i) << " ";
    }
    cerr << "\n";
}
const ll MOD = 1e9 + 7;
ll B;

struct st {
    ll s, s2, pw, bpw;
    st(ll S = 0, ll S2 = 0) {
        S %= MOD;
        S2 %= MOD;
        s = S, s2 = S2;
        pw = 2;
        bpw = B;
    }
};

const int MX = 1001000;

st mrg(st a, st b) {
    st x;
    x.s = (a.s * b.pw + b.s * a.pw) % MOD;
    x.s2 = (a.s2 * b.pw + b.s2 * a.pw + 2 * a.s * b.s) % MOD;
    x.pw = (a.pw * b.pw) % MOD;
    x.bpw = (a.bpw * b.bpw) % MOD;
    return x;
}

st del(st x, st b) {
    st a;
    a.pw = (x.pw * b.bpw) % MOD;
    a.bpw = (x.bpw * b.pw) % MOD;
    a.s = (x.s - b.s * a.pw % MOD + MOD) * b.bpw % MOD;
    a.s2 = (x.s2 - b.s2 * a.pw % MOD - 2 * a.s * b.s % MOD + 2 * MOD) * b.bpw % MOD;
    return a;
}

ll pw(ll a, ll b) {
    ll ans = 1;
    while (b) {
        while (!(b & 1))
            b >>= 1, a = (a * a) % MOD;
        --b;
        ans = (ans * a) % MOD;
    }
    return ans;
}

int n;
st dp[MX];
int bc[100];
int ad[100];
ll gg[MX];

int popcount(int x) {
    int ans = 0;
    while (x) {
        ans += (x & 1);
        x >>= 1;
    }
    return ans;
}

int main() {
    B = pw(2, MOD - 2);
    for (int i = 0; i < 1000000; ++i) {
        dp[i].pw = 1;
        dp[i].bpw = 1;
    }
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        dp[x] = mrg(dp[x], st(x, (ll)x * x));
    }
    for (int i = 0; i < (1 << 6); ++i) {
        bc[i] = __builtin_popcount(i) % 2;
        ll now = 1;
        for (int j = 0; j < 6; ++j, now *= 10) {
            if ((i >> j) & 1)
                ad[i] += now;
        }
    }
    ll ans = 0;
    for (int i = 999999; i >= 0; --i) {
        int k = 0;
        int now = 1;
        int tmp = i;
        while (tmp) {
            if (tmp % 10 == 9)
                k += now;
            tmp /= 10;
            now *= 2;
        }
        st dl(0, 0);
        dl.pw = 1;
        dl.bpw = 1;
        for (int j = 1; j < (1 << 6); ++j) {
            if ((k & j) || !bc[j])
                continue;
            int tmp = i + ad[j];
            dp[i] = mrg(dp[i], dp[tmp]);
            gg[i] -= dp[tmp].s2;
        }
        for (int j = 1; j < (1 << 6); ++j) {
            if ((k & j) || bc[j])
                continue;
            int tmp = i + ad[j];
            dl = mrg(dl, dp[tmp]);
            gg[i] += dp[tmp].s2;
        }
        dp[i] = del(dp[i], dl);
        gg[i] += dp[i].s2;
        gg[i] %= MOD;
        if (gg[i] < 0)
            gg[i] += MOD;
        ans ^= (ll)i * gg[i];
    }
    cout << ans << "\n";
	return 0;
}