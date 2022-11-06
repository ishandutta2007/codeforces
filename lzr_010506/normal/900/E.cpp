#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define Next(a) ((a != x) ? solve(a) : 0)
#define ll long long
#define N 200010
#define INF 0x3f3f3f3f
#define mo 1000000007
using namespace std;

int n, m;
int rep[N], dp[N][2];
char s[N];

int main()
{
    scanf("%d %s %d", &n, s + 1, &m);
    memset(rep, -1, sizeof(rep));
    int i, cnta[2] = {}, cntb[2] = {}, cntx = 0;
    rep(i, 1, m - 1)
    {
        if(s[i] == 'a') cnta[i & 1] ++;
        else if(s[i] == 'b') cntb[i & 1] ++;
        else cntx ++;
    }

    for(i = 1; i + m - 1 <= n; i ++)
    {
        if(s[i + m -1] == 'a') cnta[(i + m - 1) & 1] ++;
        else if(s[i + m - 1] == 'b') cntb[(i + m - 1) & 1] ++;
        else cntx ++;

        if(i & 1)
        {
            if(cnta[0] == 0 && cntb[1] == 0) rep[i] = cntx;
            else rep[i] = -1;
        }
        else
        {
            if(cnta[1] == 0 && cntb[0] == 0) rep[i] = cntx;
            else rep[i] = -1;
        }
        if(s[i] == 'a') cnta[i & 1] --;
        else if(s[i] == 'b') cntb[i & 1] --;
        else cntx --;
    }

    rep(i, m, n)
    {
        dp[i][0] = dp[i - 1][0];
        dp[i][1] = dp[i - 1][1];
        if(rep[i - m + 1] != -1)
            if(dp[i - m][0] + 1 > dp[i][0] || (dp[i - m][0] + 1 == dp[i][0] && dp[i - m][1] + rep[i - m + 1] < dp[i][1]))
            {
                dp[i][0] = dp[i - m][0] + 1;
                dp[i][1] = dp[i - m][1] + rep[i - m + 1];
            }
    }
    printf("%d\n", dp[n][1]);
	return 0;
}