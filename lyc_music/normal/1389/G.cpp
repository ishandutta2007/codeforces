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
#define N 300005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int dfn[N],low[N],sta[N],sky[N],ky[N],f[N],g[N],root,kp[N],c[N],val[N],ans;
int DFN,tp,col_n;
int W[N];
int col[N],faa[N];
vector<pa>G[N],S[N];
int n,m,p;
int gf(int k)
{
	if (faa[k]==k) return k;
	return faa[k]=gf(faa[k]);
}
void ad(int x,int y,int w)
{
	G[x].push_back({y,w});
}
void ads(int x,int y,int w)
{
	S[x].push_back({y,w});
}
void tarjan(int k,int fa)
{
	dfn[k]=++DFN;
	low[k]=dfn[k];
	sta[++tp]=k;
	for (auto U:G[k])
	{
		int u=U.fi,w=U.se;
		if (u==fa) continue;
		if (!dfn[u]) tarjan(u,k),low[k]=min(low[u],low[k]);
		else low[k]=min(low[k],dfn[u]);
	}
	if (dfn[k]==low[k])
	{
		++col_n;
		for (;;)
		{
			int u=sta[tp--];
			col[u]=col_n;
			ky[col_n]|=kp[u];
			val[col_n]+=c[u];
			if (u==k) break;
		}
	}
}
void dfs(int k,int fa)
{
	sky[k]=ky[k];
	for (auto U:S[k])
	{
		int u=U.fi,w=U.se;
		if (u==fa) continue;
		dfs(u,k);
		sky[k]|=sky[u];
		if (sky[u]==0) faa[u]=k,val[k]+=val[u];
	}
}
void dfs1(int k,int fa)
{
	f[k]=val[k];
	for (auto U:S[k])
	{
		int u=U.fi,w=U.se;
		if (u==fa||!sky[u]) continue;
		dfs1(u,k);
		f[k]=f[k]+max(0ll,f[u]-w);
	}
}
void dfs2(int k,int fa)
{
//	cout<<k<<","<<g[k]<<endl;
	for (auto U:S[k])
	{
		int u=U.fi,w=U.se;
		if (u==fa||!sky[u]) continue;
		f[u]=max(f[k]-max(0ll,f[u]-w)-w,0ll)+f[u];
		dfs2(u,k);
	}
}	
signed main()
{
	n=read(),m=read();p=read();
	for (int i=1;i<=p;i++) kp[read()]=1;
	for (int i=1;i<=n;i++)
	 	c[i]=read();
	for (int i=1;i<=m;i++) W[i]=read();
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		ad(u,v,W[i]);
		ad(v,u,W[i]);
	}
	tarjan(n,0);
	for (int i=1;i<=n;i++)
		for (auto U:G[i])
		{
			int u=U.fi,w=U.se;
			if (col[i]!=col[u]&&i<u) ads(col[i],col[u],w),ads(col[u],col[i],w);
		}
	for (int i=1;i<=col_n;i++) faa[i]=i;
	for (int i=1;i<=col_n;i++)
		if (ky[i]==1)
		{
			root=i;
			break;
		}
	dfs(root,0);
	dfs1(root,0);
//	for (int i=1;i<=n;i++) writesp(f[col[i]]);
//	puts("");
	dfs2(root,0);
//	cout<<"!"<<root<<endl;
//	for (int i=1;i<=col_n;i++) cout<<sky[i]<<" ";
	for (int i=1;i<=n;i++) writesp(f[gf(col[i])]);
}
/*
1 5
2 3
2 4
2 6
3 5

*/