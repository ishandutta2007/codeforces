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
#define mn 500005
#define inf 4444444444444444444
#define mod 1000000009
#define FLN "test"
#define pii pair <int, int>
#define XX first
#define YY second

int ans[mn], dp[mn];
int n, k;
char S[mn], T[mn];

signed main()
{
#ifdef lowie
	freopen(FLN".inp", "r", stdin);
	freopen(FLN".out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>k;
	for (int i=1; i<=n; i++) cin>>S[i];
	for (int i=1; i<=n; i++) cin>>T[i];
	
	int d=n+1;
	for (int i=1; i<=n; i++)
	{
		if (S[i]!=T[i]) 
		{
			d=i;
			break;
		}
		ans[i]=1;
	}
	
//	cerr<<d<<"\n";
	for (int i=d; i<=n; i++) ans[i]=2;
	for (int i=d+1; i<=n; i++) dp[i]+=(S[i]=='a')+(T[i]=='b');
	
	for (int i=1; i<=n; i++) dp[i]=min(dp[i-1]*2+dp[i], k);
	int ANS=0;
	for (int i=1; i<=n; i++) ANS+=min(ans[i]+dp[i], k);
	cout<<ANS;
}

// PLEASE REMOVE "cout" AND "cerr" DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/