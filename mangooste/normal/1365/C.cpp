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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &el : a) {
        cin >> el;
        el--;
    }
    for (auto &el : b) {
        cin >> el;
        el--;
    }
    vector<int> where(n);
    for (int i = 0; i < n; i++) {
        where[b[i]] = i;
    }
    map<int, int> want;
    for (int i = 0; i < n; i++) {
        int j = where[a[i]];
        int cur;
        if (j >= i) {
            cur = j - i;
        } else {
            cur = j + n - i;
        }
        want[cur]++;
    }
    int ans = 0;
    for (auto &el : want) {
        ans = max(ans, el.second);
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}