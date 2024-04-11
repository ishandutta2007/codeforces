#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1005;

int n[4], m[4], q;
int mat[4][MAXN][MAXN], len[4][MAXN][MAXN];

void init(int i, int r) {
    len[i][r][0] = 0;
    for (int c=1; c<=m[i]; c++) {
        if (mat[i][r][c]) len[i][r][c] = len[i][r][c-1]+1;
        else len[i][r][c] = 0;
    }
}

void upd(int i, int x, int y) {
    mat[i][x][y] ^= 1;
    init(i, x);
}

int mi[MAXN];

int qry(int i, int x, int y) {
    mi[x] = len[i][x][y];
    for (int r=x-1; r>0; r--) mi[r] = min(len[i][r][y], mi[r+1]);
    for (int r=x+1; r<=n[i]; r++) mi[r] = min(len[i][r][y], mi[r-1]);
    int ret = 0, lt = 1, rt = n[i];
    for (int l=1; l<=m[i]; l++) {
        while (lt <= x && mi[lt] < l) lt++;
        while (rt >= x && mi[rt] < l) rt--;
        ret = max(ret, l*(rt-lt+1));
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n[0] >> m[0] >> q;
    for (int i=1; i<=n[0]; i++)
        for (int j=1; j<=m[0]; j++)
            cin >> mat[0][i][j];

    for (int i=1; i<4; i++) {
        n[i] = m[i-1], m[i] = n[i-1];
        for (int r=1; r<=n[i-1]; r++)
            for (int c=1; c<=m[i-1]; c++)
                mat[i][c][n[i-1]-r+1] = mat[i-1][r][c];
    }

    for (int i=0; i<4; i++)
        for (int r=1; r<=n[i]; r++)
            init(i, r);

    for (int i=0; i<q; i++) {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1) {
            for (int j=0; j<4; j++) {
                upd(j, x, y);
                int nx = y, ny = n[j]-x+1;
                x = nx, y = ny;
            }
        } else {
            int ans = 0;
            for (int j=0; j<4; j++) {
                ans = max(ans, qry(j, x, y));
                int nx = y, ny = n[j]-x+1;
                x = nx, y = ny;
            }
            cout << ans << '\n';
        }
    }
    return 0;
}