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

int n, c[mn];
int cnt1[mn], cnt2[mn];
vector <int> dsk[mn];
int par[mn];

void dfs(int u)
{
	cnt1[u]=(c[u]==1), cnt2[u]=(c[u]==2);
	
	for (int j:dsk[u]) if (j!=par[u])
	{
		par[j]=u;
		dfs(j);
		cnt1[u]+=cnt1[j];
		cnt2[u]+=cnt2[j];
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
	
	int C1=0, C2=0;
	cin>>n;
	for (int i=1; i<=n; i++) 
	{
		cin>>c[i];
		C1+=(c[i]==1);
		C2+=(c[i]==2);
	}
	int u, v;
	for (int i=1; i<n; i++)
	{
		cin>>u>>v;
		dsk[u].push_back(v);
		dsk[v].push_back(u);
	}
	
	dfs(1);
	int ans=0;
	for (int i=2; i<=n; i++)
	{
		if (cnt1[i]>0 && cnt2[i]>0) continue;
		if (C1>cnt1[i] && C2>cnt2[i]) continue;
		ans++;
	}
	cout<<ans;
}

// PLEASE REMOVE "cout" AND "cerr" DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/