// Author: Little09
// Problem: D. Chip Move
// Contest: Educational Codeforces Round 133 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1716/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))
#define printYes cout << "Yes" << endl
#define printYES cout << "YES" << endl
#define printNo cout << "No" << endl
#define printNO cout << "NO" << endl
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll inf=1000000000;
const ll mod=998244353;
//const ll mod=1000000007;

const int N=200005,M=668;
int n,m; 
int dp[2][N],ans[N],s[N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	dp[0][0]=1;
	for (int i=1;i<=666;i++)
	{
		int u=m+i-1;
		for (int j=0;j<=n;j++)
		{
			if (j-u>=0) dp[i&1][j]=s[j-u];
			else dp[i&1][j]=0;
			if (j-u<0) s[j]=dp[(i-1)&1][j];
			else s[j]=(s[j-u]+dp[(i-1)&1][j])%mod;
		}
		for (int j=1;j<=n;j++)
		{
			ans[j]=(ans[j]+dp[i&1][j])%mod;
		}
	}
	for (int i=1;i<=n;i++) cout << ans[i] << " ";
	return 0;
}