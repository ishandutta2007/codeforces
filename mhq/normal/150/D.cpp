#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 155;
int n;
int a[maxN];
int pal[maxN][maxN][maxN];
int best[maxN][maxN];
int full[maxN][maxN];
char c[maxN];
const int INF = (int)1e9;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            best[i][j] = 0;
            full[i][j] = -INF;
            for (int k = 1; k <= n; k++) {
                pal[i][j][k] = -INF;
            }
        }
    }
    for (int cur = 1; cur <= n; cur++) {
         for (int l = 1; l + cur - 1 <= n; l++) {
             int r = l + cur - 1;
             if (l == r) {
                 pal[1][l][r] = 0;
             }
             else {
                 if (l != r && c[l] == c[r]) {
                     if (l + 1 == r) pal[2][l][r] = 0;
                     else pal[2][l][r] = full[l + 1][r - 1];
                 }
             }
             for (int len = 1; len <= cur; len++) {
                 for (int ri = r - 1; ri >= l + len - 1; ri--) {
                     pal[len][l][r] = max(pal[len][l][r], pal[len][l][ri] + full[ri + 1][r]);
                 }
                 for (int le = l + 1; le <= r - len + 1; le++) {
                     pal[len][l][r] = max(pal[len][l][r], pal[len][le][r] + full[l][le - 1]);
                 }
                 if (len >= 3 && c[l] == c[r] && (l + 1 <= r - 1)) {
                     pal[len][l][r] = max(pal[len][l][r], pal[len - 2][l + 1][r - 1]);
                 }
             }
             for (int len = 1; len <= cur; len++) {
                 if (a[len] != -1) full[l][r] = max(full[l][r], pal[len][l][r] + a[len]);
             }
             best[l][r] = max(best[l][r], full[l][r]);
             for (int cut = l; cut <= r; cut++) {
                 int cur_val = 0;
                 if (cut != l) cur_val += best[l][cut - 1];
                 if (cut != r) cur_val += best[cut + 1][r];
                 best[l][r] = max(best[l][r], cur_val);
             }
         }
    }
    cout << best[1][n];
    return 0;
}