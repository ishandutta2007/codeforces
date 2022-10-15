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
#define int ll
#define N 200005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int T,n,K;
set<int>G[N],E[N];
int yz[N],s[N];
int vis[N];
queue<int>q;
void ad(int x,int y)
{
	G[x].insert(y);
}
signed main()
{
	T=read();
	while (T--)
	{
		n=read();K=read();
		int ans=0;
		for (int i=1;i<n;i++)
		{
			int u=read(),v=read();
			ad(u,v);
			ad(v,u);
		}
		for (int i=1;i<=n;i++)
			if (G[i].size()==1)
			{
				yz[i]=1;
			}
		for (int i=1;i<=n;i++)
		{
			s[i]=0;
			for (auto u:G[i])
			{
				s[i]+=yz[u];
				if (yz[u]) E[i].insert(u);
			}
			if (s[i]>=K) q.push(i);
		}
		while (!q.empty())
		{
			int u=q.front();
			q.pop();
			if (vis[u]) continue;
			ans++;
			s[u]-=K;
			auto it=E[u].begin();
			for (int tp=1;tp<=K;tp++)
			{
				auto it1=it;
				it++;
				G[u].erase(G[u].find(*it1));
				vis[*it1]=1;
				E[u].erase(it1);
			}
			if (s[u]>=K) q.push(u);
			else
			{
				if (G[u].size()==1)
				{
					int v=(*G[u].begin());
					s[v]++;
					E[v].insert(u);
					if (s[v]==K) q.push(v);
				}
			}
		}
		for (int i=1;i<=n;i++) s[i]=yz[i]=0,E[i].clear(),G[i].clear(),vis[i]=0;
		writeln(ans);
	}
				
				
		
}
/*
1236123
2 1
1 2
*/