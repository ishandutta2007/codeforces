#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <ios>

using namespace std;

const int maxn = 505;

int n, m;
char mat[maxn][maxn];
int p[maxn][maxn], q[maxn][maxn];

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];
    
    for (int i = 0; i < n; i++)
        for (int j = 1; j < m; j++) {
            if (mat[i][j-1] == '.' && mat[i][j] == '.')
                p[i][j] = p[i][j-1] + 1;
            else p[i][j] = p[i][j-1];
        }

    for (int j = 0; j < m; j++)
        for (int i = 1; i < n; i++) {
            if (mat[i-1][j] == '.' && mat[i][j] == '.')
                q[i][j] = q[i-1][j] + 1;
            else q[i][j] = q[i-1][j];
        }

    int k; cin >> k;
    for (int i = 0; i < k; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1--, c1--, r2--, c2--;
        int ans = 0;
        for (int j = r1; j <= r2; j++)
            ans += p[j][c2] - p[j][c1];
        for (int j = c1; j <= c2; j++)
            ans += q[r2][j] - q[r1][j];
        cout << ans << '\n';
    }
}