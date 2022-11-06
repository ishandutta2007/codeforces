#include <bits/stdc++.h>
#define rep(i,  x,  y) for(int i = x; i <= y; i ++)
#define rrep(i, x,  y) for(int i = x; i >= y; i --)
#define ll long long
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define ls rt << 1
#define rs rt << 1 | 1
#define INF 0x3f3f3f3f
#define pll pair<ll, ll>
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int N = 705;
const int MOD = (int)1e9 + 7;

struct Sum
{
    int y, x;
};

void update(int& x, int a)
{
    x += a;
    if (x >= MOD) x -= MOD;
}

int n;
char s[N];
Sum dp[N][2];

int main()
{
    scanf("%s", s);
    n = strlen(s);
    int ans = 0;
    rep(d, 1, 9)
    {
        memset(dp, 0, sizeof(dp));
        dp[0][0].x = 0;
        dp[0][0].y = 1;
        rep(i, 0, n - 1)
        {
            int di = s[i] - '0';
            rep(now, 0, 1)
            {
                int nl = now;
                for (int dd = now ? 9 : di; dd >= 0; dd --) 
                {
                    update(dp[i + 1][nl].y, dp[i][now].y);
                    if (dd < d) update(dp[i + 1][nl].x, dp[i][now].x);
                    else update(dp[i + 1][nl].x, (10LL * dp[i][now].x + dp[i][now].y) % MOD);
                    nl = 1;
                }
            }
        }
        update(ans, dp[n][0].x);
        update(ans, dp[n][1].x);
    }
    printf("%d\n", ans);
    return 0;
    
}