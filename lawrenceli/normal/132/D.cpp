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
    int ans = dp[n+1][0], x = n+1, y = 0;

    vector<pii> v;
    while (x) {
        int p = par[x][y];
        if (p) v.push_back(pii(y^1, n-x+1));
        if (b[x]^y) v.push_back(pii(y, n-x));
        x--, y^=p;
    }

    printf("%d\n", ans);
    for (int i=0; i<v.size(); i++)
        printf("%c2^%d\n", v[i].first?'-':'+', v[i].second);
    return 0;
}