#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 1e5 + 10;
int n;
ll h[maxN];
ll A, R, M;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> A >> R >> M;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    sort(h + 1, h + n + 1);
    h[0] = 0;
    h[n + 1] = h[n];
    ll sum_small = 0;
    ll sum_big = 0;
    for (int i = 1; i <= n; i++) sum_big += h[i];
    ll opt = 1e18;
    for (int i = 0; i <= n; i++) {
        ll l = h[i];
        ll r = h[i + 1];
        ll cnt_small = i;
        ll cnt_big = n - i;
        auto calc =[&](ll F) {
            ll p1 = F * cnt_small - sum_small;
            ll p2 = sum_big - F * cnt_big;
            ll T1 = min(p1, p2) * M + (p1 - min(p1, p2)) * A + (p2 - min(p1, p2)) * R;
            ll T2 = p1 * A + p2 * R;
            return min(T1, T2);
        };
        opt = min(opt, calc(l));
        opt = min(opt, calc(r));
        while (r - l > 5) {
            ll l1 = (2 * l + r) / 3;
            ll r1 = (2 * r + l) / 3;
            if (calc(r1) > calc(l1)) r = r1;
            else l = l1;
        }
        for (ll p = l; p <= r; p++) opt = min(opt, calc(p));
        sum_small += h[i + 1];
        sum_big -= h[i + 1];
    }
    cout << opt;
    return 0;
}