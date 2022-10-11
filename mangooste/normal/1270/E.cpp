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


const int INF = 1'000'000;
int n;
vector<int> x, y;

bool try_solve() {
    array<vector<int>, 4> types;
    for (int i = 0; i < n; i++) {
        int cx = x[i] % 2;
        int cy = y[i] % 2;
        int cur_type = cx * 2 + cy;
        types[cur_type].push_back(i);
    }
    if ((int)(types[0].size() + types[3].size()) != 0 && (int)(types[0].size() + types[3].size()) != n) {
        vector<int> ans;
        for (auto el : types[0]) {
            ans.push_back(el + 1);
        }
        for (auto el : types[3]) {
            ans.push_back(el + 1);
        }
        cout << ans.size() << '\n';
        for (auto el : ans) {
            cout << el << ' ';
        }
        cout << '\n';
        return true;
    }
    for (int i = 0; i < 4; i++) {
        if (!types[i].empty() && (int)types[i].size() != n) {
            cout << types[i].size() << '\n';
            for (auto el : types[i]) {
                cout << el + 1 << ' ';
            }
            cout << '\n';
            return true;
        }
    }
    return false;
}

void Main() {
    cin >> n;
    x.resize(n);
    y.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        x[i] += INF;
        y[i] += INF;
    }
    while (!try_solve()) {
        for (int i = 0; i < n; i++) {
            x[i] = (x[i] + 1) / 2;
            y[i] = (y[i] + 1) / 2;
        }
    }
}