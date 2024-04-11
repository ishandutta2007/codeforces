#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define ll long long
#define X first
#define Y second
#define pb push_back
#define mp Maxke_pair
#define pii pair<int, int>
#define ls rt << 1
#define rs rt << 1 | 1
#define sz(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
#define vi vector<int>
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int mod = 1e9 + 7;
int dp[1010][1010][2], a[1010], n, ans, k;
char s[1010];
int check(int x)
{
    int num = 0;
    while(x != 1)
    {
        num ++;
        int tx = 0;
        while(x)
        {
            tx += x & 1;
            x >>= 1;
        }
        x = tx;
    }
    return num;
}
int main()
{
    scanf("%s", s);
    n = strlen(s);
    rep(i, 1, n) a[i] = s[i - 1] - '0';
    k = read();
    if(!k)
    {
        puts("1");
        return 0;
    }
    dp[0][0][1] = 1;
    rep(i, 1, n)
        if(!a[i])
        {
        	rep(j, 0, 1000)
        	{
                dp[i][j][0] = (dp[i][j][0] + dp[i - 1][j][0]) % mod;
                dp[i][j][1] = (dp[i][j][1] + dp[i - 1][j][1]) % mod;
            }
            rep(j, 1, 1000) dp[i][j][0] = (dp[i][j][0] + dp[i - 1][j - 1][0]) % mod;
        }
        else
        {
            rep(j, 0, 1000) dp[i][j][0] = ((dp[i][j][0] + dp[i - 1][j][0]) % mod + dp[i - 1][j][1]) % mod;
            rep(j, 1, 1000)
            {
                dp[i][j][0] = (dp[i][j][0] + dp[i - 1][j - 1][0]) % mod;
                dp[i][j][1] = (dp[i][j][1] + dp[i - 1][j - 1][1]) % mod;
            }
        }

    rep(i, 1, 1000)
        if(check(i) == k - 1)
            ans = ((ans + dp[n][i][0]) % mod + dp[n][i][1])%mod;
    if(k == 1) ans --;
    if(ans < 0) ans += mod;

    printf("%d", ans);
    return 0;
}