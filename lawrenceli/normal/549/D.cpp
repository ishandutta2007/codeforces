#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;

int n, m;
int mat[MAXN][MAXN];

//print matrix
void print() {
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) cout << mat[i][j];
        cout << endl;
    }
}

void upd(int r, int c) {
    int num = mat[r][c];
    for (int i=0; i<=r; i++)
        for (int j=0; j<=c; j++)
            mat[i][j] -= num;
}

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++) {
            char c; cin >> c;
            mat[i][j] = c == 'B' ? 1 : 0;
        }

    int r = n-1, c = m-1, ans = 1;
    if (mat[r][c]) upd(r, c);

    while (r && c) {
        if (mat[r][c]) upd(r, c), ans++;
        for (int i=r-1; i>=0; i--)
            if (mat[i][c]) upd(i, c), ans++;
        for (int i=c-1; i>=0; i--)
            if (mat[r][i]) upd(r, i), ans++;
        r--, c--;
    }

    while (r || c) {
        if (mat[r][c]) upd(r, c), ans++;
        if (r) r--;
        if (c) c--;
    }

    if (mat[0][0]) ans++;
    cout << ans;
}