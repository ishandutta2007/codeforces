#include <bits/stdc++.h>
using namespace std;
 
int n, u;
long long m;
map<int, int> ma;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> u;
        ma[u]++;
    }
    while (m >= 0) {
        auto [l, lc] = *ma.begin();
        auto [r, rc] = *prev(ma.end());
        if (l == r) {
            return cout << 0, 0;
        }
        if (lc < rc) {
            ma.erase(ma.begin());
            int nxt = ma.begin()->first;
            if (1LL * (nxt - l) * lc <= m) {
                ma[nxt] += lc;
                m -= 1LL * (nxt - l) * lc;
            } else {
                return cout << r - (l + m / lc), 0;
            }
        } else {
            ma.erase(prev(ma.end()));
            int nxt = prev(ma.end())->first;
            if (1LL * (r - nxt) * rc <= m) {
                ma[nxt] += rc;
                m -= 1LL * (r - nxt) * rc;
            } else {
                return cout << (r - m / rc) - l, 0;
            }
        }
    }
}