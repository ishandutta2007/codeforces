// Lynkcat.
// Problem: E. Add Modulo 10
// Contest: Codeforces - Codeforces Round #811 (Div. 3)
// URL: https://codeforces.com/contest/1714/problem/E
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
#define N 200005
using namespace std;
int n,a[N],b[N];
void BellaKira()
{
	cin>>n;
	int ans=1;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if (a[1]==a[n]) return cout<<"Yes"<<endl,void();
	map<int,int>Mp;
	for (int i=1;i<=n;i++)
	{
		
		if (a[i]%10==5)
		{
			Mp[a[i]]++;
			Mp[a[i]+5]++;
			continue;
		}
		if (a[i]%10==0)
		{
			Mp[a[i]]++;
			continue;
		}
		if ((a[i]%10)%2==1) a[i]+=a[i]%10;
			int o=a[i]+(1000000000-a[i])/20*20;
			for (int j=1;j<=50;j++)
				Mp[o]++,o=(o+o%10);
	}
	ans=0;
	for (auto u:Mp)
		if(u.se==n) ans=1;
		if (ans) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
		
		
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