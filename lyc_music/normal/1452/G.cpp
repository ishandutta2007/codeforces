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
//#define int ll
#define N 200005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,m;
int a[N],dis[N];
queue<int>q;
queue<pa>Q;
vector<int>G[N],G1[N];
int now[N];
int ans[N];
void ad(int x,int y)
{
	G[x].push_back(y);
}
signed main()
{
	n=read();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		ad(u,v);
		ad(v,u);
	}
	m=read();
	memset(dis,0x3f,sizeof(dis));
	for (int i=1;i<=m;i++) a[i]=read(),dis[a[i]]=0,q.push(a[i]);
	while (!q.empty())
	{
		int u=q.front();
		q.pop();
		for (auto v:G[u])
		{
			if (dis[v]>dis[u]+1)
			{
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
	}
	for (int i=1;i<=n;i++) G1[dis[i]].push_back(i);
//	cout<<i<<" "<<dis[i]<<endl;
	for (int i=n;i>=0;i--)
	{
		if (G1[i].empty()) continue;
//		cout<<"?"<<i<<" "<<G1[i].size()<<endl;
		for (auto u:G1[i])
		{
			if (now[u]>=i) continue;
			now[u]=i;
			if (!ans[u]) ans[u]=i;
			Q.push({i,u});
//			cout<<">"<<i<<" "<<u<<endl;
		}
		while (!Q.empty())
		{
			int x=Q.front().fi,y=Q.front().se;
			Q.pop();
//			cout<<"?"<<x<<" "<<y<<endl;
			if (x==1) continue;
			for (auto u:G[y])
			{
				if (now[u]>=x-1) continue;
				if (!ans[u]) ans[u]=i;
				now[u]=x-1;
				Q.push({x-1,u});
			}
		}
	}
	for (int i=1;i<=n;i++) writesp(ans[i]);	
}
/*

*/