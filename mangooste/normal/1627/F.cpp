#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

void solve() {
    int n, k;
    cin >> n >> k;

    map<pair<pair<int, int>, pair<int, int>>, int> cnt;
    for (int i = 0; i < n; i++) {
        pair<int, int> c1, c2;
        cin >> c1.first >> c1.second >> c2.first >> c2.second;
        c1.first--, c1.second--, c2.first--, c2.second--;

        cnt[{c1, c2}]++;
        cnt[{c2, c1}]++;

        c1.first = k - 1 - c1.first;
        c1.second = k - 1 - c1.second;
        c2.first = k - 1 - c2.first;
        c2.second = k - 1 - c2.second;

        cnt[{c1, c2}]++;
        cnt[{c2, c1}]++;
    }

    constexpr int INF = 1e9;
    vector dist(k + 1, vector<int>(k + 1, INF));
    dist[0][0] = 0;

    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq;
    pq.push({0, 0, 0});

    while (!pq.empty()) {
        auto [d, x, y] = pq.top();
        pq.pop();
        if (d != dist[x][y])
            continue;

        auto relax = [&](int xx, int yy, int new_dist) {
            new_dist += dist[x][y];
            if (dist[xx][yy] > new_dist) {
                dist[xx][yy] = new_dist;
                pq.push({new_dist, xx, yy});
            }
        };

        if (x + 1 <= k)
            relax(x + 1, y, cnt[{{x, y - 1}, {x, y}}]);

        if (x - 1 >= 0)
            relax(x - 1, y, cnt[{{x - 1, y - 1}, {x - 1, y}}]);

        if (y + 1 <= k)
            relax(x, y + 1, cnt[{{x - 1, y}, {x, y}}]);

        if (y - 1 >= 0)
            relax(x, y - 1, cnt[{{x - 1, y - 1}, {x, y - 1}}]);
    }

    cout << n - dist[k / 2][k / 2] << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--)
        solve();
}