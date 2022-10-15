#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 1337;

ll getMod(ll a, ll b) {
    return a < b ? a : a % b + b;
}

ll binpow(ll a, ll p, ll mod = MOD) {
    ll res = 1;
    while (p) {
        if (p & 1) {
            res = getMod(res * a, mod);
        }
        a = getMod(a * a, mod);
        p >>= 1;
    }
    return res;
}

int getPhi(int n) {
    int ans = n;
    int d = 2;
    while (d * d <= n) {
        if (n % d == 0) {
            ans = ans / d * (d - 1);
            do {
                n /= d;
            } while (n % d == 0);
        }
        d++;
    }
    if (n != 1)
        ans = ans / n * (n - 1);
    return ans;
}

void solve() {
    const int LEN = 80;

    int n, m;
    cin >> n >> m;
    vector<int> mods(LEN);
    mods[0] = m;
    for (int i = 1; i < LEN; i++) {
        mods[i] = getPhi(mods[i - 1]);
    }

    vector<ll> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        if (l == r) {
            cout << w[l] % m << '\n';
            continue;
        }
        int kek = min(LEN - 2, r - l - 1);
        ll res = getMod(w[l + kek + 1], mods[kek + 1]);
        for (int d = kek; d >= 0; d--) {
            res = binpow(w[l + d], res, mods[d]);
        }
        cout << res % m << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}