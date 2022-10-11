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
    }
    bool one = false, zero = false;
    for (auto &el : b) {
        cin >> el;
        one |= (el == 1);
        zero |= (el == 0);
    }
    if (one && zero) {
        cout << "YES\n";
    } else {
        cout << (is_sorted(a.begin(), a.end()) ? "YES\n" : "NO\n");
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}