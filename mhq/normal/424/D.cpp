#include <bits/stdc++.h>
using namespace std;
int n, m;
int tp, tu, td;
int t;
const int maxN = 305;
int r[maxN][maxN][2];
int c[maxN][maxN][2];
int a[maxN][maxN];
int ans(int i1, int i2, int j1, int j2) {
    int check = 0;
    check += r[i1][j2][0] - r[i1][j1][0];
    check += r[i2][j1][1] - r[i2][j2][1];
    check += c[i2][j2][0] - c[i1][j2][0];
    check += c[i1][j1][1] - c[i2][j1][1];
    return check;
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("log.in", "r", stdin);
    //freopen("log.out", "w", stdout);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m >> t;
    cin >> tp >> tu >> td;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 2; j <= m; j++) {
            r[i][j][0] = r[i][j - 1][0];
            if (a[i][j] > a[i][j - 1]) r[i][j][0] += tu;
            else if (a[i][j] < a[i][j - 1]) r[i][j][0] += td;
            else r[i][j][0] += tp;
        }
        for (int j = m - 1; j >= 1; j--) {
            r[i][j][1] = r[i][j + 1][1];
            if (a[i][j] > a[i][j + 1]) r[i][j][1] += tu;
            else if (a[i][j] < a[i][j + 1]) r[i][j][1] += td;
            else r[i][j][1] += tp;
        }
    }
    for (int j = 1; j <= m; j++) {
        for (int i = 2; i <= n; i++) {
            c[i][j][0] = c[i - 1][j][0];
            if (a[i][j] > a[i - 1][j]) c[i][j][0] += tu;
            else if (a[i][j] < a[i - 1][j]) c[i][j][0] += td;
            else c[i][j][0] += tp;
        }
    }
    for (int j = 1; j <= m; j++) {
        for (int i = n - 1; i >= 1; i--) {
            c[i][j][1] = c[i + 1][j][1];
            if (a[i][j] < a[i + 1][j]) c[i][j][1] += td;
            else if (a[i][j] > a[i + 1][j]) c[i][j][1] += tu;
            else c[i][j][1] += tp;
        }
    }
    int mn = (int)1e9;
    int fr, sr, fc, sc;
    for (int i1 = 1; i1 <= n; i1++) {
        for (int i2 = i1 + 2; i2 <= n; i2++) {
            set < pair < int, int > > s;
            for (int j = m - 2; j >= 1; j--) {
                int x = r[i1][j + 2][0] - r[i2][j + 2][1] + c[i2][j + 2][0] - c[i1][j + 2][0];
                s.insert(make_pair(x, j + 2));
                int y = -r[i1][j][0] + r[i2][j][1] + c[i1][j][1] - c[i2][j][1];
                auto it = s.lower_bound(make_pair(t - y, -1));
                if (it != s.end()) {
                    int p = (*it).first;
                    if (mn > abs(t - p - y)) {
                        mn = abs(t - p - y);
                        fr = i1;
                        sr = i2;
                        fc = j;
                        sc = (*it).second;
                    }
                }
                if (it != s.begin()) {
                    it--;
                    int p = (*it).first;
                    if (mn > abs(t - p - y)) {
                        mn = abs(t - p - y);
                        fr = i1;
                        sr = i2;
                        fc = j;
                        sc = (*it).second;
                    }
                }
            }
        }
    }
    cout << fr << " " << fc << " " << sr << " " << sc;
    return 0;
}