#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <functional>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

void Main();

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(10);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    Main();
#ifdef LOCAL
    cout << "\nTime: " << (int)ceil((double)1000 * clock() / CLOCKS_PER_SEC) << " ms";
#endif
}

void Main() {
    int t = 1;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<ll> a(n), b(k);
        for (auto &el : a) {
            cin >> el;
        }
        for (auto &el : b) {
            cin >> el;
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        vector<vector<ll>> real(k);
        int pos = k - 1;
        for (int i = n - k; i < n; i++) {
            real[pos--].push_back(a[i]);
        }
        pos = k - 1;
        for (int i = 0; i < n - k; i++) {
            if ((int)real[pos].size() >= b[pos]) {
                pos--;
            }
            real[pos].push_back(a[i]);
        }
        ll ans = 0;
        for (auto &el : real) {
            ans += *min_element(el.begin(), el.end()) + *max_element(el.begin(), el.end());
        }
        cout << ans << '\n';
    }
}