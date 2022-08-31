#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
const int maxN = 2e5 + 10;
ll a[maxN];
vector<pair<ll,ll>> between[maxN];
void solve() {
    cin >> n >> m;
    a[0] = -(ll)1e10;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    a[n + 1] = (ll)1e10;
    vector<pair<int,int>> all;
    for (int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;
        all.emplace_back(l, r);
    }
    for (int i = 0; i <= n + 1; i++) {
        between[i].clear();
    }
    sort(all.begin(), all.end(), [&](pair<int,int> a, pair<int,int> b) {
        if (a.first != b.first) return a.first > b.first;
        return a.second < b.second;
    });
    vector<pair<int,int>> inter;
    int min_r = 2e9;
    for (auto& it : all) {
        if (it.second >= min_r) {
            continue;
        }
        min_r = it.second;
        inter.emplace_back(it);
    }
    reverse(inter.begin(), inter.end());
    for (int x = 0; x + 1 < inter.size(); x++) {
        assert(inter[x].first < inter[x + 1].first);
        assert(inter[x].second < inter[x + 1].second);
    }
    for (auto& it : inter) {
        int p1 = lower_bound(a, a + n + 2, it.first) - a;
        p1--;
        assert(a[p1] < it.first);
        if (it.second >= a[p1 + 1]) continue;
        between[p1 + 1].emplace_back(it);
    }
    vector<ll> dp = {0};
    for (int i = 1; i <= n + 1; i++) {
        vector<ll> ndp(between[i].size() + 1, 1e15);
        ll best = 1e18;
        for (int z = 0; z <= between[i - 1].size(); z++) {
            if (z == (int)between[i - 1].size()) {
                best = min(best, dp[z] - a[i - 1]);
            }
            else {
                best = min(best, dp[z] + a[i - 1] - 2 * between[i - 1][z].second);
            }
        }
        for (int z = 0; z <= (int)between[i].size(); z++) {
            if (z == 0) ndp[z] = min(ndp[z], best + a[i - 1]);
            else ndp[z] = min(ndp[z], best + between[i][z - 1].first);
        }
        best = 1e18;
        for (int z = 0; z <= between[i - 1].size(); z++) {
            if (z == (int)between[i - 1].size()) {
                best = min(best, dp[z] - 2 * a[i - 1]);
            }
            else {
                best = min(best, dp[z] - a[i - 1] - between[i - 1][z].second);
            }
        }
        for (int z = 0; z <= (int)between[i].size(); z++) {
            if (z == 0) ndp[z] = min(ndp[z], best + 2 * a[i - 1]);
            else ndp[z] = min(ndp[z], best + 2 * between[i][z - 1].first);
        }
        dp = ndp;
    }
    cout << dp.back() << '\n';
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