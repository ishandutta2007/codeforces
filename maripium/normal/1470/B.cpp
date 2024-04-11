#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    const int MX = 1.1e6;
    vector<int> go(MX, 1);
    for (int i = 2; i*i < MX; ++i) {
        for (int j = i*i; j < MX; j += i*i) go[j] = i;
    }
    auto reduce = [&](int v) {
        while (go[v] > 1) {
            v /= (go[v] * go[v]);
        }
        return v;
    };
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        map<int, int> mp;
        for (int i = 0; i < N; ++i) {
            int v; cin >> v;
            mp[reduce(v)] ++;
        }
        int ans0 = 0;
        int ans1 = 0;
        for (auto [x, y] : mp) {
            ans0 = max(ans0, y);
            if (y % 2 == 0 || x == 1) ans1 += y;
        }
        for (auto [x, y] : mp) {
            if ((x > 1) && (y & 1)) ans1 = max(ans1, y);
        }
        int Q; cin >> Q;
        while (Q--) {
            int64_t W; cin >> W;
            cout << (W == 0 ? ans0 : ans1) << '\n';
        }
    }
}