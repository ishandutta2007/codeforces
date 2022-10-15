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
#define N 200005
using namespace std;
int ans[N];
vector<pa>G[N];
const int B=200000;
int n;
int tr[N];
void upd(int x,int y)
{
	while (x<=B)
	{
		tr[x]+=y;
		x+=x&-x;
	}
}
int qry(int x)
{
	int res=0;
	while (x)
	{
		res+=tr[x];
		x-=x&-x;
	}
	return res;
}
void BellaKira()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		int l,r;
		cin>>l>>r;
		G[r].push_back(mp(l,i));
		int lf=(l+2)/3;
		int rt=r/6;
		ans[i]=(r-l+1)*(r-l)*(r-l-1)/6;
		if (lf<=rt)
			ans[i]-=rt-lf+1;
		lf=(l+5)/6;
		rt=r/15;
		if (lf<=rt)
			ans[i]-=rt-lf+1;
	}
	for (int i=1;i<=B;i++)
	{
		poly g,g1;
		for (int j=1;j*j<=i;j++)
			if (i%j==0)
			{
				if (j!=i)
				{
					g.push_back(j);
				}
				if (i/j!=i&&j!=i/j)
				{
					g1.push_back(i/j);
				}
			}
		while (g1.size()) g.push_back(g1.back()),g1.pop_back();
		int tt=g.size();
		upd(1,tt*(tt-1)/2);
		// cout<"?"<<tt*(tt-1)/2<<endl;
		for (int j=0;j<g.size();j++)
		{
			tt--;
			upd(g[j]+1,tt*(tt-1)/2-(tt+1)*(tt)/2);
			// cout<<"?"<<g[j]<<" "<<tt*(tt-1)/2-(tt+1)*(tt)/2<<endl;
		}
		for (auto [u,v]:G[i])
		{
			ans[v]-=qry(u);
		}
		// cout<<i<<" "<<qry(2)<<endl;
	}
	for (int i=1;i<=n;i++) cout<<ans[i]<<'\n';
			
}
signed main()
{
	IOS;
	cin.tie(0);
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}