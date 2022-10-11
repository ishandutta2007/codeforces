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
 
// #define int long long
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fun function
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    int mx = 0;
    for (auto &i : a) {
        for (auto &el : i) {
            cin >> el;
            mx = max(mx, el);
        }
    }
    int need_mask = (1 << m) - 1;
    Fun<pair<int, int>(int)> Get = [&](int val) {
        vector<int> masks(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] >= val) {
                    masks[i] += (1 << j);
                }
            }
            if (masks[i] == need_mask) {
                return mp(i, i);
            }
        }
        vector<int> maybe(need_mask + 1, -1);
        for (int i = 0; i < n; i++) {
            maybe[masks[i]] = i;
        }
        for (int i = 0; i < need_mask; i++) {
            if (maybe[i] == -1) {
                continue;
            }
            for (int j = i + 1; j < need_mask + 1; j++) {
                if ((i | j) == need_mask && maybe[j] != -1) {
                    return mp(maybe[i], maybe[j]);
                }
            }
        }
        return mp(-1, -1);
    };
    int L = 0, R = mx + 1;
    while (R - L > 1) {
        int mid = (L + R) / 2;
        if (Get(mid) != mp(-1, -1)) {
            L = mid;
        } else {
            R = mid;
        }
    }
    pair<int, int> ans = Get(L);
    cout << ans.first + 1 << ' ' << ans.second + 1 << '\n';
}