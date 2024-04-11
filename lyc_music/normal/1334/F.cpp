//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define ll long long
#define F(i,a,b) for (int i=(a);i<=(b);i++)
#define R(i,a,b) for (int i=(a);i<(b);i++)
#define D(i,a,b) for (int i=(a);i>=(b);i--)
#define go(i,x) for (int i=head[x];i;i=e[i].nx)
#define IOS ios::sync_with_stdio(false)
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
#define N 500005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int c[N],a[N],b[N];
int p[N],dp[N];
int n,m;
vector<int>G[N];
void update(int x,int y)
{
	while (x<=n)
	{
//		cout<<x<<endl;
		c[x]+=y;
		x+=(x&-x);
	}
}
int query(int x)
{
	int res=0;
	while (x)
	{
		res+=c[x];
		x-=(x&-x);
	}
	return res;
}
int sum(int x,int y)
{
	if (x>y) return 0;
	return query(y)-query(x-1);
}
signed main()
{
	n=read();
	for (int i=1;i<=n;i++) 
		a[i]=read(),G[a[i]].push_back(i);
	for (int i=1;i<=n;i++) 
	{
		p[i]=read(),update(i,p[i]);
	}
	G[0].push_back(0);
	G[n+1].push_back(n+1);
	m=read();
	for (int i=1;i<=m;i++) b[i]=read();
	b[++m]=n+1;
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	for (int i=1;i<=m;i++)
	{
		int l=0;
//		cout<<"!"<<i<<endl;
		if (i>1)
		{
			for (int j=b[i-2]+1;j<=b[i-1];j++)
				for (auto u:G[j])
				{
					if (p[u]>0) update(u,-p[u]);
				}
		}
//		cout<<"!"<<i<<endl;
		for (int j=0;j<G[b[i]].size();j++)
		{
			while (l<G[b[i-1]].size()&&G[b[i-1]][l]<G[b[i]][j])
			{
				dp[G[b[i]][j]]=min(dp[G[b[i]][j]],dp[G[b[i-1]][l]]+sum(G[b[i-1]][l]+1,G[b[i]][j]-1));
				l++;
			}
			if (j)
				dp[G[b[i]][j]]=min(dp[G[b[i]][j]],dp[G[b[i]][j-1]]+sum(G[b[i]][j-1],G[b[i]][j]-1));
		}
	}
//	for (int i=1;i<=n;i++) 
//		cout<<dp[i]<<" ";
	if (dp[n+1]>1e15) puts("NO");
	else puts("YES"),writeln(dp[n+1]);
}
/*

*/