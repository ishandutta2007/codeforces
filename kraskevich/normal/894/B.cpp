#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

const ll MOD = 1000 * 1000 * 1000 + 7;

ll bpow(ll x, ll n) {
    ll res = 1;
    for (; n > 0; n /= 2) {
        if (n % 2)
            res = res * x % MOD;
        x = x * x % MOD;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;
    int k;
    cin >> k;
    if (n % 2 != m % 2 && k == -1) {
        cout << 0 << endl;
        return 0;
    }
    ll res = bpow(bpow(2, n - 1), m - 1);
    cout << res << endl;
}