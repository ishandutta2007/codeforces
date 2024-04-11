#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = (int)1e6 + 100;
int a[maxN];
ll b[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    ll tot = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        tot += a[i];
    }
    vector < ll > pr;
    for (int i = 2; 1LL * i * i <= tot; i++) {
        if (tot % i == 0) {
            pr.emplace_back(i);
            while (tot % i == 0) {
                tot /= i;
            }
        }
    }
    if (tot > 1) pr.emplace_back(tot);
    ll best = 1e18;
    for (ll x : pr) {
        ll val = 0;
        ll delta = 0;
        for (int i = 1; i <= n; i++) {
            b[i] = (a[i] + delta) % x;
            ll ndelta = b[i];
            val += min(ndelta % x, x - ndelta % x);
            delta = ndelta;
        }
        best = min(best, val);
    }
    if (best > 1e17) {
        cout << -1;
    }
    else {
        cout << best;
    }
    return 0;
}