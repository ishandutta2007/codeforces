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
#define inf 1e18
#define mod 998244353
#define int ll
#define N 300005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int w1[N],w2[N],dp[N][25][2][2],st[N][25],dep[N];
int val[N];
int q,n,x,y;
vector<pa>G[N];
void ad(int x,int y,int z)
{
	G[x].push_back({y,z});
}
void init(int k,int fa)
{
	for (auto U:G[k])
	{
		int u=U.fi,id=U.se;
		if (u==fa) continue;
		init(u,k);
		val[k]=min(val[k],val[u]+w1[id]+w2[id]);
	}
}
void init1(int k,int fa)
{
	for (auto U:G[k])
	{
		int u=U.fi,id=U.se;
		if (u==fa) continue;
		val[u]=min(val[u],val[k]+w1[id]+w2[id]);
		init1(u,k);
	}
}	
void dfs(int k,int fa,int lsteg)
{
	dep[k]=dep[fa]+1;
	st[k][0]=fa;
	for (int i=1;i<=20;i++)
		st[k][i]=st[st[k][i-1]][i-1];
	dp[k][0][0][0]=min(val[k]+w2[lsteg]+val[fa],w1[lsteg]);
	dp[k][0][1][1]=min(val[k]+w1[lsteg]+val[fa],w2[lsteg]);
	dp[k][0][0][1]=min(val[k]+w2[lsteg],w1[lsteg]+val[fa]);
	dp[k][0][1][0]=min(val[k]+w1[lsteg],w2[lsteg]+val[fa]);
	for (int i=1;i<=20;i++)
		for (int x=0;x<=1;x++)
			for (int y=0;y<=1;y++)
				for (int z=0;z<=1;z++)
					dp[k][i][x][y]=min(dp[k][i][x][y],dp[k][i-1][x][z]+dp[st[k][i-1]][i-1][z][y]);
	for (auto U:G[k])
	{
		int u=U.fi,id=U.se;
		if (u==fa) continue;
		dfs(u,k,id);
	}
}
int LCA(int x,int y)
{
	if (dep[x]<dep[y]) swap(x,y);
	for (int i=20;i>=0;i--)
		if (dep[st[x][i]]>=dep[y]) x=st[x][i];
	if (x==y) return x;
	for (int i=20;i>=0;i--)
		if (st[x][i]!=st[y][i]) x=st[x][i],y=st[y][i];
	return st[x][0];
}
int work(int x,int y)
{
	int lca=LCA((x+1)/2,(y+1)/2);
	int a=val[(x+1)/2],b=val[(x+1)/2];
	if (x%2==1) a=0; else b=0;
	x=(x+1)/2;
	for (int i=20;i>=0;i--)
		if (dep[st[x][i]]>=dep[lca])
		{
			int aa=a,bb=b;
			a=min(aa+dp[x][i][0][0],bb+dp[x][i][1][0]);
			b=min(aa+dp[x][i][0][1],bb+dp[x][i][1][1]);
			x=st[x][i];
		}
	int A=val[(y+1)/2],B=val[(y+1)/2];
	if (y%2==1) A=0; else B=0;
	y=(y+1)/2;
	for (int i=20;i>=0;i--)
		if (dep[st[y][i]]>=dep[lca])
		{
			int aa=A,bb=B;
			A=min(aa+dp[y][i][0][0],bb+dp[y][i][1][0]);
			B=min(aa+dp[y][i][0][1],bb+dp[y][i][1][1]);
			y=st[y][i];
		}
	return min(A+a,B+b);
}
signed main()
{
	n=read();
	for (int i=1;i<=n;i++) val[i]=read();
	memset(dp,0x3f,sizeof(dp));
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		w1[i]=read(),w2[i]=read();
		ad(u,v,i);
		ad(v,u,i);
	}
	init(1,0);
	init1(1,0);
	dfs(1,0,0);
	q=read();
	while (q--)
	{
		x=read(),y=read();
		writeln(work(x,y));
	}
}
/*

*/