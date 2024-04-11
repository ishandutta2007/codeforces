// Lynkcat.
// Problem: B. Fake Plastic Trees
// Contest: Codeforces - Codeforces Round #800 (Div. 1)
// URL: https://codeforces.com/contest/1693/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms

#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
#define N  200005
using namespace std;
int n,fa[N];
poly G[N];
int l[N],r[N];
int vl[N],vr[N],vsl[N],vsr[N];
void BellaKira()
{
	cin>>n;
	for (int i=2;i<=n;i++) cin>>fa[i],G[fa[i]].push_back(i);
	for (int i=1;i<=n;i++) cin>>l[i]>>r[i];
	
	for (int i=n;i>=1;i--)
	{
		int x=0,y=0,smx=0,smy=0;
		for (auto u:G[i]) x+=vl[u],y+=vsl[u];
		if (x<l[i]) y++,x=r[i];
		else x=min(x,r[i]);
		vl[i]=x,vsl[i]=y;
	}
	
	cout<<vsl[1]<<endl;
	
	for (int i=1;i<=n;i++) vsl[i]=inf,vsr[i]=inf,vl[i]=inf,vr[i]=inf,G[i].clear();
				
				
		
}
signed main()
{
	IOS;
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}