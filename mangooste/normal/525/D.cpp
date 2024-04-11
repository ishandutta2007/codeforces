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
    cin >> n >> m >> ws;
    vector<string> a(n);
    for (auto &s : a)
        getline(cin, s);

    if (n == 1 || m == 1) {
        for (const auto s : a)
            cout << s << '\n';

        return 0;
    }

    static const int dx[]{-1, 0, 1, 0};
    static const int dy[]{0, 1, 0, -1};
    vector<vector<char>> used(n, vector<char>(m));

    auto check = [&](int x, int y) {
        return 0 <= x && x < n && 0 <= y && y < m;
    };

    auto is_bad = [&](int x, int y) {
        if (!check(x, y) || a[x][y] == '.' || used[x][y])
            return false;

        for (int d = 0; d < 4; d++) {
            int x1 = x + dx[d], y1 = y + dy[d];
            int x2 = x + dx[(d + 1) & 3], y2 = y + dy[(d + 1) & 3];
            if (!check(x1, y1) || !check(x2, y2))
                continue;

            int x3 = x + dx[d] + dx[(d + 1) & 3], y3 = y + dy[d] + dy[(d + 1) & 3];
            assert(check(x3, y3));
            if (a[x1][y1] == '.' && a[x2][y2] == '.' && a[x3][y3] == '.')
                return true;
        }
        return false;
    };

    vector<pair<int, int>> que;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (is_bad(i, j)) {
                used[i][j] = 1;
                que.emplace_back(i, j);
            }

    for (int st = 0; st < len(que); st++) {
        const auto [x, y] = que[st];
        a[x][y] = '.';
        for (int d = 0; d < 4; d++) {
            int xx = x + dx[d], yy = y + dy[d];
            if (is_bad(xx, yy)) {
                used[xx][yy] = 1;
                que.emplace_back(xx, yy);
            }

            xx += dx[(d + 1) & 3];
            yy += dy[(d + 1) & 3];
            if (is_bad(xx, yy)) {
                used[xx][yy] = 1;
                que.emplace_back(xx, yy);
            }
        }
    }

    for (const auto s : a)
        cout << s << '\n';
}