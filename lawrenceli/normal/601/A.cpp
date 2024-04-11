#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 405;

int n, m, mat[maxn][maxn];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        mat[a][b] = mat[b][a] = 1;
    }

    if (mat[0][n-1] == 1) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (i != j)
                    mat[i][j] = !mat[i][j];
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j && mat[i][j] == 0)
                mat[i][j] = 1e9;

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (i != k && j != k && i != j)
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
    
    if (mat[0][n-1] == 1e9) cout << "-1\n";
    else cout << mat[0][n-1] << '\n';
}