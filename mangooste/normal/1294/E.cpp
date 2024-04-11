#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

// #define int long long
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto &el : a) {
        for (auto &ell : el) {
            cin >> ell;
        }
    }
    int ans = 0;
    for (int j = 0; j < m; j++) {
        vector<int> cnt(n, 0);
        for (int i = 0; i < n; i++) {
            int cur = a[i][j] - (j + 1);
            if (cur % m == 0) {
                int to = cur / m;
                if (to >= n) {
                    continue;
                }
                if (to > i) {
                    cnt[i + n - to]++;
                } else {
                    cnt[i - to]++;
                }
            }
        }
        int cur_ans = n;
        for (int i = 0; i < n; i++) {
            cur_ans = min(cur_ans, n - cnt[i] + i);
        }
        ans += cur_ans;
    }
    cout << ans << '\n';
}