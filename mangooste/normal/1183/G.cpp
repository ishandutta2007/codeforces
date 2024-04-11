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

void solve() {
    int n;
    cin >> n;
    vector<int> cnt_all(n, 0), cnt_bad(n, 0);
    for (int i = 0; i < n; i++) {
        int type, chk;
        cin >> type >> chk;
        type--;
        cnt_all[type]++;
        cnt_bad[type] += chk;
    }
    vector<vector<int>> this_num(n + 1);
    for (int i = 0; i < n; i++) {
        this_num[cnt_all[i]].pb(cnt_bad[i]);
    }
    int ans1 = 0, ans2 = 0;
    priority_queue<int> pq;
    for (int i = n; i >= 0; i--) {
        for (auto el : this_num[i]) {
            pq.push(el);
        }
        if (!pq.empty()) {
            int mx = pq.top();
            pq.pop();
            ans1 += i;
            ans2 += min(i, mx);
        }
    }
    cout << ans1 << ' ' << ans2 << '\n';
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        solve();
    }
}