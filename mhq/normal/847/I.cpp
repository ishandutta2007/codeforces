#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
pair<pair<int, int>, int> o[500000];
int n, m, q, p;
int a[252][252];
int used[252][252];
int d[252][252];
long long calc [252][252];

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> q >> p;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == '.') a[i][j + 1] = 0;
            else
            if (s[j] == '*') a[i][j + 1] = -1;
            else a[i][j + 1] = s[j] - 'A' + 1;
        }
    }
    for (int xn = 1; xn <= n; xn++)
    for (int yn = 1; yn <= m; yn++)
        if (a[xn][yn] >= 1) {
            int sz = 0;
            int l = 1;

            sz++;
            o[sz] = make_pair(make_pair(xn, yn), 0);
            d[xn][yn] = q * a[xn][yn];
            used[xn][yn] = 1;
            while (l <= sz) {
                int x = o[l].first.first;
                int y = o[l].first.second;
                int h = o[l].second;
                if (d[x][y] < 2) break;
                for (int dx = -1; dx <= 1; dx++)
                for (int dy = -1; dy <= 1; dy++) {
                    if (abs(dx + dy) != 1) continue;
                    if (x + dx == 0) continue;
                    if (x + dx > n) continue;
                    if (y + dy == 0) continue;
                    if (y + dy > m) continue;
                    if (a[x + dx][y + dy] == -1) continue;
                    if (used[x + dx][y + dy] == 1) continue;
                    d[x + dx][y + dy] = d[x][y] / 2;
                    used[x + dx][y + dy] = 1;
                    sz++;
                    o[sz] = make_pair(make_pair(x + dx, y + dy), h + 1);
                }
                l++;
            }
            for (; sz >= 1; sz--) {
                int x = o[sz].first.first;
                int y = o[sz].first.second;
                int h = o[sz].second;
                calc[x][y] += d[x][y];
                d[x][y] = 0;
                used[x][y] = 0;
            }
        }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
        if (calc[i][j] > p) ans++;
    cout << ans << "\n";
    return 0;
}