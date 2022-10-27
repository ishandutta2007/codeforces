#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 10;
const int MOD = 1e9 + 7;
using ll = int64_t;

ll p(ll a, int x) {
    ll res = 1;;
    for (int i = 0 ; i < x ; ++ i) res = res * a;
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;
    for (cin >> T ; T -- ;) {
        ll n, k;
        cin >> n >> k;
        int x = 0;
        int res = 0;
        int p = 1;
        for (int i = 0 ; i < 30 ; ++ i) {
            if (k >> i & 1) res = (res + p) % MOD;
            p = 1ll * p * n % MOD;
        }
        cout << res << '\n';
    }
}