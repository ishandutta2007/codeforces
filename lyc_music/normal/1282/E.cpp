//QwQcOrZ yyds!!!
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
#define N 1200005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
vector<pa>G[N];
struct
{
	int a,b,c;
}E[N];
map<pa,int>Mp;
int du[N],du1[N],vis[N];
set<int>S[N];
int T,n,m;
pa eg[N];
void dfs(int k,int fa)
{
	writesp(k);
	for (auto U:G[k])
	{
		int u=U.fi,w=U.se;
		if (u==fa) continue;
		if (vis[w]||u==1) continue;
		dfs(u,k);
		break;
	}
}
void ad(int x,int y,int w)
{
	G[x].push_back({y,w});
}
void addeg(int x,int y)
{
	if (x>y) swap(x,y);
	if (!Mp.count({x,y})) du[x]++,du[y]++;
	eg[++m]={x,y};
	Mp[{x,y}]++;
}
signed main()
{
	T=read();
	while (T--)
	{
		n=read();m=0;Mp.clear();
		set<int>q;
		vector<int>ans;
		for (int i=1;i<=n-2;i++)
		{
			E[i].a=read(),E[i].b=read(),E[i].c=read();
			S[E[i].a].insert(i);
			S[E[i].b].insert(i);
			S[E[i].c].insert(i);
			addeg(E[i].a,E[i].b);
			addeg(E[i].c,E[i].b);
			addeg(E[i].a,E[i].c);
		}
		for (int i=1;i<=m;i++)
		{
			vis[i]=0;
			if (Mp[{min(eg[i].fi,eg[i].se),max(eg[i].fi,eg[i].se)}]>1) vis[i]=1;
			else
			{
				ad(eg[i].fi,eg[i].se,i);
				ad(eg[i].se,eg[i].fi,i);
			}
		}
		for (int i=1;i<=n;i++)
			if (du[i]==2)
			{
				q.insert(*S[i].begin());
			}
		while (!q.empty())
		{
			int u=(*q.begin());
			q.erase(q.begin());
			S[E[u].a].erase(u);
			S[E[u].b].erase(u);
			S[E[u].c].erase(u);
			int i=u;
			if (du[E[u].a]==2)
			{
				du[E[i].b]--,du[E[i].c]--;
				if (du[E[i].b]==2)
				{
					q.insert(*S[E[i].b].begin());
				}
				if (du[E[i].c]==2)
				{
					q.insert(*S[E[i].c].begin());
				}
			}else
			if (du[E[u].b]==2)
			{
				du[E[i].a]--,du[E[i].c]--;
				if (du[E[i].a]==2)
				{
					q.insert(*S[E[i].a].begin());
				}
				if (du[E[i].c]==2)
				{
					q.insert(*S[E[i].c].begin());
				}
			}else
			if (du[E[u].c]==2)
			{
				du[E[i].b]--,du[E[i].a]--;
				if (du[E[i].a]==2)
				{
					q.insert(*S[E[i].a].begin());
				}
				if (du[E[i].b]==2)
				{
					q.insert(*S[E[i].b].begin());
				}
			}
			ans.push_back(u);
		}
		dfs(1,0);
		puts("");
		for (auto u:ans) writesp(u);
		puts("");
		for (int i=1;i<=n;i++) S[i].clear(),du[i]=0,G[i].clear();
	}
}
/*
1123
4
1 2 3
2 3 4

*/