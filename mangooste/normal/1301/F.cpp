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

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto &vec : a)
        for (auto &x : vec)
            cin >> x, x--;

    auto check_cell = [&](int x, int y) {
        return 0 <= x && x < n && 0 <= y && y < m;
    };

    const int INF = n * m;
    vector<vector<vector<int>>> dist(k, vector<vector<int>>(n, vector<int>(m, INF)));

    for (int color = 0; color < k; color++) {
        vector<pair<int, int>> que;
        que.reserve(n * m);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (a[i][j] == color) {
                    dist[color][i][j] = 0;
                    que.emplace_back(i, j);
                }

        const vector<int> dx{-1, 0, 1, 0};
        const vector<int> dy{0, 1, 0, -1};

        for (int ptr = 0; ptr < len(que); ptr++) {
            const auto &[x, y] = que[ptr];
            for (int d = 0; d < 4; d++) {
                int new_x = x + dx[d];
                int new_y = y + dy[d];
                if (check_cell(new_x, new_y) && dist[color][new_x][new_y] > dist[color][x][y] + 1) {
                    dist[color][new_x][new_y] = dist[color][x][y] + 1;
                    que.emplace_back(new_x, new_y);
                }
            }
        }
    }

    vector<vector<int>> jumps(k, vector<int>(k, INF));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int color = 0; color < k; color++) {
                jumps[a[i][j]][color] = min(jumps[a[i][j]][color], dist[color][i][j] + 1);
                jumps[color][a[i][j]] = min(jumps[color][a[i][j]], dist[color][i][j] + 1);
            }

    for (int m = 0; m < k; m++)
        for (int v = 0; v < k; v++)
            for (int u = 0; u < k; u++)
                jumps[v][u] = min(jumps[v][u], jumps[v][m] + jumps[m][u]);

    int q;
    cin >> q;
    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--, y1--, x2--, y2--;

        int answer = abs(x1 - x2) + abs(y1 - y2);
        for (int first = 0; first < k; first++)
            for (int second = 0; second < k; second++)
                answer = min(answer, dist[first][x1][y1] + dist[second][x2][y2] + 1 + jumps[first][second]);

        for (int color = 0; color < k; color++)
            answer = min(answer, dist[color][x1][y1] + dist[color][x2][y2] + 1);

        cout << answer << '\n';
    }
}