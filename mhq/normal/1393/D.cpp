#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2005;
int n, m;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char c[maxN][maxN];
int val[maxN][maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> c[i][j];
            val[i][j] = n + m + 20;
        }
    }
    for (int a = -1; a <= 1; a += 2) {
        for (int b = -1; b <= 1; b += 2) {
            int stn = (a == 1 ? 1 : n);
            int stm = (b == 1 ? 1 : m);
            for (int i = stn; (1 <= i && i <= n); i += a) {
                for (int j = stm; (1 <= j && j <= m); j += b) {
                    for (int k = 0; k < 4; k++) {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if (nx < 1 || nx > n || ny < 1 || ny > m || c[nx][ny] != c[i][j]) {
                            val[i][j] = 1;
                            break;
                        }
                        else {
                            val[i][j] = min(val[i][j], val[nx][ny] + 1);
                        }

                    }
                }
            }
        }
    }
    for (int a = -1; a <= 1; a += 2) {
        for (int b = -1; b <= 1; b += 2) {
            int stn = (a == 1 ? 1 : n);
            int stm = (b == 1 ? 1 : m);
            for (int j = stm; (1 <= j && j <= m); j += b) {
                for (int i = stn; (1 <= i && i <= n); i += a) {
                    for (int k = 0; k < 4; k++) {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if (nx < 1 || nx > n || ny < 1 || ny > m || c[nx][ny] != c[i][j]) {
                            val[i][j] = 1;
                            break;
                        }
                        else {
                            val[i][j] = min(val[i][j], val[nx][ny] + 1);
                        }
                    }
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ans += val[i][j];
        }
    }
    cout << ans;
    return 0;
}