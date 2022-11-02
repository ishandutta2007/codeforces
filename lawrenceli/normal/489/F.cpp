#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 505;

int n, m, mod, freq[MAXN], num[3], dp[2][MAXN][MAXN], k[3];

void add(int& a, int b) { a = (a+b)%mod; }

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m >> mod;
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++) {
            char c; cin >> c;
            if (c == '1') freq[j]++;
        }

    for (int i=0; i<n; i++)
        num[2-freq[i]]++;

    dp[0][num[0]][num[1]] = 1;
    for (int i=m; i<n; i++) {
        for (k[0]=0; k[0]<=n; k[0]++)
            for (k[1]=0; k[1]<=n; k[1]++)
                if (dp[0][k[0]][k[1]]) {
                    int x = dp[0][k[0]][k[1]];
                    k[2] = n-k[0]-k[1];

                    for (int j=1; j<3; j++)
                        if (k[j]>=2) {
                            int y = ll(x)*((ll(k[j])*(k[j]-1)/2)%mod)%mod;
                            if (j == 1) add(dp[1][k[0]+2][k[1]-2], y);
                            else add(dp[1][k[0]][k[1]+2], y);
                        }

                    if (k[1]>=1 && k[2]>=1) {
                        int y = ll(x)*(ll(k[1])*k[2]%mod)%mod;
                        add(dp[1][k[0]+1][k[1]], y);
                    }
                }
        for (int a=0; a<=n; a++)
            for (int b=0; b<=n; b++)
                dp[0][a][b] = dp[1][a][b], dp[1][a][b] = 0;
    }

    cout << dp[0][n][0] << '\n';
    return 0;
}