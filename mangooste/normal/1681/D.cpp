#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) int((a).size())

#ifdef LOCAL
    #include "debug.h"
#else
    #define dbg(...)
#endif // LOCAL

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    ll x;
    cin >> n >> x;

    unordered_map<ll, int> dist;
    dist.rehash(3e6);
    dist[x] = 0;
    queue<pair<ll, int>> que;
    que.emplace(x, 0);

    while (!que.empty()) {
        auto [v, cur_dist] = que.front();
        que.pop();

        auto s = to_string(v);
        if (len(s) == n) {
            cout << cur_dist << '\n';
            return 0;
        }
        for (char c : s) {
            int y = c - '0';
            ll x = v * y;
            if (!dist.count(x)) {
                dist[x] = cur_dist + 1;
                que.emplace(x, cur_dist + 1);
            }
        }
    }
    cout << "-1\n";
}