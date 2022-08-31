#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = 2005;
int n, k;
char a[maxN][maxN];
int f[maxN][maxN];
bool ok[maxN][maxN];
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    if (a[1][1] == 'a') f[1][1] = 0;
    else f[1][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 && j == 1) continue;
            f[i][j] = maxN * maxN;
            if (i > 1) f[i][j] = min(f[i - 1][j], f[i][j]);
            if (j > 1) f[i][j] = min(f[i][j - 1], f[i][j]);
            if (a[i][j] != 'a') f[i][j]++;
        }
    }
    if (f[n][n] <= k) {
        for (int i = 1; i <= 2 * n - 1; i++) cout << 'a';
        return 0;
    }
    int best = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (f[i][j] <= k) {
                best = max(best, i + j);
            }
        }
    }
    string cur_ans = "";
    for (int i = 2; i <= best; i++) {
        cur_ans += 'a';
    }
    vector < pair < int, int > > pos;
    if (best == 0) {
        cur_ans += a[1][1];
        best = 2;
    }
    for (int i = 1; i <= n; i++) {
        int j = best - i;
        if (j >= 1 && j <= n) {
            if (f[i][j] <= k || (best == 2)) {
                ok[i][j] = true;
                pos.emplace_back(i, j);
            }
        }
    }
    for (int sum = best; sum + 1 <= 2 * n; sum++) {
        char opt_symb = 'z';
        for (auto t : pos) {
            int x = t.first;
            int y = t.second;
            if (x + 1 <= n) {
                opt_symb = min(opt_symb, a[x + 1][y]);
            }
            if (y + 1 <= n) {
                opt_symb = min(opt_symb, a[x][y + 1]);
            }
        }
        cur_ans += opt_symb;
        vector < pair < int, int > > npos;
        for (auto t : pos) {
            int x = t.first;
            int y = t.second;
            if (x + 1 <= n && !ok[x + 1][y]) {
                if (a[x + 1][y] == opt_symb) {
                    ok[x + 1][y] = true;
                    npos.emplace_back(x + 1, y);
                }
            }
            if (y + 1 <= n && !ok[x][y + 1]) {
                if (ok[x][y + 1]) continue;
                if (a[x][y + 1] == opt_symb) {
                    ok[x][y + 1] = true;
                    npos.emplace_back(x, y + 1);
                }
            }
        }
        pos = npos;
    }
    cout << cur_ans;
}