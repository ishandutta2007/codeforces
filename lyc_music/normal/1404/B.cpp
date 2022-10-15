//The Hunting Party - Keys To The Kingdom
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
#define N 100005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int dep[N],f[N];
vector<int>G[N];
int maxdis,n,a,b,la,lb;
void ad(int x,int y)
{
	G[x].push_back(y);
}
void dfs(int k,int fa)
{
	dep[k]=dep[fa]+1;
	f[k]=0;
	int x=0,y=0;
	for (auto u:G[k])
	{
		if (u==fa) continue;
		dfs(u,k);
		f[k]=max(f[k],f[u]+1);
		if (f[u]+1>x) y=x,x=f[u]+1;
		else y=max(y,f[u]+1);
	}
	maxdis=max(maxdis,x+y);
}
void LYC_music()
{
	n=read(),a=read(),b=read(),la=read(),lb=read();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		ad(u,v);
		ad(v,u);
	}
	maxdis=0;
	dfs(a,0);
	if (dep[b]-1<=la) puts("Alice");
	else
	{
		if ((maxdis+1)/2>la&&lb>2*la) puts("Bob");
		else puts("Alice");
	}
	for (int i=1;i<=n;i++) G[i].clear(),f[i]=0;
}
signed main()
{
	int T=read();
	while (T--)
	{
		LYC_music();
	}
}
/*

*/