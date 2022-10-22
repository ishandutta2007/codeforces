#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

void upd(int& x, int y) {
    if (x > y)
        x = y;
}

vector<vector<int>> fast(int n, int m, int k, vector<vector<int>> R, vector<vector<int>> D) {
    vector<vector<int>> res(n + 1, vector<int>(m + 1, -1));
    if (k % 2)
        return res;

    int k2 = k / 2;

    auto check = [&](int i, int j) -> bool {
        return 1 <= i && i <= n && 1 <= j && j <= m;
    };

    vector<pii> MOVES = {{-1, 0}, {+1, 0}, {0, -1}, {0, +1}};

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1, inf)));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j][0] = 0;
        }
    }
    for (int c = 0; c < k; c += 2) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                for (auto [xi, xj] : MOVES) {
                    int ui = i + xi;
                    int uj = j + xj;
                    if (!check(ui, uj))
                        continue;
                    int w;
                    if (xi == -1) w = D[ui][uj];
                    else if (xi == +1) w = D[i][j];
                    else if (xj == -1) w = R[ui][uj];
                    else w = R[i][j];
                    upd(dp[i][j][c + 2], dp[ui][uj][c] + 2 * w);
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            res[i][j] = dp[i][j][k];
        }
    }

    return res;
}

void work() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> R(n + 1, vector<int>(m + 1)), D(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < m; j++) {
            cin >> R[i][j];
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> D[i][j];
        }
    }
    vector<vector<int>> fs = fast(n, m, k, R, D);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << fs[i][j] << " ";
        }
        cout << "\n";
    }
}

void test() {
    const int MAXX = 1e6;
    int n = 500;
    int m = 500;
    int k = 20;
    mt19937 rnd(time(NULL));
    vector<vector<int>> R(n + 1, vector<int>(m + 1)), D(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < m; j++) {
            R[i][j] = rnd() % MAXX + 1;
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            D[i][j] = rnd() % MAXX + 1;
        }
    }
    vector<vector<int>> fs = fast(n, m, k, R, D);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << fs[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

#ifdef MAX_TEST
    test();
#else
    work();
#endif

    return 0;
}