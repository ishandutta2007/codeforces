#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int N = 100 * 1000 + 10;
const ll MOD = 1000 * 1000 * 1000 + 7;

ll binPow(ll x, ll n) {
    ll res = 1;
    for (; n > 0; n /= 2) {
        if (n & 1)
            res = res * x % MOD;
        x = x * x % MOD;
    }
    return res;
}

ll inv(ll x) {
    ll r = binPow(x, MOD - 2);
    assert (r * x % MOD == 1);
    return r;
}

ll f[N];
ll invf[N];

void init() {
    f[0] = 1;
    for (int i = 1; i < N; i++)
        f[i] = f[i - 1] * i % MOD;
    for (int i = 0; i < N; i++)
        invf[i] = inv(f[i]);
}

ll cnk(ll n, ll k) {
    if (k > n || n < 0 || k < 0)
        return 0;
    return f[n] * invf[k] % MOD * invf[n - k] % MOD;
}

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
    init();
    ll A, B, h;
    cin >> A >> B >> h;
    if (B == 0) {
        cout << 1 << endl;
        return 0;
    }
    if (A == 0) {
        cout << (B > h ? 1 : 0) << endl;
        return 0;
    }
    assert(A && B);
    ll good = 0;
    ll tot = 0;
    for (ll a = 1; a <= A; a++)
        for (ll b = max(1ll, a - 1); b <= min(B, a + 1); b++) {
            ll totA = cnk(A - 1, a - 1);
            ll totB = cnk(B - 1, b - 1);
            //cerr << A << " " << B << " " << totA << " " << totB << endl;
            ll goodA = totA;
            ll goodB = cnk(B - h * b - 1, b - 1);
            ll mul = 1;
            if (a == b)
                mul = 2;
            tot += mul * totA * totB;
            tot %= MOD;
            good += mul * goodA * goodB;
            good %= MOD;
        }
    //cerr << good << " " << tot << endl;
    assert (tot);
    cout << good * inv(tot) % MOD << endl;
}