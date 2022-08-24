#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector < int > cnt(26);
    int sum = 0;
    for (int i = 0; i < k; i++) {
        char s;
        cin >> s;
        cnt[s - 'A']++;
    }
    for (int i = 0; i < 26; i++) {
        sum += cnt[i];
    }
    ll opt = (ll)1e18;
    for (int take = 0; take < 26; take++) {
        vector < bool > can(k + 1, false);
        can[0] = true;
        for (int j = 0; j < 26; j++) {
            if (j == take) continue;
            for (int res = k; res >= cnt[j]; res--) {
                can[res] = can[res] | can[res - cnt[j]];
            }
        }
        int cur_sum = sum - cnt[take];
        for (int sm = 0; sm <= k; sm++) {
            if (!can[sm]) continue;
            if (sm + cnt[take] < n || (cur_sum - sm + cnt[take]) < m) continue;
            int need1 = max(0, n - sm);
            int need2 = max(0, m - (cur_sum - sm));
            opt = min(opt, 1LL * need1 * need2);
        }
    }
    cout << opt << '\n';
}
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tst;
    cin >> tst;
    while (tst--) solve();
    return 0;
}