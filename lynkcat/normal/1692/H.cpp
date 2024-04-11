// Lynkcat.
// Problem: H. Gambling
// Contest: Codeforces - Codeforces Round #799 (Div. 4)
// URL: https://codeforces.com/contest/1692/problem/H
// Memory Limit: 256 MB
// Time Limit: 2000 ms

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
int n,a[N],s[N];
void BellaKira()
{
	map<int,poly>G;
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i],G[a[i]].push_back(i);
	int ans=1;
	int ansl=1,ansr=1;
	for (auto u:G)
	{
		poly now=u.se;
		int m=now.size();
		int mn=1;
		int mnl=now[0];
		s[1]=1;
		for (int i=2;i<=m;i++)
		{
			s[i]=s[i-1]-(now[i-1]-now[i-2]-1)+1;
			if (s[i]-mn+1>ans)
			{
				ans=s[i]-mn+1;
				ansl=mnl;
				ansr=now[i-1];
			}
			if (s[i]<mn)
			{
				mn=s[i];
				mnl=now[i-1];
			}
		}
	}
	cout<<a[ansl]<<" "<<ansl<<" "<<ansr<<endl;
	
			
		
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