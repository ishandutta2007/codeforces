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
int f[N],yez[N],son[N],T,n,ans;
queue<int>q;
vector<int>G[N];
void ad(int x,int y)
{
	G[x].push_back(y);
}
void dfs(int k,int fa)
{
	f[k]=fa;
	for (auto u:G[k])
	{
		if (u==fa) continue;
		son[k]++;
		dfs(u,k);
		if (son[u]==0) yez[k]++;
	}
}
signed main()
{
	T=read();
	while (T--)
	{
		n=read();ans=0;
		for (int i=1;i<n;i++)
		{
			int u=read(),v=read();
			ad(u,v);
			ad(v,u);
		}
		dfs(1,0);
		for (int i=1;i<=n;i++)
			if (son[i]==yez[i]&&son[i]) q.push(i);
		while (!q.empty())
		{
			int u=q.front();
//			cout<<u<<endl;
			ans+=yez[u]-1;
			q.pop();
			son[f[u]]--;
			if (son[f[u]]!=0)
			{
				if (son[f[u]]==yez[f[u]]) q.push(f[u]);
			} else
			{
				if (!f[f[u]]) continue;
				yez[f[f[u]]]++;
				if (son[f[f[u]]]==yez[f[f[u]]]) q.push(f[f[u]]);
			}
		}
		writeln(ans+1);
		for (int i=1;i<=n;i++) yez[i]=son[i]=f[i]=0,G[i].clear();
	}
}
/*

*/