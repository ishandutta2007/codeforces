#include<bits/stdc++.h>
#define X first
#define Y second
#define int long long
#define sz(a) (int)a.size()
using namespace std;
const int N = 500;
const int mod = 1e9 + 7;
int cnk[N][N];
int dp[N / 2][N / 2][N /2];
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k, p;
    cin >> n >> m >> k >> p;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cnk[i][j] = 0;
        }
    }
    cnk[0][0] = 1;
    for(int i = 1; i < N; i++){
        cnk[i][0] = 1;
        for(int j = 1; j < N; j++){
            cnk[i][j] = (cnk[i - 1][j - 1] + cnk[i - 1][j]);
            if(cnk[i][j] >= p){
                cnk[i][j] -= p;
            }
        }
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            for(int c = 0; c <= n; c++){
                dp[i][j][c] = 0;
            }
        }
    }
    int fact[n + 1];
    fact[0] = 1;
    for(int i = 1; i <= n; i++){
        fact[i] = fact[i - 1] * i % p;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= i; j++){
            dp[i][1][j] = (j == 1) * fact[i];
        }
    }
    for(int i = 1; i <= m; i++){
        dp[0][i][0] = 1;
    }

    for(int h1 = 1; h1 < m; h1++){
        for(int sz_left = 0; sz_left < n; sz_left++){
            for(int c_left = 0; c_left <= sz_left; c_left++){
                if(!dp[sz_left][h1][c_left]){
                    continue;
                }
                for(int sz_right = 0; sz_right + sz_left < n; sz_right++){
                    for(int c_right = 0; c_right <= sz_right; c_right++){
                        if(!dp[sz_right][h1][c_right]){
                            continue;
                        }
                        dp[sz_left + sz_right + 1][h1 + 1][c_left + c_right] = (dp[sz_left + sz_right + 1][h1 + 1][c_left + c_right] + dp[sz_left][h1][c_left] * dp[sz_right][h1][c_right] % p * cnk[sz_left + sz_right][sz_left] % p) % p;
                    }
                }
            }
        }
    }
    cout << dp[n][m][k]<< "\n";
    return 0;
}