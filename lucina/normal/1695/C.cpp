#include<bits/stdc++.h>
using namespace std;
const int nax = 1024;
int n, m;
int a[nax][nax];
int dp_min[nax][nax];
int dp_max[nax][nax];

bool solve() {
    cin >> n >> m;
    for (int i = 1 ; i <= n;  ++ i)
    for (int j = 1 ; j <= m ; ++ j) {
        cin >> a[i][j];
        if (j == 1) {
            dp_max[i][j] = dp_max[i - 1][j] + a[i][j];
            dp_min[i][j] = dp_min[i - 1][j] + a[i][j];
            continue;
        }
        if (i == 1) {
            dp_max[i][j] = dp_max[i][j - 1] + a[i][j];
            dp_min[i][j] = dp_min[i][j - 1] + a[i][j];
            continue;
        }
        dp_max[i][j] = max(dp_max[i][j - 1],dp_max[i - 1][j]) + a[i][j];
        dp_min[i][j] = min(dp_min[i][j - 1],dp_min[i - 1][j]) + a[i][j];
    }

    if (dp_min[n][m] % 2) return false;
    return dp_max[n][m] >= 0 && dp_min[n][m] <= 0;



}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        cout << (solve() ? "YES" : "NO") << '\n';
    }
}