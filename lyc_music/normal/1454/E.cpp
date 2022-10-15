//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define ll long long
#define F(i,a,b) for (int i=(a);i<=(b);i++)
#define R(i,a,b) for (int i=(a);i<(b);i++)
#define D(i,a,b) for (int i=(a);i>=(b);i--)
#define go(i,x) for (int i=head[x];i;i=e[i].nx)
#define IOS ios::sync_with_stdio(false)
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
#define N 200005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int T,n,dep[N],f[N][25],ans,vis[N],siz[N],fa[N],fuck[N],cho[N],cnt[N],X,Y;
vector<pa>G[N];
pa E[N];
int gf(int x)
{
	if (fa[x]==x) return x;
	return fa[x]=gf(fa[x]);
}
void dfs(int k,int fa)
{
	vis[k]=1;
	siz[k]=1;
	f[k][0]=fa;dep[k]=dep[fa]+1;
	for (auto U:G[k])
	{
		int u=U.fi;
		if (vis[u]) continue;
		fuck[u]=U.se;
		dfs(u,k);
		siz[k]+=siz[u];
	}
}
inline int lca(int x,int y)
{
	if (dep[x]<dep[y]) swap(x,y);
	for (int i=20;i>=0;i--)
		if (dep[f[x][i]]>=dep[y]) x=f[x][i];
	if (x==y) return x;
	for (int i=20;i>=0;i--)
		if (f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}
signed main()
{
	T=read();
	while (T--)
	{
		n=read();ans=0;int nowfuck=0;
		for (int i=1;i<=n;i++)
		{
			int u=read(),v=read();
			G[u].push_back({v,i});
			G[v].push_back({u,i});
			E[i]={u,v};
		}
		dfs(1,0);
		for (int i=1;i<=20;i++)
			for (int j=1;j<=n;j++)
				f[j][i]=f[f[j][i-1]][i-1];
		for (int i=1;i<=n;i++)
		{
			int x=E[i].fi,y=E[i].se,z=lca(E[i].fi,E[i].se);
//			cout<<x<<" "<<y<<" "<<z<<endl;
			if (x!=f[y][0]&&y!=f[x][0])
			{
				X=x,Y=y;
//				cout<<X<<" "<<Y<<endl;
				nowfuck=i;
				while (X!=z) cho[fuck[X]]=1,X=f[X][0];
				swap(X,Y);
				while (X!=z) cho[fuck[X]]=1,X=f[X][0];
				break;
			}
		}
		for (int i=1;i<=n;i++) fa[i]=i,cnt[i]=1;
		for (int i=1;i<=n;i++)
			if (!cho[i])
			{
				if (i==nowfuck) continue;
				int x=E[i].fi,y=E[i].se;
				gf(x),gf(y);
				cnt[fa[y]]+=cnt[fa[x]];
				fa[fa[x]]=fa[y];
			}
		for (int i=1;i<=n;i++)
			if (cho[i])
			{
				int x=E[i].fi,y=E[i].se;
				gf(x),gf(y);
				ans+=cnt[fa[y]]*cnt[fa[x]];
//				cout<<x<<" "<<y<<" "<<ans<<" "<<cnt[fa[y]]<<" "<<cnt[fa[x]]<<" "<<fa[x]<<" "<<fa[y]<<endl;
				cnt[fa[y]]+=cnt[fa[x]];
				fa[fa[x]]=fa[y];
			}
		
		writeln(ans+n*(n-1)/2);
		for (int i=1;i<=n;i++) G[i].clear(),vis[i]=0,cho[i]=0;
	}
		
		
		
}
/*
1
11
9 1
1 2
7 1
4 10
8 5
4 6
4 2
7 5
2 5
3 1
11 6
*/