#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 51, inf = 1000111222;

char f[max_n][max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> f[i][j];
        }
    }

    for (int si = 0; si < n - 1; ++si) {
        for (int sj = 0; sj < m - 1; ++sj) {
            for (int fi = si + 1; fi < n; ++fi) {
                for (int fj = sj + 1; fj < m; ++fj) {
                    if (f[si][sj] == '#' && f[fi][fj] == '#' && f[si][fj] == '#' && f[fi][sj] == '.') {
                        cout << "No";
                        return 0;
                    }
                    if (f[si][sj] == '#' && f[fi][fj] == '#' && f[si][fj] == '.' && f[fi][sj] == '#') {
                        cout << "No";
                        return 0;
                    }
                    if (f[si][sj] == '.' && f[fi][fj] == '#' && f[si][fj] == '#' && f[fi][sj] == '#') {
                        cout << "No";
                        return 0;
                    }
                    if (f[si][sj] == '#' && f[fi][fj] == '.' && f[si][fj] == '#' && f[fi][sj] == '#') {
                        cout << "No";
                        return 0;
                    }
                }
            }
        }
    }
    cout << "Yes";
    return 0;
}