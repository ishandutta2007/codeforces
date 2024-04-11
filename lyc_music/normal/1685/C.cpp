// Lynkcat.
// Problem: C. Bring Balance
// URL: https://codeforces.com/contest/1685/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// -----------------------------------------------

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
int n,a[N],s[N];
int st[N][20];
int lg2[N];
int L[N],R[N],sta[N],tp;
string stt;
vector<pa>G[N];
int dis[N],lst[N],lstw[N];
inline int query(int l,int r)
{
	int t=lg2[r-l+1];
	return max(st[l][t],st[r-(1<<t)+1][t]);
}
inline void ad(int x,int y,int z)
{
	G[x].push_back(mp(y,z));
}
void BellaKira()
{
	vector<pa>ans;
	poly g;
	cin>>n;
	cin>>stt;
	for (int i=0;i<stt.size();i++)
	{
		if (stt[i]=='(') a[i+1]=1;
		else a[i+1]=-1;
	}
	stt=' '+stt;
	n*=2;
	for (int i=0;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
		st[i][0]=s[i];
	}
	for (int j=1;j<=18;j++)
		for (int i=0;i+(1<<j)-1<=n;i++)
			st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	tp=0;sta[tp]=-1;
	for (int i=1;i<=n;i++)
	{
		while (tp&&s[sta[tp]]<=s[i])
		{
			tp--;
		}
		L[i]=sta[tp]+1;
		sta[++tp]=i;
	}
	tp=0;sta[tp]=n+1;
	for (int i=n;i>=0;i--)
	{
		while (tp&&s[sta[tp]]<s[i])
		{
			tp--;
		}
		R[i]=sta[tp]-1;
		sta[++tp]=i;
	}
	for (int i=0;i<=n;i++)
	{
		int l=L[i],r=R[i];
		if (i-l+1<=r-i+1)
		{
			for (int j=l;j<=i;j++)
			{
				int L=i,R=r;
				int now=i;
				while (L<=R)
				{
					int mid=L+(R-L)/2;
					if (query(mid,r)+s[j]>=s[i])
					{
						now=mid;
						L=mid+1;
					} else
						R=mid-1;
				}
				ad(j,now,1);
			}
		} else
		{
			for (int j=i;j<=r;j++)
			{
				int L=l,R=i;
				int now=i;
				while (L<=R)
				{
					int mid=L+(R-L)/2;
					if (query(l,mid)+s[j]>=s[i])
					{
						now=mid;
						R=mid-1;
					} else L=mid+1;
				}
				ad(now,j,1);
			}
		}
	}				
	for (int i=1;i<=n;i++)
	{
		if (s[i]>=0)
			ad(i-1,i,0);
			
		ad(i,i-1,0);
	}
	deque<int>q;
	dis[0]=0;
	for (int i=1;i<=n;i++) dis[i]=inf;
	q.push_back(0);
	while (!q.empty())
	{
		int u=q.front();
		// cout<<u<<","<<dis[u]<<endl;
		q.pop_front();
		for (auto [v,w]:G[u])
		{
			if (dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				lstw[v]=w;
				lst[v]=u;
				if (w==0) q.push_front(v);
				else q.push_back(v);
			}
		}
	}
	int now=n;
	while (now)
	{
		if (lstw[now])
		{
			ans.push_back(mp(lst[now]+1,now));
		}
		now=lst[now];
	}
	cout<<ans.size()<<endl;
	for (auto u:ans) cout<<u.fi<<" "<<u.se<<endl;
	for (int i=0;i<=n;i++)
		G[i].clear();
		
}
signed main()
{
	lg2[0]=-1;
	for (int i=1;i<=100000;i++) lg2[i]=lg2[i/2]+1;
	IOS;
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}