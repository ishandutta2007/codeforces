#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < N; ++i) {
            int x, y, u, v; cin >> x >> y >> u >> v;
            int mx = u-x, my = v-y;
            int g = __gcd(abs(mx), abs(my));
            mx /= g, my /= g;
            mp[{mx, my}] ++;
        }
        int64_t ans = 0;
        for (auto [dir, cnt] : mp) {
            int x, y; tie(x, y) = dir;
            if (make_pair(x, y) < make_pair(-x, -y) && mp.count({-x, -y})) {
                ans += int64_t(cnt) * mp[{-x, -y}];
            }
        }
        cout << ans << '\n';
    }
}