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
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    bool any = false;
    for (auto &el : a) {
        cin >> el;
        if (el % x) {
            any = true;
        }
    }
    if (!any) {
        cout << "-1\n";
        return;
    }
    int answer = 1;
    vector<int> last(x, -1);
    last[0] = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        int ost = sum % x;
        if (last[ost] == -1 || last[ost] != i) {
            answer = max(answer, i - last[ost]);
        }
        if (last[ost] == i) {
            last[ost] = i + 1;
        }
    }
    cout << answer << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve_case();
    }
}