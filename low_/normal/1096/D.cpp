#include<iostream>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<deque>
#include<set>
#include<map>
#include<bitset>
#include<ctime>
#include<queue>
using namespace std;
#define int long long
#define mn 100005
#define inf 4444444444444444444
#define mod 1000000009
#define FLN "test"
#define pii pair <int, int>
#define XX first
#define YY second

int n, P[mn];
string S;

int dp[mn][5];

signed main()
{
#ifdef lowie
	freopen(FLN".inp", "r", stdin);
	freopen(FLN".out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	for (int i=0; i<mn; i++) dp[i][0]=dp[i][1]=dp[i][2]=dp[i][3]=dp[i][4]=inf;
	cin>>n>>S;
	for (int i=1; i<=n; i++) cin>>P[i];
	S=" "+S;
	
	string T=" hard";
	
	dp[0][0]=0;
	for (int j=0; j<4; j++) for (int i=1; i<=n; i++) 
	{
		if (S[i]!=T[j+1]) dp[i][j]=min(dp[i-1][j],dp[i][j]);
		else dp[i][j+1]=min(dp[i-1][j], dp[i][j+1]), dp[i][j]=min(dp[i-1][j]+P[i], dp[i][j]);
	}
	int ans=min(min(dp[n][0], dp[n][1]), min(dp[n][2], dp[n][3]));
	cout<<ans;
	
}

// PLEASE REMOVE "cout" AND "cerr" DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/