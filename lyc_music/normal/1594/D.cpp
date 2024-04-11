//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define re register
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
vector<pa>G[N];
int f[N][2];
int fa[N];
string st;
int dep[N];
int z;
int T,n,m,x,y,ans;
map<pa,int>Mp;
int gf(int x)
{
	if (x==fa[x]) return x;
	return fa[x]=gf(fa[x]);
}
void ad(int x,int y,int z)
{G[x].push_back({y,z});
}
void dfs(int k,int fa)
{
	f[k][0]=0;f[k][1]=1;
	for (auto U:G[k])
	{
		int u=U.fi,w=U.se;
		if (u==fa) continue;
//		cout<<k<<"->"<<u<<" "<<w<<endl;
		dep[u]=dep[k]^w;
		dfs(u,k);
		for (int i=0;i<=1;i++)
			f[k][i]+=f[u][i^w];
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin>>T;
	while (T--)
	{
		cin>>n>>m;ans=1;
		vector<pair<pa,int>>g;
		int tot=0;
		for (int i=1;i<=n;i++) fa[i]=i;
		for (int i=1;i<=m;i++)
		{
			cin>>x>>y>>st;
			if (st=="imposter")
			{
				z=1;
			} else z=0;
			if (Mp.count({x,y}))
			{
				if (Mp[{x,y}]!=z) ans=0;
			} else
			{	
				
				if (gf(x)!=gf(y)) 
				{
					ad(x,y,z);
					ad(y,x,z);
					fa[gf(x)]=gf(y);
				} else g.push_back({{x,y},z});
				Mp[{x,y}]=Mp[{y,x}]=z;
			}
		}
		if (!ans) puts("-1");
		else
		{
			int sm=0;
			for (int i=1;i<=n;i++)
				if (gf(i)==i)
				{
					dep[i]=0;
					dfs(i,0);
					sm+=max(f[i][0],f[i][1]);
				}
			for (auto u:g)
			{
//				cout<<dep[u.fi.fi]<<" "<<dep[u.fi.se]<<endl;
				if ((dep[u.fi.fi]^dep[u.fi.se])!=u.se) ans=0;
			}
			if (!ans) puts("-1");
			else
			writeln(sm);
		}
		for (int i=1;i<=n;i++) G[i].clear();
		Mp.clear();
	}
}
/*

*/