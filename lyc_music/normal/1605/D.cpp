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
#define N 200005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
vector<int>g[2],G[N],a[25],g1,g2,g3;
int dep[N],b[25];
int ans[N];
int n;
void ad(int x,int y)
{
	G[x].push_back(y);
}
bool cmp(int x,int y)
{
	return dep[x]<dep[y];
}
void dfs(int k,int fa)
{
	dep[k]=dep[fa]+1;
	g[dep[k]%2].push_back(k);
	for (auto u:G[k])
	{
		if (u==fa) continue;
		dfs(u,k);
	}
}
void LYC_music()
{
	n=read();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		ad(u,v);
		ad(v,u);
	}
	if (n==1)
	{
		puts("1");
		return;
	}
	dfs(1,0);
	for (int i=1;i<=n;i++)
	{
		for (int j=20;j>=0;j--)
			if ((i>>j)&1)
			{
				a[j].push_back(i);
				b[j]++;
//				cout<<"?"<<j<<endl;
				break;
			}
	}
	if (g[0].size()<g[1].size()) swap(g[0],g[1]);
	for (int j=0;j<=20;j++)
		if ((g[1].size()>>(j))&1)
		{
			for (auto u:a[j]) g1.push_back(u);
		} else
		{
			for (auto u:a[j]) g2.push_back(u);
		}
	for (auto u:g[1])
	{
		ans[u]=g1.back();
		g1.pop_back();
	}
	for (auto u:g[0])
	{
		ans[u]=g2.back();
		g2.pop_back();
	}
	for (int i=1;i<=n;i++) writesp(ans[i]);
	puts("");
	for (int i=1;i<=n;i++) G[i].clear();
	for (int i=0;i<=20;i++) b[i]=0,a[i].clear();
	g1.clear();g2.clear();g3.clear();
	g[0].clear(),g[1].clear();
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
1
14
5 9
9 14
7 9
4 9
9 11
9 12
2 9
9 8
9 3
13 9
10 9
1 9
9 6
*/