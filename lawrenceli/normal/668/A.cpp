#include <bits/stdc++.h>

using namespace std;

#define A first
#define B second

typedef pair<int, int> pii;

const int maxn = 105;

int n, m, q;
int mat[maxn][maxn];
pii ind[maxn][maxn];

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            ind[i][j] = pii(i, j);

    for (int i = 0; i < q; i++) {
        int t; cin >> t;
        if (t == 1) {
            int r; cin >> r;
            pii x = ind[r][1];
            for (int j = 2; j <= m; j++)
                ind[r][j - 1] = ind[r][j];
            ind[r][m] = x;
        } else if (t == 2) {
            int c; cin >> c;
            pii x = ind[1][c];
            for (int j = 2; j <= n; j++)
                ind[j - 1][c] = ind[j][c];
            ind[n][c] = x;
        } else {
            int r, c, x;
            cin >> r >> c >> x;
            pii p = ind[r][c];
            mat[p.A][p.B] = x;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            cout << mat[i][j] << ' ';
        cout << '\n';
    }
}