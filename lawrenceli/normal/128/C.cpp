#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>

using namespace std;

const int MAXN = 1005;
const int MOD = 1e9 + 7;

int n, m, k;
int dp[MAXN][MAXN];

void init() {
    for (int i=1; i<MAXN; i++) dp[i][0] = 1;
    for (int j=1; j<MAXN; j++) {
        int pre = 0;
        for (int i=1; i<MAXN; i++) {
            dp[i][j] = (dp[i-1][j] + pre) % MOD;
            pre = (pre + dp[i-1][j-1]) % MOD;
        }
    }
}

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    init();

    cin >> n >> m >> k;
    cout << (long long)(dp[n][k]) * dp[m][k] % MOD << '\n';
    return 0;
}