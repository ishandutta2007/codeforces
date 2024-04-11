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
#define N 400005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int T,n,m,du[N],dis[N],vis[N];
vector<int>G[N];
void ad(int x,int y)
{
	G[x].push_back(y);
}
signed main()
{
	T=read();
	while (T--)
	{
		n=read();m=read();
		if (n==1) 
		{
			puts("0");
			continue;
		}
		for (int i=1;i<n;i++)
		{
			int u=read(),v=read();
			ad(u,v);
			ad(v,u);
			du[u]++,du[v]++;
		}
		queue<int>q;
		for (int i=1;i<=n;i++)
		{
			vis[i]=0;dis[i]=0;
			if (du[i]==1) q.push(i),vis[i]=1;
		}
		while (!q.empty())
		{
			int u=q.front();
			q.pop();
//			cout<<u<<","<<dis[u]<<endl;
			if (dis[u]==m-1) continue;
			for (auto v:G[u])
			{
				du[v]--;
				if (du[v]==1)
				{
					if (!vis[v])
					{
						vis[v]=1;
						dis[v]=dis[u]+1;
						q.push(v);
					}
				}
			}
		}
		int ans=0;
		for (int i=1;i<=n;i++)
			ans+=(vis[i]^1),G[i].clear(),du[i]=0;
		writeln(ans);
	}
}
/*
1
7 3
1 2
2 3
3 4
4 5
5 6
6 7
*/