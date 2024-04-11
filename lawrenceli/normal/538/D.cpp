#include <bits/stdc++.h>
using namespace std;

const int MAXN = 55;

int n;
char mat[MAXN][MAXN], ans[2*MAXN][2*MAXN];

bool good(int dx, int dy) {
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            if (mat[i][j] == 'o') {
                int x = i+dx, y = j+dy;
                if (x>=0 && x<n && y>=0 && y<n && mat[x][y] == '.')
                    return 0;
            }
    return 1;
}

void cover(int dx, int dy) {
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            if (mat[i][j] == 'o') {
                int x = i+dx, y = j+dy;
                if (x>=0 && x<n && y>=0 && y<n && mat[x][y] == 'x')
                    mat[x][y] = '.';
            }
}

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=0; i<n; i++) cin >> mat[i];

    for (int dx=-(n-1); dx<=n-1; dx++)
        for (int dy=-(n-1); dy<=n-1; dy++)
            if (good(dx, dy)) ans[dx+n-1][dy+n-1] = 'x';
            else ans[dx+n-1][dy+n-1] = '.';
    ans[n-1][n-1] = 'o';

    for (int i=0; i<2*n-1; i++)
        for (int j=0; j<2*n-1; j++)
            if (ans[i][j] == 'x') cover(i-(n-1), j-(n-1));

    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            if (mat[i][j] == 'x') {
                cout << "NO";
                return 0;
            }

    cout << "YES\n";
    for (int i=0; i<2*n-1; i++) {
        for (int j=0; j<2*n-1; j++)
            cout << ans[i][j];
        cout << '\n';
    }
}