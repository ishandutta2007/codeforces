#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = 5005;
int a[maxN];
int q;
int n, k;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    vector < pair < int, int > > all;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        for (int j = 1; j <= k; j++) {
            all.emplace_back(a[i] * j, j);
        }
    }
    sort(all.begin(), all.end());
    vector < pair < int, int > > nall;
    for (int i = 0; i < all.size(); i++) {
        if (!nall.empty() && nall.back().first == all[i].first) continue;
        nall.push_back(all[i]);
    }
    all = nall;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int x;
        cin >> x;
        int best = 10000;
        for (int j = 0; j < all.size(); j++) {
            if (all[j].first > x) break;
            if (all[j].first == x) {
                best = min(best, all[j].second);
            }
            if (all[j].first + all[0].first > x) continue;
            if (all[j].first + all.back().first < x) continue;
            auto it = lower_bound(all.begin(), all.end(), make_pair(x - all[j].first + 1, -1)) - all.begin();
            it--;
            if (it < 0 || it >= all.size()) continue;
            if (all[it].first == x - all[j].first) best = min(best, all[it].second + all[j].second);
        }
        if (best > k) cout << -1 << '\n';
        else cout << best << '\n';
    }
}