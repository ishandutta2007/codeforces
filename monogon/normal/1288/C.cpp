
#include <bits/stdc++.h>

#define ll long long
using namespace std;

// how many nondecreasing arrays of length m with values
// from 1 to n s.t. the last value is at most n?
// f[m][n] = sum_{i = 1}^n f[m - 1][i].
// f[0][n] = 1.
// f[m][0] = 0 for m >= 1.

// Then f[m][n - 1] = sum_{i = 1}^{n - 1} f[m - 1][i]
// f[m][n] = f[m][n - 1] + f[m - 1][n]

// Iterate over all possible final values k of a[m].
// Possibilities for a: f[m - 1][k].
// Possibilities for b: f[m][n - k + 1].

const int N = 1005, M = 1'000'000'007;
int n, m;
ll f[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i <= n; i++) {
        f[0][i] = 1;
    }
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            f[i][j] = (f[i - 1][j] + f[i][j - 1]) % M;
        }
    }
    ll ans = 0;
    for(int k = 1; k <= n; k++) {
        ans = (ans + f[m - 1][k] * f[m][n - k + 1]) % M;
    }
    cout << ans << endl;
}