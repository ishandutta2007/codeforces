
#include <bits/stdc++.h>

#define ll long long
using namespace std;

// try every subset of songs
// check that sum(t[i]) = T
// count number of orderings that avoid consecutive genres
// only depends on counts of the three genres
// precompute with DP
// DP[i][j][k][l] = number of ways if i of genre 1, j of genre 2, k of genre 3, and last song must be genre l.

const int N = 16, TT = 225, M = 1e9 + 7;
int n, T, t[N], g[N];
ll dp[N][N][N][3];

ll fact(ll x) {
    ll ans = 1;
    for(int i = 1; i <= x; i++) {
        ans *= i;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> T;
    for(int i = 0; i < n; i++) {
        cin >> t[i] >> g[i];
        g[i]--;
    }
    for(int l = 0; l < 3; l++) dp[0][0][0][l] = 1;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            for(int k = 0; k <= n; k++) {
                if(i != 0) {
                    if(j == 0 && k == 0) {
                        if(i == 1) dp[i][j][k][0] = 1;
                    }else dp[i][j][k][0] = (dp[i - 1][j][k][1] + dp[i - 1][j][k][2]) % M;
                }
                if(j != 0) {
                    if(i == 0 && k == 0) {
                        if(j == 1) dp[i][j][k][1] = 1;
                    }else dp[i][j][k][1] = (dp[i][j - 1][k][0] + dp[i][j - 1][k][2]) % M;
                }
                if(k != 0) {
                    if(i == 0 && j == 0) {
                        if(k == 1) dp[i][j][k][2] = 1;
                    }else dp[i][j][k][2] = (dp[i][j][k - 1][0] + dp[i][j][k - 1][1]) % M;
                }
            }
        }
    }
    ll ans = 0;
    for(int mask = 0; mask < (1 << n); mask++) {
        int sum = 0;
        vector<int> v(3, 0);
        for(int i = 0; i < n; i++) {
            if((mask >> i) & 1) {
                sum += t[i];
                v[g[i]]++;
            }
        }
        if(sum != T) continue;
        // (v[0] + v[1] + v[2])! / (v[0]! v[1]! v[2]!)
        ll m = (((fact(v[0]) * fact(v[1])) % M) * fact(v[2])) % M;
        for(int i = 0; i < 3; i++) {
            ans = (ans + m * dp[v[0]][v[1]][v[2]][i]) % M;
        }
    }
    cout << ans << endl;
}