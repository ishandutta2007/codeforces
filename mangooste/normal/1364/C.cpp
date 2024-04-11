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

void solve_case() {
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> st;
    for (auto &el : a) {
        cin >> el;
        st.insert(el);
    }
    vector<int> b(n);
    set<int> can;
    for (int i = 0; i <= 2 * n; i++) {
        if(!st.count(i)) {
            can.insert(i);
        }
    }
    for (int i = 0; i < n; i++) {
        b[i] = *can.begin();
        can.erase(can.begin());
        if (i != n - 1 && a[i + 1] != a[i]) {
            can.insert(a[i]);
        }
    }
    for (auto &el : b) {
        cout << el << ' ';
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve_case();
    }
}