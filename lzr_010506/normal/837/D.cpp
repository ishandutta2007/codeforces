#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define il inline
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (x).size()
#define ALL(x) (x).begin(), (x).end()
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
const int N = 210;
int dp[210][210 * 30];
int main()
{
	int n, k;
	scanf("%d%d",&n,&k);
	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;
	int i;
	for(i=1; i<=n; i++)
	{
		long long x;
		scanf("%lld",&x);
		int two = 0, five = 0;
		while(x % 2 == 0) x /= 2, two++;
		while(x % 5 == 0) x /= 5, five++;
		int j;
		for(int j = k - 1; j >= 0; j --)
		{
			int l;
			for(l=30 * 200; l>=0; l--)
			 if (dp[j][l] >= 0)
			{
				dp[j + 1][l + five] = max(dp[j][l] + two, dp[j + 1][l + five]);
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= n*30; i ++)
	{
		//cout << dp[k][i] << " " << i << endl;
		ans = max(ans, min(dp[k][i], i));
	}
	cout << ans;
}