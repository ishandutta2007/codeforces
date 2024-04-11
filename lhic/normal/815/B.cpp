#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long long llong;
typedef long double ld;

using namespace std;

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
        cerr << (*i) << " ";
    }
    cerr << "\n";
}

int n;

ll a[220000];
ll b[220000];
const ll MOD = 1e9 + 7;

int solve() {
    int fl = 0;
    int cur = n;
    for (int i = 0; i < n - 1; ++i) {
        for (int i = 0; i < cur - 1; ++i) {
            if (fl == 0)
                b[i] = (a[i] + a[i + 1]) % MOD;
            else
                b[i] = (a[i] - a[i + 1] + MOD) % MOD;
            fl ^= 1;
        }
        --cur;
        for (int i = 0; i < cur; ++i)
            a[i] = b[i];
    }
    return a[0];
}

const int MX = 220000;

ll fc[MX];
ll bfc[MX];

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

void init() {
    fc[0] = 1;
    for (int i = 1; i < MX; ++i)
        fc[i] = (fc[i - 1] * i) % MOD;
    for (int i = 0; i < MX; ++i)
        bfc[i] = pw(fc[i], MOD - 2);
}


ll cnk(int n, int k) {
    return fc[n] * bfc[k] % MOD * bfc[n - k] % MOD;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", a + i);
    }
    if (n <= 5) {
        cout << solve() << "\n";
        return 0;
    }
    if (n % 2 == 1) {
        int fl = 0;
        int cur = n;
        for (int i = 0; i < 1; ++i) {
            for (int i = 0; i < cur - 1; ++i) {
                if (fl == 0)
                    b[i] = (a[i] + a[i + 1]) % MOD;
                else
                    b[i] = (a[i] - a[i + 1] + MOD) % MOD;
                fl ^= 1;
            }
            --cur;
            for (int i = 0; i < cur; ++i)
                a[i] = b[i];
        }
        n = cur;
        assert(fl == 0);
    }
    ll ans = 0;
    init();
    if (n % 4 == 0) {
        int k = n / 2 - 1;
        for (int i = 0; i < n; ++i) {
            ll c = cnk(k, i / 2);
            if (i % 2 == 1)
                c = -c;
            ans = (ans + (a[i] * c) % MOD + MOD) % MOD;
        }
    }
    else {
        int k = n / 2 - 1;
        for (int i = 0; i < n; ++i) {
            ll c = cnk(k, i / 2);
            ans = (ans + (a[i] * c) % MOD + MOD) % MOD;
        }
    }
    cout << ans << "\n";
    return 0;
}