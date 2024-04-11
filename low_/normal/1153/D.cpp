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
#define mn 300005
#define inf 4444444444444444444
#define mod 1000000009
#define FLN "test"
#define pii pair <int, int>
#define XX first
#define YY second

int n, K[mn], par[mn];
vector <int> dsk[mn];

int dp[mn], leaf=0;
void DFS(int u)
{
	int m1=0, m2=inf;
	for (int v: dsk[u]) 
	{
		DFS(v);
		m1+=dp[v], m2=min(m2,dp[v]);
	}
	
	if (m2==inf) dp[u]=1, leaf++;
	else
	{
		if (K[u]==1) dp[u]=m2;
		else dp[u]=m1;
	}
}

signed main()
{
#ifdef lowie
	freopen(FLN".inp", "r", stdin);
	freopen(FLN".out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for (int i=1; i<=n; i++) cin>>K[i];
	for (int i=2; i<=n; i++) 
	{
		cin>>par[i];
		dsk[par[i]].push_back(i);
	}
	
	DFS(1);
	cout<<leaf+1-dp[1];
}

// PLEASE REMOVE "cout" AND "cerr" DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/