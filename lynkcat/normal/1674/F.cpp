// Lynkcat.
// Problem: F. Desktop Rearrangement
// URL: https://codeforces.com/contest/1674/problem/F
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// -----------------------------------------------

//~~
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
#define N 1005
using namespace std;
int n,m,q;
string a[N];
int ans;
int tot;
void calc(int tt,int f)
{
	int x=(tt-1)%n+1,y=(tt-1)/n+1;
	if (a[x][y]=='*') ans+=0;
	else ans+=f;
}
int id(int x,int y)
{
	return (y-1)*n+x;
}
void BellaKira()
{
	cin>>n>>m>>q;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]=' '+a[i];
		for (auto u:a[i]) tot+=(u=='*');
	}
	for (int i=1;i<=tot;i++)
		calc(i,1);
	// cout<<"??"<<ans<<endl;
	for (int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		if (a[x][y]=='*')
		{
			if (id(x,y)<=tot)
			{
				calc(id(x,y),-1);
				a[x][y]='.';
				calc(id(x,y),1);
			} else a[x][y]='.';
			calc(tot,-1);
			tot--;
		}
		else
		{
			if (id(x,y)<=tot)
			{
				calc(id(x,y),-1);
				a[x][y]='*';
				calc(id(x,y),1);
			} else a[x][y]='*';
			calc(tot+1,1);
			tot++;
		}
		cout<<ans<<endl;
	}
			
				
}
signed main()
{
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}