#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
ll all = 0;
const int maxN = 15;
vector < pair < int, int > > g[maxN][maxN];
bool used[maxN][maxN];
pair < int, int > mt[maxN][maxN];
bool kuhn(int a, int b) {
    if (used[a][b]) return false;
    used[a][b] = true;
    for (auto t : g[a][b]) {
        int x = t.first;
        int y = t.second;
        if (((mt[x][y] == make_pair(-1, -1)) || kuhn(mt[x][y].first, mt[x][y].second))) {
            mt[x][y] = make_pair(a, b);
            return true;
        }
    }
    return false;
}
void solve_stupid() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if ((i + j) & 1) continue;
            for (int x = 1; x <= n; x++) {
                for (int y = 1; y <= m; y++) {
                    if ((abs(x - i) + abs(y - j)) == 3) {
                        //cout << i << " " << j << " " << x << " " << y << endl;
                        g[i][j].emplace_back(make_pair(x, y));
                    }
                }
            }
        }
    }
    memset(used, -1, sizeof used);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            mt[i][j] = make_pair(-1, -1);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if ((i + j) & 1) continue;
            memset(used, 0, sizeof used);
            kuhn(i, j);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mt[i][j] != make_pair(-1, -1)) {
                ans++;
            }
        }
    }
    cout << 2 * ans;
    exit(0);
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    all = 1LL * n * m;
    if (n > m) swap(n, m);
    if (n == 1) {
        if (m % 6 <= 3) cout << all - (m % 6);
        else {
            if (m % 6 == 4) cout << all - 2;
            else if (m % 6 == 5) cout << all - 1;
        }
        return 0;
    }
    if (n <= 10 && m <= 10) solve_stupid();
    if (all % 2 == 0) cout << all;
    else cout << all - 1;
    return 0;
}