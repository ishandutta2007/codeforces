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

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<array<int, 3>> suf(n, {-1, -1, -1});
    suf[n - 1][s[n - 1] - '1'] = n - 1;
    for (int i = n - 2; i >= 0; i--) {
        suf[i] = suf[i + 1];
        suf[i][s[i] - '1'] = i;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (suf[i][0] == -1 || suf[i][1] == -1 || suf[i][2] == -1)
            continue;
        int cur_ans = max({suf[i][0], suf[i][1], suf[i][2]}) - i + 1;
        if (ans == 0 || cur_ans < ans)
            ans = cur_ans;
    }
    cout << ans << '\n';
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}