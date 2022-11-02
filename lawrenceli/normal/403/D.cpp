#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1005;
const int MAXL = 50;
const int MOD = 1e9 + 7;

int fact[MAXN], dp[MAXN][MAXL][2];

void add(int& a, int b) { a = (a+b)%MOD; }

void init() {
    fact[0] = 1;
    for (int i=1; i<MAXN; i++)
        fact[i] = ll(fact[i-1])*i%MOD;

    dp[0][0][1] = 1;

    for (int k=0; k<MAXN; k++) {
        for (int i=0; i<MAXN; i++)
            for (int j=0; j<MAXL; j++) {
                if (i>0) add(dp[i][j][1], dp[i-1][j][1]);
                if (k>0) add(dp[i][j][1], dp[i][j][0]);
                if (i>0 && k>0) add(dp[i][j][1], (MOD-dp[i-1][j][0])%MOD);
                if (i-k>=0 && j>0 && k>0) add(dp[i][j][1], dp[i-k][j-1][0]);
            }

        for (int i=0; i<MAXN; i++)
            for (int j=0; j<MAXL; j++)
                dp[i][j][0] = dp[i][j][1], dp[i][j][1] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    init();

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        if (k >= MAXL) cout << "0\n";
        else cout << ll(dp[n][k][0])*fact[k]%MOD << '\n';
    }
    return 0;
}