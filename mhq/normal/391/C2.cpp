#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
int n, k;
const int maxN = 2 * (int)1e5 + 10;
const ll INF = (ll)1e18;
int p[maxN], e[maxN];
ll solve(int wins) {
  //  cout << wins << endl;
    if (wins < 0 || wins > n) return INF;
    vector < int > other, need;
    int already = 0;
    vector < pair < int, int > > all;
    for (int i = 0; i < n; i++) {
        if (p[i] > wins) {
            other.push_back(e[i]);
            all.push_back(make_pair(e[i], 0));
        }
        else if (p[i] + 1 < wins) {
            other.push_back(e[i]);
            all.push_back(make_pair(e[i], 0));
            already++;
        }
        else {
            need.push_back(e[i]);
            all.push_back(make_pair(e[i], 1));
        }
    }
    sort(other.begin(), other.end());
    sort(need.begin(), need.end());
    sort(all.begin(), all.end());
    ll ans = 0;
    if (already >= n - k + 1) {
        for (int i = 0; i < wins; i++) {
            ans += all[i].first;
        }
        return ans;
    }
    else if (already + need.size() < n - k + 1) {
        return INF;
    }
    int need_to_add = n - k + 1 - already;
    for (int i = 0; i < all.size(); i++) {
        if (wins == 0) break;
        auto t = all[i];
        if (t.second == 1) {
            wins--;
            need_to_add--;
            ans += t.first;
        }
        else {
            if (wins > need_to_add) {
                wins--;
                ans += t.first;
            }
            else {
                continue;
            }
        }
    }
    if (wins > 0 || need_to_add > 0) return INF;
 //   cout << wins << " " << ans << endl;
    return ans;
}
int main() {
   // freopen("input.txt", "r", stdin);
    srand(239);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    vector < pair < int, int > > all(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i] >> e[i];
        all[i] = make_pair(p[i], e[i]);
    }
    sort(all.begin(), all.end());
    reverse(all.begin(), all.end());
    if (k == n + 1) {
        cout << 0;
        return 0;
    }
    ll ans = INF;
    for (int i = all[k - 1].first + 2; i >= max(all[k - 1].first - 2, 0); i--) {
        ans = min(ans, solve(i));
    }
    if (ans == INF) cout << -1;
    else cout << ans;
    return 0;
}