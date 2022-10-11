#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using ll = long long;
using namespace std;

// #define int long long
#define all(a) a.begin(), a.end()

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 1e8;
    int a_, b_, c_;
    a_ = b_ = c_ = -1;
    for (int i = 1; i < 3e4; i++) {
        for (int j = i; j <= 3e4; j += i) {
            for (int z = j; z <= 3e4; z += j) {
                int cur = abs(a - i) + abs(b - j) + abs(c - z);
                if (ans > cur)
                    ans = cur, a_ = i, b_ = j, c_ = z;
            }
        }
    }
    cout << ans << '\n';
    cout << a_ << ' ' << b_ << ' ' << c_ << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}