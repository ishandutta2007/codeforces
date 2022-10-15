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
#define inf 1e18
#define mod 998244353
#define int ll
#define N 500005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int st[N][25];
int dep[N];
int ans[N];
int n;
int ds;
vector<int>G[N],Q[N];
void ad(int x,int y)
{
	G[x].push_back(y);
}
int lca(int x,int y)
{
	if (dep[x]<dep[y]) swap(x,y);
	for (int i=20;i>=0;i--)
		if (dep[st[x][i]]>=dep[y]) x=st[x][i];
	if (x==y) return x;
	for (int i=20;i>=0;i--)
		if (st[x][i]!=st[y][i]) x=st[x][i],y=st[y][i];
	return st[x][0];
}
int dis(int x,int y)
{
	return dep[x]+dep[y]-dep[lca(x,y)]*2;
}
void dfs(int k,int fa)
{
	st[k][0]=fa;
	dep[k]=dep[fa]+1;
	Q[dep[k]].push_back(k);
	ans[0]=max(ans[0],dep[k]);
	for (int i=1;i<=20;i++)
		st[k][i]=st[st[k][i-1]][i-1];
	for (auto u:G[k])
	{
		if (u==fa) continue;
		dfs(u,k);
	}
}
void BellaKira()
{
	n=read();
	for (int i=1;i<n;i++)
	{
		int x=read(),y=read();
		ad(x,y);
		ad(y,x);
	}
	dep[0]=-1;
	dfs(1,0);
	ds=0;
	int x=0,y=0;
	for (int i=1;i<=n;i++) ans[i]=ans[0];
	for (int i=n;i>=1;i--)
	{
		for (auto u:Q[i])
		{
			if (!x) x=u;
			else
			if (!y)
			{
				y=u;
				ds=dis(x,y);
			}
			else
			{
				if (dis(x,u)>dis(y,u))
				{
					if (dis(x,u)>ds)
					{
						y=u;
						ds=dis(x,y);
					}
				} else
				{
					if (dis(y,u)>ds)
					{
						x=u;
						ds=dis(x,y);
					}
				}
					
			}
		}
        if(i-1-(ds+1)/2>=0) ans[i-1-(ds+1)/2]=i-1;
    }
    for (int i=n-1;i>=1;i--) ans[i]=min(ans[i],ans[i+1]);
    for (int i=1;i<=n;i++) writesp(ans[i]);
    puts("");
    for (int i=0;i<=n;i++) Q[i].clear(),G[i].clear(),ans[i]=0;
		
}
signed main()
{
	int T=read();
	while (T--)
	{
		BellaKira();
	}
}
/*

*/