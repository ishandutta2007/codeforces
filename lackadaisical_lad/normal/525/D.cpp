#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;
// const int MOD = 998244353;
 
ll binpow(ll a, ll p, int mod = MOD) {
    ll res = 1;
    a %= mod;
    while (p) {
        if (p & 1) {
            (res *= a) %= mod;
        }
        p >>= 1;
        (a *= a) %= mod;
    }
    return res;
}
 
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> field(n);
    for (int i = 0; i < n; i++) {
        cin >> field[i];
    }
    vector<vector<int>> used(n, vector<int>(m));
    vector<int> dx{0, 1, 0, 1};
    vector<int> dy{0, 0, 1, 1};
    vector<int> rx{-1, -1, 0, 0};
    vector<int> ry{-1, 0, -1, 0};

    auto in_field = [&](int i, int j) {
        return i >= 0 && i < n && j >= 0 && j < m;
    };

    auto check = [&](int i, int j) {
        if (!in_field(i, j) || field[i][j] != '*' || used[i][j]) return false;
        for (int r = 0; r < 4; r++) {
            int x = i + rx[r];
            int y = j + ry[r];
            if (!in_field(i, j)) continue;
            int star = 0;
            int cnt = 0;
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (in_field(nx, ny)) {
                    cnt++;
                    star += field[nx][ny] == '*';
                }
            }
            if (cnt == 4 && star == 1) {
                return true;
            }
        }
        return false;
    };

    vector<int> qx{-1, -1, -1, 0, 0, 1, 1, 1};
    vector<int> qy{-1, 0, 1, -1, 1, -1, 0, 1};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!check(i, j)) continue;
            field[i][j] = '.';
            queue<pair<int, int>> q;
            used[i][j] = 1;
            q.push({i, j});
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                for (int d = 0; d < 8; d++) {
                    int nx = x + qx[d];
                    int ny = y + qy[d];
                    if (check(nx, ny)) {
                        used[nx][ny] = 1;
                        field[nx][ny] = '.';
                        q.push({nx, ny});
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << field[i] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case #" << tc << ": ";  
        solve();
    }
    return 0;
}