// Problem: M. Minimum LCM
// Contest: Codeforces - 2022-2023 ICPC, NERC, Southern and Volga Russian Regional Contest (Online Mirror, ICPC Rules, Preferably Teams)
// URL: https://codeforces.com/contest/1765/problem/M
// Memory Limit: 512 MB
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
// #define N 
using namespace std;
void BellaKira()
{
	int n;
	cin>>n;
	if (n%2==0) cout<<n/2<<" "<<n/2<<'\n';
	else
	{
		int ansx=1,ansy=n-1;
		int ans=inf;
		for (int i=1;i*i<=n;i++)
		{
			if (n%i==0)
			{
				int x=n/i;
				int y=x-1;
				x=1;
				if (x*y*i<ans)
				{
					ansx=x*i,ansy=y*i;
					ans=x*y*i;
				}
			}
			if (n%i==0&&i!=1)
			{
				int x=i;
				int y=x-1;
				x=1;
				if (x*y*n/i<ans)
				{
					ansx=x*n/i,ansy=y*n/i;
					ans=x*y*n/i;
				}
			}
		}
		cout<<ansx<<" "<<ansy<<'\n';
	}
}
signed main()
{
	IOS;cin.tie(0); 
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}