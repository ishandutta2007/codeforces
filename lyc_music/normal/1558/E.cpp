//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define ll long long
#define F(i,a,b) for (int i=(a);i<=(b);i++)
#define R(i,a,b) for (int i=(a);i<(b);i++)
#define D(i,a,b) for (int i=(a);i>=(b);i--)
#define go(i,x) for (int i=head[x];i;i=e[i].nx)
#define mp make_pair
#define pb push_back
#define pa pair < int,int >
#define fi first
#define se second
#define re register
#define be begin()
#define en end()
#define sqr(x) ((x)*(x))
#define ret return puts("-1"),0;
#define put putchar('\n')
#define inf 1000000005
#define mod 998244353
#define int ll
#define N 100005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int f[N],vis[N],pre[N],dis[N],a[N],b[N],L,R,ans;
int n,m;
queue<int>q;
vector<int>G[N];
int check(int x)
{
	memset(f,0,sizeof(f));
	f[1]=1;
	while (1)
	{
		int sm=0;
		for (int i=1;i<=n;i++) vis[i]=f[i],pre[i]=0,sm+=f[i];
//		cout<<x<<endl;
//		for (int i=1;i<=n;i++) cout<<f[i];
//		cout<<endl;
		if (sm==n) return 1;
		for (int i=1;i<=n;i++)
			if (f[i]) q.push(i),dis[i]=x;
		int U=0,V=0;
		while (!q.empty())
		{
			int u=q.front();
			q.pop();
			for (auto v:G[u])
			{
				if (f[v]&&f[u]) continue;
				if (dis[u]<=a[v]||pre[u]==v) continue;
				if (vis[v])
				{
					U=u;
					V=v;
					break;
				}
				dis[v]=dis[u]+b[v];
				vis[v]=1;
				q.push(v);
				pre[v]=u;
			}
			if (U) break;
		}
		while (!q.empty()) q.pop();
//		cout<<U<<" "<<V<<endl;
		if (!U) return 0;
		for (;!f[U];U=pre[U]) f[U]=1,x+=b[U];
		for (;!f[V];V=pre[V]) f[V]=1,x+=b[V];
	}
}	
signed main()
{
	int T=read();
	while (T--)
	{
		n=read(),m=read();
		for (int i=2;i<=n;i++) a[i]=read();
		for (int i=2;i<=n;i++) b[i]=read();
		for (int i=1;i<=m;i++)
		{
			int u=read(),v=read();
			G[u].push_back(v);
			G[v].push_back(u);
		}
		L=0,R=1e14;ans=0;
		while (L<=R)
		{
			int mid=L+(R-L)/2;
			if (check(mid)) ans=mid,R=mid-1;
			else L=mid+1;
		}
		writeln(ans);
		for (int i=1;i<=n;i++) G[i].clear();
	}
}
/*

*/