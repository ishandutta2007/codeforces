#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int cnt[45];
const int maxN = 1e5 + 10;
int ncnt[45];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        ll w;
        cin >> n >> w;
        memset(cnt, 0, sizeof cnt);
        ll l = 0;
        ll r = 1e9;
        for (int i = 1; i <= n; i++) {
            int w;
            cin >> w;
            for (int j = 0; j <= 20; j++) {
                if (w == (1 << j)) {
                    cnt[j]++;
                    break;
                }
            }
        }
        while (r - l > 1) {
            ll mid = (l + r) / 2;
            for (int x = 0; x <= 40; x++) {
                ncnt[x] = cnt[x];
            }
            bool ok = true;
            for (int x = 0; x <= 40; x++) {
                if (!ncnt[x]) continue;
                if (!(w & (1LL << x))) {
                    if (x == 40) {
                        ok = false;
                        break;
                    }
                    ncnt[x + 1] += (ncnt[x] + 1) / 2;
                    continue;
                }
                ll take = min((ll)ncnt[x], mid);
                ncnt[x] -= take;
                ncnt[x + 1] += (ncnt[x] + 1) / 2;
            }
            if (ok) {
                r = mid;
            }
            else {
                l = mid;
            }
        }
        cout << r << '\n';
    }
    return 0;
}