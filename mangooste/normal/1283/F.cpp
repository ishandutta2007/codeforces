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

int n;
vector<int> a;
vector<pair<int, int>> ans;

void Main() {
    cin >> n;
    a.resize(n - 1);
    for (auto &el : a) {
        cin >> el;
    }
    set<int> was;
    if (a[0] == n) {
        was.insert(n);
    }
    int cur_v = n;
    for (int i = 0; i < n - 1;) {
        while (cur_v > 0 && was.count(cur_v)) {
            cur_v--;
        }
        if (cur_v < 1 || a[i] == cur_v) {
            cout << "-1\n";
            // cout << "bad1\n";
            return;
        }
        was.insert(cur_v);
        vector<int> way;
        do {
            way.push_back(a[i]);
            was.insert(a[i]);
            i++;
        } while (i < n - 1 && !was.count(a[i]));
        for (int j = 1; j < (int)way.size(); j++) {
            ans.emplace_back(way[j - 1], way[j]);
        }
        ans.emplace_back(way.back(), cur_v--);
        // cout << "ans =  ";
        // for (auto el : ans) {
        //     cout << " (" << el.first << ' ' << el.second << ')';
        // }
        // cout << '\n';
    }
    for (int i = 0; i < n; i++) {
        if (!was.count(i + 1)) {
            cout << "-1\n";
            // cout << "bad2\n";
            return;
        }
    }
    cout << a[0] << '\n';
    for (auto el : ans) {
        cout << el.first << ' ' << el.second << '\n';
    }
}