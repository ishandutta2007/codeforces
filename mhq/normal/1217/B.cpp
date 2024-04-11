#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
bool cmp(pair < ll, ll >& a, pair < ll, ll >& b) {
    return a.first - a.second > b.first - b.second;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        vector < pair < ll, ll > > all;
        ll x;
        cin >> n >> x;
        for (int i = 0; i < n; i++) {
            ll d, h;
            cin >> d >> h;
            all.emplace_back(d, h);
        }
        ll best = x + 10;
        sort(all.begin(), all.end(), cmp);
        for (int lst = 0; lst < n; lst++) {
            if (x <= all[lst].first) {
                best = 1;
                continue;
            }
            ll add = all[0].first - all[0].second;
            if (add <= 0) continue;
            best = min(best, (x - all[lst].first + add - 1) / add + 1);
        }
        if (best == x + 10) {
            cout << -1 << '\n';
        }
        else cout << best << '\n';
    }
    return 0;
}