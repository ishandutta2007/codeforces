//~~
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
//#define int ll
#define N 500005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int s[N];
vector<pa>G[N];
int siz[N];
int son[N];
int ans[N];
int p[5000005];
int dep[N];
int n;
void ad(int x,int y,int w)
{
	G[x].push_back(mp(y,w));
}
void dfs(int k,int fa)
{
	dep[k]=dep[fa]+1;
	siz[k]=1;
	for (auto U:G[k])
	{
		int u=U.fi,w=U.se;
		if (u==fa) continue;
		s[u]=s[k]^(1<<w);
		dfs(u,k);
		siz[k]+=siz[u];
		if (siz[u]>siz[son[k]]) son[k]=u;
	}
}
void clr(int k,int fa)
{
	p[s[k]]=-inf;
	for (auto U:G[k])
	{
		int u=U.fi;
		if (u==fa) continue;
		clr(u,k);
	}
}
void ins(int k,int fa)
{
	p[s[k]]=max(p[s[k]],dep[k]);
	for (auto U:G[k])
	{
		int u=U.fi;
		if (u==fa) continue;
		ins(u,k);
	}
}
void qry(int k,int fa,int rt)
{
	// cout<<"qry "<<k<<" "<<fa<<" "<<rt<<endl;
	ans[rt]=max(ans[rt],p[s[k]]-dep[rt]*2+dep[k]);
	for (int i=0;i<22;i++)
	{
		// cout<<rt<<" "<<fa<<" "<<p[s[k]^(1<<i)]-dep[rt]*2+dep[k]<<" "<<k<<" "<<p[s[k]^(1<<i)]<<endl;
		ans[rt]=max(ans[rt],p[s[k]^(1<<i)]-dep[rt]*2+dep[k]);
	}
	for (auto U:G[k])
	{
		int u=U.fi;
		if (u==fa) continue;
		qry(u,k,rt);
	}
}
void dfs2(int k,int fa)
{
	for (auto U:G[k])
	{
		int u=U.fi,w=U.se;
		if (u==fa||u==son[k]) continue;
		dfs2(u,k);
		ans[k]=max(ans[k],ans[u]);
		clr(u,k);
	}
	if (son[k]) dfs2(son[k],k);
	ans[k]=max(ans[k],ans[son[k]]);
	ans[k]=max(ans[k],p[s[k]]-dep[k]);
	for (int i=0;i<22;i++)	
	{
		ans[k]=max(ans[k],p[s[k]^(1<<i)]-dep[k]);
		// cout<<k<<" "<<i<<" "<<p[s[k]^(1<<i)]-dep[k]<<endl;
	}
	p[s[k]]=max(p[s[k]],dep[k]);
	for (auto U:G[k])
	{
		int u=U.fi,w=U.se;
		if (u==fa||u==son[k]) continue;
		qry(u,k,k);
		ins(u,k);
	}
}
void BellaKira()
{
	cin>>n;
	for (int i=0;i<(1<<22);i++) p[i]=-inf;
	for (int i=2;i<=n;i++)
	{
		int x;
		char ch;
		cin>>x>>ch;
		ad(x,i,ch-'a');
	}
	dfs(1,0);
	dfs2(1,0);
	for (int i=1;i<=n;i++) cout<<ans[i]<<" ";
}
signed main()
{
	IOS;
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}
/*

*/