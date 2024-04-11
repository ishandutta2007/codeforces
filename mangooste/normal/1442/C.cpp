#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define len(a) ((int)((a).size()))

template<typename A, typename B>
ostream& operator<<(ostream &out, pair<A, B> p) { return out << '(' << p.first << ", " << p.second << ')'; }

template<typename A, typename B = typename enable_if<!is_same<A, string>::value, typename A::value_type>::type>
ostream& operator<<(ostream &out, A vec) { out << '{'; string sep; for (B x : vec) out << sep << x, sep = ", "; return out << '}'; }

void dbg_print() { cerr << endl; }
template<typename A, typename... B> void dbg_print(A a, B... b) { cerr << ' ' << a; dbg_print(b...); }

#ifdef LOCAL
    #define dbg(...) cerr << '#' << __LINE__ << " [" << #__VA_ARGS__ << "]:", dbg_print(__VA_ARGS__)
#else
    #define dbg(...)
#endif



int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    array<vector<vector<int>>, 2> g;
    g.fill(vector<vector<int>>(n));

    while (m--) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        g[0][v].push_back(u);
        g[1][u].push_back(v);
    }

    const int LG = __lg(n) + 1;
    const int INF = 1e9;

    auto dijkstra = [&]() {
        vector<vector<array<int, 2>>> dist(n, vector<array<int, 2>>(LG, {INF, INF}));
        priority_queue<array<int, 4>, vector<array<int, 4>>, greater<>> pq;
        dist[0][0][0] = 0;
        pq.push({0, 0, 0, 0});

        while (len(pq)) {
            auto [cur_d, v, level, type] = pq.top();
            pq.pop();
            if (cur_d != dist[v][level][type])
                continue;

            auto relax = [&](int u, int u_level, int u_type, int cost) {
                if (u_level >= LG || dist[u][u_level][u_type] <= cur_d + cost)
                    return;

                dist[u][u_level][u_type] = cur_d + cost;
                pq.push({cur_d + cost, u, u_level, u_type});
            };

            relax(v, level + 1, type ^ 1, 1 << level);
            for (auto u : g[type][v])
                relax(u, level, type, 1);
        }
        return dist;
    };

    {
        auto dist = dijkstra();
        int mn = INF;
        for (int i = 0; i < LG; i++)
            mn = min({mn, dist[n - 1][i][0], dist[n - 1][i][1]});

        if (mn != INF) {
            cout << mn << '\n';
            return 0;
        }
    }

    const int MOD = 998244353;
    vector<int> p2(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        p2[i] = p2[i - 1] * 2;
        if (p2[i] >= MOD)
            p2[i] -= MOD;
    }

    vector<array<int, 2>> dist_mod(n);
    vector<array<pair<int, int>, 2>> dist(n, {pair<int, int>{INF, INF}, {INF, INF}});
    priority_queue<pair<pair<int, int>, pair<int, int>>, vector<pair<pair<int, int>, pair<int, int>>>, greater<>> pq;
    dist[0][0] = {0, 0};
    pq.push({dist[0][0], {0, 0}});

    while (len(pq)) {
        auto [cur_d, v_data] = pq.top();
        auto [v, type] = v_data;
        pq.pop();
        if (cur_d != dist[v][type])
            continue;

        auto relax = [&](int u, int u_type, pair<int, int> new_d, int new_d_mod) {
            if (dist[u][u_type] <= new_d)
                return;

            dist[u][u_type] = new_d;
            dist_mod[u][u_type] = new_d_mod;
            if (dist_mod[u][u_type] >= MOD)
                dist_mod[u][u_type] -= MOD;

            pq.push({dist[u][u_type], {u, u_type}});
        };

        relax(v, type ^ 1, {cur_d.first + 1, cur_d.second}, dist_mod[v][type] + p2[cur_d.first]);
        for (auto u : g[type][v])
            relax(u, type, {cur_d.first, cur_d.second + 1}, dist_mod[v][type] + 1);
    }
    cout << (dist[n - 1][0] < dist[n - 1][1] ? dist_mod[n - 1][0] : dist_mod[n - 1][1]) << '\n';
}