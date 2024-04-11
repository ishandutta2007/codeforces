#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = 500;
const int mod = (int)1e9 + 7;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1));
    int res = pw(a, b / 2);
    return mult(res, res);
}
int inv(int a) {
    return pw(a, mod - 2);
}
bool edge[maxN][maxN];
bool used[maxN];
void add(int x, int y) {
    edge[x][y] = true;
    edge[y][x] = true;
}
int a[maxN][maxN];
void solve() {
    int n, m;
    cin >> n >> m;
    int num = 2 * n + m;
    memset(edge, 0, sizeof edge);
    for (int i = 0; i < n; i++) {
        add(2 * i, 2 * i + 1);
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == '1') {
                add(2 * i, 2 * n + j);
                add(2 * i + 1, 2 * n + j);
            }
        }
    }
    int val = 0;
    for (int iter = 0; iter < 10; iter++) {
        memset(used, 0, sizeof used);
        for (int i = 0; i < num; i++) {
            for (int j = i; j < num; j++) {
                if (!edge[i][j]) {
                    a[i][j] = 0;
                    a[j][i] = 0;
                }
                else {
                    int res = (rand() | (rand() << 10)) % mod;
                    a[i][j] = res;
                    a[j][i] = sub(0, res);
                }
            }
        }
        int cur = 0;
        for (int i = 0; i < num; i++) {
            int ind = -1;
            for (int j = 0; j < num; j++) {
                if (used[j]) continue;
                if (a[j][i] != 0) {
                    ind = j;
                    break;
                }
            }
            if (ind == -1) {
                continue;
            }
            used[ind] = true;
            cur++;
            int inv_a = inv(a[ind][i]);
            for (int row = 0; row < num; row++) {
                if (used[row]) continue;
                int coef = mult(inv_a, a[row][i]);
                for (int col = 0; col < num; col++) {
                    a[row][col] = sub(a[row][col], mult(coef, a[ind][col]));
                }
            }
        }
        val = max(val, cur / 2);
    }
    cout << val - n << '\n';
}
int main() {
    //freopen("input.txt", "r", stdin);
    srand(239);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tst;
    cin >> tst;
    while (tst--) {
        solve();
    }
    return 0;
}