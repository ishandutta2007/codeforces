#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2e5 + 10;
ll a[maxN];
ll pref_odd[maxN], pref_even[maxN];
ll calc_single(int x) {
    if (x == 0) return 0;
    vector < int > d;
    while (x) {
        d.emplace_back(min(x, 9));
        x -= min(x, 9);
    }
    reverse(d.begin(), d.end());
    ll ans = 0;
    for (int& v : d) {
        ans = 10 * ans + v;
    }
    return ans;
}
const ll PINF = 1e18;
ll safe_mult(ll a, ll b) {
    if (!a || !b) return 0;
    if (a >= (PINF + b - 1) / b) return PINF;
    return a * b;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n, k;
        cin >> n >> k;
        const ll INF = 4e17;
        ll best = 5e18;
        for (int res = 0; res < 10; res++) {
            int cnt0 = 0;
            int cnt1 = 0;
            int sum_dig = 0;
            for (int p = 0; p <= k; p++) {
                sum_dig += (res + p) % 10;
                if (res + p < 10) cnt0++;
                else cnt1++;
            }
            if (sum_dig > n) continue;
            int lft = n - sum_dig;
            if (cnt0 == 0) {
                if (lft % cnt1 == 0) {
                    ll f = calc_single(lft / cnt1);
                    f--;
                    if (f < 0) continue;
                    best = min(best, 10 * f + res);
                }
            }
            else if (cnt1 == 0) {
                if (lft % cnt0 == 0) {
                    ll f = calc_single(lft / cnt0);
                    best = min(best, 10 * f + res);
                }
            }
            else {
                for (int x = 0; x * cnt0 <= lft; x++) {
                    if ((lft - x * cnt0) % cnt1 != 0) continue;
                    int y = (lft - x * cnt0) / cnt1;
                    //S = x, S + 1 = y
                    for (int last_nine = 0; last_nine * 9 <= x; last_nine++) {
                        int will = (x - last_nine * 9) + 1;
                        if (will != y) continue;
                        for (int p = 0; p <= 8 && p <= x; p++) {
                            ll nbest = calc_single(x - p);
                            if (nbest > PINF) continue;
                            nbest = safe_mult(nbest, 10);
                            nbest += p;
                            for (int c = 0; c < last_nine; c++) {
                                nbest = safe_mult(nbest, 10);
                                nbest += 9;
                            }
                            nbest = safe_mult(nbest, 10);
                            nbest += res;
                            best = min(best, nbest);
                        }
                    }
                }
            }
        }
        if (best > 4e18) {
            cout << -1 << '\n';
            continue;
        }
        cout << best << '\n';
    }
    return 0;
}