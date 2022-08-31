#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
   // freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        map<int,vector<int>> mp;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            mp[x].emplace_back(i);
        }
        ll ans = 0;
        for (auto& it : mp) {
            auto& vec = it.second;
            ll sum_good = 0;
            for (auto& t : vec) sum_good += n + 1 - t;
            for (auto& t : vec) {
                sum_good -= (n + 1 - t);
                ans += t * sum_good;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}