#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXS = 105;
const int MAXN = 55;
const int INF = 1e9;

string str;
int n;
int dp[MAXS][MAXN][2][2]; //0 - left, 1 - right
int dir[2];

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    dir[0] = -1; dir[1] = 1;
    for (int i=0; i<MAXS; i++)
        for (int j=0; j<MAXN; j++)
            for (int k=0; k<2; k++)
                for (int l=0; l<2; l++)
                    dp[i][j][k][l] = -INF;
    dp[0][0][0][0] = dp[0][0][0][1] = 0;
    cin >> str >> n;
    for (int i=0; i<str.length(); i++) {
        for (int j=0; j<=n; j++) {
            for (int k=0; k<2; k++) {
                for (int l=0; l<2; l++) {
                    if (str[i] == 'T') {
                        dp[i+1][j][k^1][l] = max(dp[i+1][j][k^1][l], dp[i][j][k][l]);
                        dp[i+1][j+1][k][l] = max(dp[i+1][j+1][k][l], dp[i][j][k][l] + dir[k^l]);
                    } else {
                        dp[i+1][j][k][l] = max(dp[i+1][j][k][l], dp[i][j][k][l] + dir[k^l]);
                        dp[i+1][j+1][k^1][l] = max(dp[i+1][j+1][k^1][l], dp[i][j][k][l]);
                    }
                }
            }
        }
    }
    int best = 0;
    for (int i=n; i>=0; i-=2) {
        for (int j=0; j<2; j++) {
            for (int k=0; k<2; k++) {
                best = max(best, dp[str.length()][i][j][k]);
            }
        }
    }
    cout << best << endl;
}