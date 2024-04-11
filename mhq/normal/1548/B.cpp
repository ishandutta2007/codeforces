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
ll b[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i < n; i++) {
            b[i] = abs(a[i + 1] - a[i]);
        }
        vector<pair<ll,int>> st;
        int best = 1;
        for (int i = 1; i < n; i++) {
            vector<pair<ll,int>> nst;
            for (auto& it : st) {
                it.first = __gcd(it.first, b[i]);
            }
            st.emplace_back(b[i], i);
            for (auto& it : st) {
                if (nst.empty() || nst.back().first != it.first) nst.emplace_back(it);
            }
            st = nst;
            if (st[0].first != 1) {
                best = max(best, i - st[0].second + 2);
            }
            else {
                if (st.size() > 1) {
                    best = max(best, i - st[1].second + 2);
                }
            }
        }
        cout << best << '\n';
    }
    return 0;
}