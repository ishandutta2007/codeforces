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

    int n, m, w;
    cin >> n >> m >> w;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    auto bfs = [&](int x, int y) {
        auto check = [&](int x, int y) {
            return 0 <= x && x < n && 0 <= y && y < m && a[x][y] != -1;
        };

        static const int dx[]{-1, 0, 1, 0};
        static const int dy[]{0, 1, 0, -1};

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[x][y] = 0;
        vector<pair<int, int>> que{{x, y}};

        for (int ptr = 0; ptr < len(que); ptr++) {
            auto [x, y] = que[ptr];
            for (int d = 0; d < 4; d++) {
                int xx = x + dx[d];
                int yy = y + dy[d];
                if (check(xx, yy) && dist[xx][yy] > dist[x][y] + 1) {
                    dist[xx][yy] = dist[x][y] + 1;
                    que.emplace_back(xx, yy);
                }
            }
        }
        return dist;
    };

    auto dist = bfs(0, 0);
    ll answer = LLONG_MAX;
    if (dist[n - 1][m - 1] != INT_MAX)
        answer = 1ll * dist[n - 1][m - 1] * w;

    ll mn = LLONG_MAX;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] > 0 && dist[i][j] != INT_MAX)
                mn = min(mn, 1ll * dist[i][j] * w + a[i][j]);

    dist = bfs(n - 1, m - 1);
    if (mn != LLONG_MAX)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (a[i][j] > 0 && dist[i][j] != INT_MAX)
                    answer = min(answer, 1ll * dist[i][j] * w + a[i][j] + mn);

    if (answer == LLONG_MAX)
        answer = -1;

    cout << answer << '\n';
}