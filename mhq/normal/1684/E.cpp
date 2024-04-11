#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, k;
const int maxN = 1e5 + 10;
int a[maxN];
void solve() {
    map<int,int> cnt;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    vector<int> difs;
    vector<pair<int, int>> vals;
    for (auto& it : cnt) {
        difs.emplace_back(it.second);
        vals.emplace_back(it);
    }
    reverse(vals.begin(), vals.end());
    sort(difs.begin(), difs.end());
    int T = difs.size();
    int best = T;
    difs.erase(unique(difs.begin(), difs.end()), difs.end());
    int cnt_bigger = n;
    vector<int> sz(difs.size());
    for (auto& it : vals) {
        int pos = lower_bound(difs.begin(), difs.end(), it.second) - difs.begin();
        sz[pos] += 1;
    }
    int need = 0;
    int bad = 0;
    for (int mex = 0; mex <= n; mex++) {
        if (cnt_bigger + bad < need || need > k) {
            break;
        }
        int killed = 0;
        int need_bad = max(0, need - cnt_bigger);
        int D = k - need_bad;
        for (int j = 0; j < sz.size(); j++) {
            killed += min(sz[j], D / difs[j]);
            D -= min(sz[j], D / difs[j]) * difs[j];
        }
        best = min(best, T - killed - mex + need);
        if (!vals.empty() && vals.back().first == mex) {
            cnt_bigger -= (vals.back().second);
            bad += (vals.back().second - 1);
            int pos = lower_bound(difs.begin(), difs.end(), vals.back().second) - difs.begin();
            sz[pos] -= 1;
            vals.pop_back();
        }
        else {
            need++;
        }
    }
    cout << best << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        solve();
    }
    return 0;
}