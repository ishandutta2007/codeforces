//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
#define N 400005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int T,n,m;
pa E[N];
vector<int>G[N],G1[N];
int usd[N];
queue<int>q;
int vis[N],dis[N],f[N],f1[N];
int ru[N],ru1[N];

signed main()
{
	T=read();
	while (T--)
	{
		n=read();m=read();
		for (int i=1;i<=m;i++)
		{
			int u=read(),v=read();
			E[i]={u,v};
			G[u].push_back(i);
		}
		q.push(1);
		dis[1]=0;
		vis[1]=1;
		while (!q.empty())
		{
			int u=q.front();
			q.pop();
			for (auto id:G[u])
			{
				int v=E[id].se;
				if (vis[v]) continue;
				vis[v]=1;
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
		for (int i=1;i<=m;i++)
			if (dis[E[i].fi]<dis[E[i].se])
			{
				G1[E[i].se].push_back(E[i].fi);
				ru[E[i].fi]++;
			}
		for (int i=1;i<=n;i++)
		{
			f[i]=dis[i];
			ru1[i]=ru[i];
		}
//		cout<<endl;
		for (int i=1;i<=n;i++) f1[i]=f[i];
		for (int i=1;i<=m;i++)
			if (dis[E[i].fi]>=dis[E[i].se])
			{
				f1[E[i].fi]=min(f1[E[i].fi],dis[E[i].se]);
//				cout<<"?"<<E[i].se<<" "<<E[i].fi<<endl;
			}
		for (int i=1;i<=n;i++)
			if (!ru1[i])
			{
				q.push(i);
			}
		while (!q.empty())
		{
			int u=q.front();
			q.pop();
			for (auto v:G1[u])
			{
				ru1[v]--;
				f1[v]=min(f1[v],f1[u]);
				if (!ru1[v]) 
				{
					q.push(v);
				}
			}
		}
		for (int i=1;i<=n;i++) 
		{
			writesp(f1[i]);
			G1[i].clear(),G[i].clear();
			ru[i]=ru1[i]=f[i]=f1[i]=dis[i]=0;
			vis[i]=0;
		}
		for (int i=1;i<=m;i++) usd[i]=0;
	}
		
		
		
		
				
			
				
}
/*

*/