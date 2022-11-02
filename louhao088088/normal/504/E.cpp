// Problem: CF504E Misha and LCP on Tree
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF504E
// Memory Limit: 500 MB
// Time Limit: 8000 ms
// 2021-11-15 18:03:43
// Author : louhao088
// 
// Powered by CP Editor (https://cpeditor.org)
#pragma GCC optimize(3,"Ofast","inline")
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ls (rt<<1)
#define rs (rt<<1|1)
#define lowbit (x&-x)
#define int long long
const int maxn=3e5+5,M=34005,base1=197,base2=233,mod=2020051021,mod2=1396716913;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
inline void print(int x)
{
    static int a[55];int top=0;
    if(x<0) putchar('-'),x=-x;
    do{a[top++]=x%10,x/=10;}while(x);
    while(top) putchar(a[--top]+48);
}
int n,m,u,v,s[maxn],s2[maxn],x,y,x2,y2,lca,lca2,dfn[maxn*2],cnt=0;
int st[maxn*2][22],h3[maxn],h4[maxn],h[maxn],h2[maxn],inv1[maxn],inv2[maxn];
int son[maxn],dep[maxn],lg[maxn*2],f[maxn][22],top[maxn],d[maxn];
vector<int>e[maxn];
int *up[maxn],*dn[maxn];
int Pow(int x,int y,int mod){int res=1;while(y){if(y&1)res=res*x%mod;x=x*x%mod;y=y/2;}return res;}
char a[maxn];
long long res;
void dfs(int x,int fa)
{
	//cout<<x<<" "<<fa<<endl;
	st[++cnt][0]=x;dfn[x]=cnt;
	d[x]=d[fa]+1;dep[x]=d[x];f[x][0]=fa;
	h[x]=(h[fa]*base1+a[x])%mod;
	h2[x]=(h2[fa]+s[d[x]-1]*a[x])%mod;
	h3[x]=(h3[fa]*base2+a[x])%mod2;
	h4[x]=(h4[fa]+s2[d[x]-1]*a[x])%mod2;
	for(int i=0;f[x][i];i++)f[x][i+1]=f[f[x][i]][i];
	for(auto i:e[x])
		if(i^fa)
		{
			dfs(i,x);st[++cnt][0]=x;
			if(dep[i]>dep[x])dep[x]=dep[i],son[x]=i;
		}
}
void dfs2(int x,int p)
{
	top[x]=p;
	if(x==p)
	{
		up[x]=new int[dep[x]-d[x]+2];
		dn[x]=new int[dep[x]-d[x]+2];
		*up[x]=*dn[x]=x;
		for(int i=0,o=x;i<=dep[x]-d[x];i++)
			up[x][i]=o,o=f[o][0];
		for(int i=0,o=x;i<=dep[x]-d[x];i++)
			dn[x][i]=o,o=son[o];
	}
	if(son[x])dfs2(son[x],p);
	for(auto i:e[x])if(i!=son[x]&&i!=f[x][0])dfs2(i,i);
	
}
int getmin(int a,int b){return d[a]<d[b]?a:b;}
void init()
{
	for(int i=2;i<2*n;i++)lg[i]=lg[i>>1]+1;
	for(int t=1;1<<t<=cnt;t++)
		for(int i=1;i+(1<<t)<=cnt;i++)
			st[i][t]=getmin(st[i][t-1],st[i+(1<<(t-1))][t-1]);
}
int Lca(int u,int v)
{
	if(dfn[u]>dfn[v])swap(u,v);
	int uu=dfn[u],vv=dfn[v],len=vv-uu+1;
	return getmin(st[uu][lg[len]],st[vv-(1<<lg[len])+1][lg[len]]);
}
int getf(int x,int k)
{
	if(d[x]<=k)return 0;
	if(!k)return x;
	x=f[x][lg[k]];k-=1<<lg[k];
	k-=d[x]-d[top[x]],x=top[x];
	return k>=0?up[x][k]:dn[x][-k];
}
int get1(int dis,int x,int y,int lca)
{
	//cout<<x<<" "<<y<<" "<<lca<<" "<<dis<<endl;
	if(dis<=d[x]-d[lca]+1)
	{
		int z=getf(x,dis),g;
		//cout<<z<<endl;
		g=h2[x]-h2[z]+mod;g=g%mod*inv1[d[z]]%mod;
		return g;
	}
	else 
	{
		int g;
		g=h2[x]-h2[f[lca][0]]+mod;g=g%mod*inv1[d[f[lca][0]]]%mod;
		//cout<<g<<" "<<x<<" "<<y<<endl;
		int ds=d[x]+d[y]-2*d[lca]+1;
		int z=getf(y,ds-dis);
		//cout<<z<<endl;
		int o=(h[z]-h[lca]*s[d[z]-d[lca]]%mod+mod)%mod;
		//cout<<o<<endl;
		return (g*s[d[z]-d[lca]]%mod+o)%mod;
	}
}
int get2(int dis,int x,int y,int lca)
{
	//cout<<dis<<" "<<x<<" "<<y<<endl;
	if(dis<=d[x]-d[lca]+1)
	{
		int z=getf(x,dis),g;
		g=h4[x]-h4[z]+mod2;g=g%mod2*inv2[d[z]]%mod2;
		//cout<<z<<" "<<g<<endl;
		return g;
	}
	else 
	{
		int g;
		g=h4[x]-h4[f[lca][0]]+mod2;g=g%mod2*inv2[d[f[lca][0]]]%mod2;
		int ds=d[x]+d[y]-2*d[lca]+1;
		int z=getf(y,ds-dis);
		int o=(h3[z]-h3[lca]*s2[d[z]-d[lca]]%mod2+mod2)%mod2;
		return (g*s2[d[z]-d[lca]]%mod2+o)%mod2;
	}
}
bool check(int mid)
{
	//cout<<mid<<endl;
	int g1=get1(mid,x,y,lca);int g2=get1(mid,x2,y2,lca2);
//	cout<<g1<<" "<<g2<<" "<<mid<<endl;
	if(g1!=g2)return false;
	g1=get2(mid,x,y,lca),g2=get2(mid,x2,y2,lca2);
	//cout<<g1<<" "<<g2<<" "<<mid<<endl;
	if(g1!=g2)return false;
	return true;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	scanf("%s",a+1);
	for(int i=1;i<n;i++)u=read(),v=read(),e[u].push_back(v),e[v].push_back(u);
	s[0]=1,s2[0]=1;inv1[0]=1,inv2[0]=1;
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]*base1%mod;inv1[i]=Pow(s[i],mod-2,mod);
		s2[i]=s2[i-1]*base2%mod2;inv2[i]=Pow(s2[i],mod2-2,mod2);
	}
	//cout<<inv2[1]*s2[1]%mod2<<endl;
	dfs(1,0);
	//return 0;
	dfs2(1,1);
	init();
	m=read();
	for(int i=1;i<=m;i++)
	{
		x=read(),y=read();x2=read(),y2=read();
		lca=Lca(x,y),lca2=Lca(x2,y2);
		int l=1,r=min(d[x]+d[y]-2*d[lca],d[x2]+d[y2]-2*d[lca2])+1,res=0;
		while(l<=r)
		{
			//cout<<l<<" "<<r<<endl;
			int mid=l+r>>1;
			if(check(mid))l=mid+1,res=mid;
			else r=mid-1;
		}
		print(res);puts("");
	}
 	return 0;
}