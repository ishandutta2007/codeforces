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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    int m = *max_element(all(a)) + 1;
    vector<vector<int>> poses(m);
    for (int i = 0; i < n; i++)
        poses[a[i]].push_back(i);
    vector<vector<int>> cnt(n + 1, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        cnt[i + 1] = cnt[i];
        cnt[i + 1][a[i]]++;
    }
    int ans = *max_element(all(cnt.back()));
    for (int a = 0; a < m; a++) {
        int sz = poses[a].size();
        for (int i = 0; i < sz - i - 1; i++) {
            int L = poses[a][i] + 1;
            int R = poses[a][sz - i - 1];
            int mx = 0;
            for (int b = 0; b < m; b++)
                mx = max(mx, cnt[R][b] - cnt[L][b]);
            ans = max(ans, 2 * (i + 1) + mx);
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}