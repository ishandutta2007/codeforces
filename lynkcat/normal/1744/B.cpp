// Lynkcat.
// Problem: B. Even-Odd Increments
// Contest: Codeforces - Codeforces Round  #828 (Div. 3)
// URL: https://codeforces.com/contest/1744/problem/B
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
#define inf 1e9
#define mod 998244353
#define int ll
#define N 100005
using namespace std;
int n,q,a[N];
void BellaKira()
{
	cin>>n>>q;
	int sm=0;
	int o=0,oo=0;
	for (int i=1;i<=n;i++)
		cin>>a[i],sm+=a[i],o+=(a[i]%2==0),oo+=(a[i]%2==1);
	int X=0,Y=0;
	int Z=0;
	int bl=0;
	for (int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		if (!bl)
		{
			if (y%2==1)
			{
				if (x==0) X+=y,bl=2;
				else Y+=y,bl=1;
			}
			else
			{
				if (x==0) X+=y;
				else Y+=y;
			}
		} else
		{
			if (bl-1==x)
			{
				Z+=y;
				if (y%2==1) bl=3-bl;
			}
		}
		cout<<Z*n+X*o+Y*oo+sm<<endl;
		// " "<<o<<" "<<oo<<" "<<X<<" "<<Y<<" "<<Z<<" "<<bl<<'\n';
	}
}
signed main()
{
	IOS;
	cin.tie(0);
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}