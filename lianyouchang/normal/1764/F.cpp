// Problem: F. Doremy's Experimental Tree
// Contest: Codeforces - Codeforces Global Round 24
// URL: https://codeforces.com/contest/1764/problem/F
// Memory Limit: 256 MB
// Time Limit: 2500 ms

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
#define N 2005
using namespace std;
int n,f[N][N],siz[N];
int vis[N];
void BellaKira()
{
	cin>>n;
	int x=0,y=0;
	int mn=inf;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=i;j++)
		{
			cin>>f[i][j];
			f[j][i]=f[i][j];
			if (f[i][j]<mn)
			{
				x=i,y=j;
			}
		}
	for (int j=1;j<=n;j++) siz[j]=1;
	for (int i=1;i<n;i++)
	{
		int pos=0;
		for (int j=1;j<=n;j++)
			if (!vis[j]&&j!=x)
			{
				if (!pos||f[x][pos]>f[x][j]) pos=j;
			}
		// cout<<"??"<<x<<" "<<pos<<'\n';
		vis[pos]=1;
		int pos1=0;
		int vv=0;
		for (int j=1;j<=n;j++)
			if (!vis[j]&&j!=pos)
			{
				int V=f[x][j]-f[x][pos];
				if (V%siz[pos]!=0) continue;
				V/=siz[pos];
				if (f[j][j]-f[pos][pos]==(siz[pos]-(n-siz[pos]))*V&&f[j][j]-f[j][pos]==siz[pos]*V)
				{
					// cout<<"?"<<j<<" "<<f[x][j]<<'\n';
					if (!pos1||f[x][j]>f[x][pos1])
						pos1=j,vv=V;
					// break;
				}
			}
		siz[pos1]+=siz[pos];
		cout<<pos<<" "<<pos1<<" "<<vv<<'\n';
	}
	
			
}
signed main()
{
	IOS;cin.tie(0); 
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}