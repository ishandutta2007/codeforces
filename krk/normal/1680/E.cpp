#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const int Inf = 1000000000;

int T;
int n;
char B[2][Maxn];
int dp[Maxn][2];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        scanf("%s", B[0]);
        scanf("%s", B[1]);
        int lef = 0;
        while (B[0][lef] != '*' && B[1][lef] != '*') lef++;
        int rig = n - 1;
        while (B[0][rig] != '*' && B[1][rig] != '*') rig--;
        for (int i = lef; i <= rig + 1; i++)
            dp[i][0] = dp[i][1] = Inf;
        dp[lef + 1][0] = B[1][lef] == '*'? 1: 0;
        dp[lef + 1][1] = B[0][lef] == '*'? 1: 0;
        for (int i = lef + 1; i <= rig; i++) {
            bool hasA = true, hasB = B[1][i] == '*';
            dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + 1 + int(hasB));
            dp[i + 1][1] = min(dp[i + 1][1], dp[i][0] + 2);
            hasA = B[0][i] == '*', hasB = true;
            dp[i + 1][0] = min(dp[i + 1][0], dp[i][1] + 2);
            dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + 1 + int(hasA));
        }
        printf("%d\n", min(dp[rig + 1][0], dp[rig + 1][1]));
    }
    return 0;
}