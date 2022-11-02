//almost exact same as 132D??
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;

const int MAXN = 1000100;
const int INF = 1e9;

int n;
char s[MAXN];
bool b[MAXN];
int dp[MAXN][2], par[MAXN][2];

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    gets(s); n = strlen(s);
    for (int i=0; i<n; i++)
        b[i+1] = s[i]-'0';
    for (int i=0; i<MAXN; i++)
        for (int j=0; j<2; j++)
            dp[i][j] = INF;
    dp[0][0] = 0;
    for (int i=1; i<=n+1; i++)
        for (int j=0; j<2; j++) {
            int x = b[i]^j;
            if (dp[i-1][j]+x < dp[i][j])
                dp[i][j] = dp[i-1][j]+x, par[i][j] = 0;
            if (dp[i-1][j^1]+x+1 < dp[i][j])
                dp[i][j] = dp[i-1][j^1]+x+1, par[i][j] = 1;
        }

    printf("%d\n", dp[n+1][0]);
    return 0;
}