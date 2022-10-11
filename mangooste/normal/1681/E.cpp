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
    cin >> n;
    vector<array<pair<int, int>, 2>> cells(n - 1);
    vector<int> between(n - 1);

    auto dist = [&](const pair<int, int> &a, const pair<int, int> &b) {
        return abs(a.first - b.first) + abs(a.second - b.second);
    };

    for (int i = 0; i < n - 1; i++) {
        for (auto &[x, y] : cells[i]) {
            cin >> x >> y;
            x--, y--;
        }
        between[i] = dist(cells[i][0], cells[i][1]);
    }

    constexpr ll INF = 1e18;

    struct node {
        int from, to;
        ll dist[2][2];

        node() {
            for (int f : {0, 1}) {
                dist[f][0] = dist[f][1] = INF;
            }
        }
    };
    
    auto merge = [&](const node &left, const node &right) {
        node res;
        res.from = left.from;
        res.to = right.to;
        for (int f : {0, 1}) {
            for (int t : {0, 1}) {
                for (int m1 : {0, 1}) {
                    for (int m2 : {0, 1}) {
                        res.dist[f][t] = min(res.dist[f][t], left.dist[f][m1] + right.dist[m2][t] + (m1 == m2 ? 0 : between[left.to]));
                    }
                }
            }
        }
        return res;
    };

    const int LG = __lg(n) + 1;
    vector jump(LG, vector<node>(n - 2));
    for (int i = 0; i < n - 2; i++) {
        jump[0][i].from = i;
        jump[0][i].to = i + 1;
        for (int f : {0, 1}) {
            jump[0][i].dist[f][f] = dist(cells[i][f], cells[i + 1][f]);
            jump[0][i].dist[f][f ^ 1] = min(between[i] + dist(cells[i][f ^ 1], cells[i + 1][f ^ 1]),
                1 + dist({cells[i][f].first + (f ^ 1), cells[i][f].second + f}, cells[i + 1][f ^ 1]));
        }
    }

    for (int level = 1; level < LG; level++) {
        for (int i = 0; i + (1 << level) <= n - 2; i++) {
            jump[level][i] = merge(jump[level - 1][i], jump[level - 1][i + (1 << (level - 1))]);
        }
    }

    int q;
    cin >> q;
    while (q--) {
        pair<int, int> s, t;
        cin >> s.first >> s.second >> t.first >> t.second;
        s.first--, s.second--, t.first--, t.second--;

        int ss = max(s.first, s.second);
        int tt = max(t.first, t.second);
        if (ss == tt) {
            cout << dist(s, t) << '\n';
            continue;
        }

        if (ss > tt) {
            swap(ss, tt);
            swap(s, t);
        }

        node cur;
        cur.from = cur.to = ss;
        for (int f : {0, 1}) cur.dist[f][f] = 0;
        for (int i = LG - 1; i >= 0; i--) {
            if ((tt - 1 - ss) >> i & 1) {
                cur = merge(cur, jump[i][cur.to]);
            }
        }

        ll ans = INF;
        for (int rot_s : {0, 1}) {
            for (int rot_t : {0, 1}) {
                ll already = dist(s, cells[ss][rot_s]) + 1 + dist(t, {cells[tt - 1][rot_t].first + (rot_t ^ 1), cells[tt - 1][rot_t].second + rot_t});
                ans = min(ans, already + cur.dist[rot_s][rot_t]);
            }
        }
        cout << ans << '\n';
    }
}