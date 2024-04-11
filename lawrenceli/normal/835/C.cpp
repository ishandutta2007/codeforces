#include <bits/stdc++.h>

using namespace std;

const int maxn = 100100;

int n, q, c;
int x[maxn], y[maxn], s[maxn];
int pre[11][105][105];
int mat[105][105];

void compute(int t) {
    memset(mat, 0, sizeof(mat));
    for (int i = 0; i < n; i++) mat[x[i]][y[i]] += s[i];
    for (int i = 1; i <= 100; i++)
        for (int j = 1; j <= 100; j++)
            pre[t][i][j] = pre[t][i - 1][j] + pre[t][i][j - 1] - pre[t][i - 1][j - 1] + mat[i][j];
}

int main() {
    ios_base::sync_with_stdio(0);
    
    cin >> n >> q >> c;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> s[i];
    }

    for (int t = 0; t <= c; t++) {
        compute(t);
        for (int i = 0; i < n; i++)
            s[i] = (s[i] + 1) % (c + 1);
    }

    for (int i = 0; i < q; i++) {
        int t, x1, y1, x2, y2;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        t %= (c + 1);
        cout << pre[t][x2][y2] - pre[t][x2][y1 - 1] - pre[t][x1 - 1][y2] + pre[t][x1 - 1][y1 - 1] << '\n';
    }
}