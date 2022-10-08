
#include <bits/stdc++.h>

using namespace std;

const int M = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    if(n < m) swap(n, m);
    
    vector<vector<long long>> choose(n + m, vector<long long>(n));
    for(int i = 0; i < n + m; i++) {
        for(int j = 0; j < n; j++) {
            if(j == 0) choose[i][j] = 1;
            else if(i == 0) choose[i][j] = 0;
            else choose[i][j] = (choose[i - 1][j] + choose[i - 1][j - 1]) % M;
        }
    }
    long long ans = 0;
    for(int r = 1; r < n; r++) {
        long long F = 0;
        for(int c = m - 1; c >= 1; c--) {
            F = (F + choose[n - r + m - c - 1][n - r] * choose[c + n - r - 1][n - r - 1]) % M;
            ans = (ans + choose[r + c - 1][r] * ((choose[m - c + r - 1][r - 1] * F) % M)) % M;
        }
    }

    swap(n, m);
    for(int r = 1; r < n; r++) {
        long long F = 0;
        for(int c = m - 1; c >= 1; c--) {
            ans = (ans + choose[r + c - 1][r] * ((choose[m - c + r - 1][r - 1] * F) % M)) % M;
            F = (F + choose[n - r + m - c - 1][n - r] * choose[c + n - r - 1][n - r - 1]) % M;
        }
    }
    ans = (2 * ans) % M;
    cout << ans << '\n';
}