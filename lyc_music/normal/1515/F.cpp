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
#define N 300005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,m,X,a[N],sum,vis[N];
vector<int>ans,ans1;
vector<pa>G[N];
void dfs(int k,int fa,int las)
{
//	cout<<k<<" "<<fa<<" "<<las<<endl;
	vis[k]=1;
	for (auto U:G[k])
	{
		int u=U.fi,id=U.se;
		if (u==fa||vis[u]) continue;
		dfs(u,k,id);
	}
	if (k==1) return;
	if (a[k]>=X)
	{
		ans.push_back(las);
		a[fa]=a[fa]+a[k]-X;
	}
	else
	{
		ans1.push_back(las);
	}
}
signed main()
{
	n=read(),m=read();X=read();
	for (int i=1;i<=n;i++) a[i]=read(),sum+=a[i];
	if (sum<(n-1)*X) return puts("NO"),0;
	for (int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		G[x].push_back({y,i});
		G[y].push_back({x,i});
	}
	dfs(1,0,0);
	for (int i=1;i<=n;i++)
		if (!vis[i]) return puts("NO"),0;
	puts("YES");
	for (auto u:ans) writeln(u);
	if (!ans1.empty())
	{
		for (int i=ans1.size()-1;i>=0;i--)
		{
			writeln(ans1[i]);
		}
	}
}
/*

*/