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
#define N 200005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,q,s,d,a[N],f[N],dis[N],tot;
vector<int>G[N];
vector<pa>G1[N];
set<pa>S;
struct node
{
	int u,v,w;
};
vector<node>E;
bool cmp(node x,node y)
{
	return x.w<y.w;
}
int gf(int x)
{
	if (f[x]==x) return x;
	return f[x]=gf(f[x]);
}
void ad(int x,int y,int w)
{
	G1[x].push_back({y,w});
}
void dfs(int k,int fa)
{
	for (auto U:G1[k])
	{
		int u=U.fi,w=U.se;
		if (u==fa) continue;
		dis[u]=max(dis[k],w);
		dfs(u,k);
	}
}
signed main()
{
	n=read(),q=read(),s=read(),d=read();
	for (int i=1;i<=n;i++) a[i]=read(),f[i]=i,S.insert({a[i],i});
	while (tot!=n-1)
	{
		E.clear();
		for (int i=1;i<=n;i++) G[f[i]].push_back(i);
		for (int i=1;i<=n;i++)
		{
			if (!G[i].size()) continue;
			for (auto u:G[i])
			{
				S.erase(S.find({a[u],u}));
			}
			for (auto u:G[i])
			{
				auto it=S.lower_bound({a[u]+d,0});
				if (it!=S.end()) E.push_back({u,(*it).se,abs(abs((*it).fi-a[u])-d)});
				if (it!=S.begin())
				{
					it--;E.push_back({u,(*it).se,abs(abs((*it).fi-a[u])-d)});
				}
				it=S.lower_bound({a[u]-d,0});
				if (it!=S.end())E.push_back({u,(*it).se,abs(abs((*it).fi-a[u])-d)});
				if (it!=S.begin())
				{
					it--;E.push_back({u,(*it).se,abs(abs((*it).fi-a[u])-d)});
				}
			}
			for (auto u:G[i])
			{
				S.insert({a[u],u});
			}
		}
		sort(E.begin(),E.end(),cmp);
		for (auto U:E)
		{
			int x=U.u,y=U.v,w=U.w;
			if (gf(x)==gf(y)) continue;
			ad(x,y,w),ad(y,x,w),f[f[x]]=f[y];tot++;
		}
	}
	dfs(s,0);
	while (q--)
	{
		int x=read(),y=read();
		swap(x,y);
		if (dis[y]<=x) puts("Yes");
		else puts("No");
	}
}
/*

*/