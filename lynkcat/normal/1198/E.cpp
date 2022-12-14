// Lynkcat.
// Problem: A. Rectangle Painting 2
// Contest: Codeforces - 10.10(1)
// URL: https://codeforces.com/gym/403247/problem/A
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
#define inf 1e9
#define mod 998244353
#define int ll
#define N 100005
using namespace std;
namespace G
{
	struct edge
	{
		int to,val,nxt;
		edge(int a=0,int b=0,int c=0)
		{
			to=a,val=b,nxt=c;
		}
	}E[N];
	int cnt=1;
	int hd[N],dis[N],q[N],cur[N];
	int n,m,S,T,ans;
	void add(int x,int y,int w)
	{
		E[++cnt].to=y;
		E[cnt].val=w;
		E[cnt].nxt=hd[x];
		hd[x]=cnt;
		
		E[++cnt].to=x;
		E[cnt].val=0;
		E[cnt].nxt=hd[y];
		hd[y]=cnt;
	}
	int bfs()
	{
		int l=1,r=1;
		for (int i=1;i<=n;i++) dis[i]=inf,cur[i]=hd[i];
		dis[S]=0;
		q[1]=S;
		while (l<=r)
		{
			int u=q[l++];
			for (int i=hd[u];i;i=E[i].nxt)
			{
				if (E[i].val&&dis[E[i].to]>dis[u]+1)
				{
					dis[E[i].to]=dis[u]+1;
					q[++r]=E[i].to;
				}
			}
		}
		return (dis[T]!=inf);
	}
	int dinic(int k,int liu)
	{
		if (k==T) return liu;
		int res=liu;
		for (int i=cur[k];i&&res;i=E[i].nxt)
		{
			cur[k]=i;
			if (dis[E[i].to]==dis[k]+1&&E[i].val)
			{
				int c=dinic(E[i].to,min(res,E[i].val));
				res-=c;
				E[i].val-=c;
				E[i^1].val+=c;
				if (!res) break;
			}
		}
		return liu-res;
	}	
}
int n,m,a[N],b[N],x[N],y[N];
int s[105][105];
void BellaKira()
{
	cin>>n>>m;
	poly gx,gy;
	for (int i=1;i<=m;i++)
		cin>>a[i]>>b[i]>>x[i]>>y[i],gx.push_back(a[i]),gx.push_back(x[i]+1),
		gy.push_back(b[i]),gy.push_back(y[i]+1);
	sort(gx.begin(),gx.end());gx.erase(unique(gx.begin(),gx.end()),gx.end());
	sort(gy.begin(),gy.end());gy.erase(unique(gy.begin(),gy.end()),gy.end());
	for (int i=1;i<=m;i++)
	{
		a[i]=lower_bound(gx.begin(),gx.end(),a[i])-gx.begin()+1;
		x[i]=lower_bound(gx.begin(),gx.end(),x[i]+1)-gx.begin()+1;
		b[i]=lower_bound(gy.begin(),gy.end(),b[i])-gy.begin()+1;
		y[i]=lower_bound(gy.begin(),gy.end(),y[i]+1)-gy.begin()+1;
		s[a[i]][b[i]]++;
		s[a[i]][y[i]]--;
		s[x[i]][b[i]]--;
		s[x[i]][y[i]]++;
	}
	n=max(gx.size(),gy.size());
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
	G::n=2*n+2,G::S=G::n-1,G::T=G::n;
	for (int i=1;i<gx.size();i++) G::add(2*n+1,i,gx[i]-gx[i-1]);
	for (int i=1;i<gy.size();i++) G::add(i+n,2*n+2,gy[i]-gy[i-1]);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (s[i][j])
			{
				G::add(i,j+n,inf);
			}
	int ans=0;
	while (G::bfs())
	{
		ans+=G::dinic(2*n+1,inf);
	}
	cout<<ans<<'\n';
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