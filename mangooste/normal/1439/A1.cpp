#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

template<typename A, typename B> ostream& operator<<(ostream &out, pair<A, B> p) { return out << '(' << p.first << ", " << p.second << ')'; }
template<typename A, typename B = typename enable_if<!is_same<A, string>::value, typename A::value_type>::type> ostream& operator<<(ostream &out, A v) { out << '{'; string sep; for (const B &x : v) out << sep << x, sep = ", "; return out << '}'; }

void dbgPrint() { cerr << endl; }
template<typename A, typename... B> void dbgPrint(A a, B... b) { cerr << ' ' << a; dbgPrint(b...); }

#ifdef LOCAL
#define dbg(...) cerr << "line #" << __LINE__ << " [" << #__VA_ARGS__ << "]:", dbgPrint(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define sz(a) int(a.size())
#define all(a) (a).begin(), (a).end()

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        assert(n >= 2 && m >= 2);
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char c; cin >> c;
                grid[i][j] = c - '0';
            }
        }

        vector<vector<pair<int, int>>> ops;
        auto change = [&](vector<pair<int, int>> sq) {
            ops.push_back(sq);
            for (auto [x, y] : sq) grid[x][y] ^= 1;
        };
        for (int i = 0; i < n - 2; i++) {
            for (int j = m - 1; j > 1; j--) {
                if (grid[i][j]) change({ {i, j}, {i, j - 1}, {i + 1, j} });
            }
        }
        for (int j = m - 1; j > 1; j--) {
            if (grid[n - 2][j]) change({ {n - 2, j}, {n - 2, j - 1}, {n - 1, j - 1} });
            if (grid[n - 1][j]) change({ {n - 1, j}, {n - 2, j - 1}, {n - 1, j - 1} });
        }

        for (int i = n - 1; i > 1; i--) {
            if (grid[i][0]) change({ {i, 0}, {i - 1, 0}, {i - 1, 1} });
            if (grid[i][1]) change({ {i, 1}, {i - 1, 0}, {i - 1, 1} });
        }

        while (true) {
            vector<pair<int, int>> whereOnes;
            vector<pair<int, int>> whereZeroes;
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    if (grid[i][j]) {
                        whereOnes.emplace_back(i, j);
                    } else {
                        whereZeroes.emplace_back(i, j);
                    }
                }
            }
            if (sz(whereOnes) == 0) break;
            if (sz(whereOnes) == 4) {
                change({ whereOnes[0], whereOnes[1], whereOnes[2] });
                continue;
            }
            if (sz(whereOnes) == 3) {
                change(whereOnes);
                continue;
            }
            if (sz(whereOnes) == 2) {
                change({ whereOnes[0], whereZeroes[0], whereZeroes[1] });
                continue;
            }
            assert(sz(whereOnes) == 1);
            change({ whereOnes[0], whereZeroes[0], whereZeroes[1] });
        }

        assert(sz(ops) <= n * m);
        cout << sz(ops) << '\n';
        for (auto &xs : ops) {
            assert(sz(xs) == 3);
            for (auto [x, y] : xs) cout << x + 1 << ' ' << y + 1 << ' ';
            cout << '\n';
        }
    }
}