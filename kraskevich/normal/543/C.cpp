#include <bits/stdc++.h>

using namespace std;

const int INF = 1000 * 1000 * 1000;
const int N = 20;

int dp[1 << N];
int sumForLett[N][26];
int maskForLett[N][26];
int maxForLett[N][26];
int a[N][N];
string s[N];

int main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    for (int i = 0; i < n; i++)
        for (int pos = 0; pos < m; pos++) {
            char c = s[i][pos] - 'a';
            sumForLett[pos][c] += a[i][pos];
            maskForLett[pos][c] |= (1 << i);    
            maxForLett[pos][c] = max(maxForLett[pos][c], a[i][pos]);  
        } 
    int maxMask = (1 << n);
    for (int i = 0; i < maxMask; i++)
        dp[i] = INF;
    dp[0] = 0;
    for (int pos = 0; pos < m; pos++)
        for (int mask = 0; mask < maxMask; mask++) {
            if (dp[mask] == INF)
                continue;
            for (int i = 0; i < n; i++) {
                int nmask = mask | (1 << i);
                int nval = dp[mask] + a[i][pos];
                if (dp[nmask] > nval)
                    dp[nmask] = nval;
                int c = s[i][pos] - 'a';
                nmask = mask | maskForLett[pos][c];
                nval =  dp[mask] + sumForLett[pos][c] - maxForLett[pos][c];
                if (dp[nmask] > nval)
                    dp[nmask] = nval;
            }
        }
    cout << dp[maxMask - 1] << endl;
    return 0;
}