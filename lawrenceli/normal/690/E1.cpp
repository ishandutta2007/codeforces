#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 605;

int q, n, m;
int mat[maxn][maxn];

ll sq(int x) { return x * x; }

int main() {
    ios_base::sync_with_stdio(0);
    cin >> q;
    for (int ii = 0; ii < q; ii++) {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];

        ll c1 = 0, c2 = 0;
        for (int i = 0; i < m; i++) {
            c1 += sq(mat[n / 2 - 1][i] - mat[n / 2][i]);
            c2 += sq(mat[0][i] - mat[n - 1][i]);
        }

        if (c1 < c2) cout << "NO\n";
        else cout << "YES\n";
    }
}