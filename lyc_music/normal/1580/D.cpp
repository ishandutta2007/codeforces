//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define re register
#define inf 1e18
#define mod 998244353
#define int ll
#define N 4005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int ls[N],rs[N],a[N],siz[N],dp[N][N];
int n,m,rt;
int build(int l,int r)
{
	if (l>r) return 0;
	int now=inf,x=0;
	for (int i=l;i<=r;i++)
		if (a[i]<now) now=a[i],x=i;
	ls[x]=build(l,x-1);
	rs[x]=build(x+1,r);
	return x;
}
void dfs(int k)
{
	siz[k]=1;
	memset(dp[k],0xc0,sizeof(dp[k]));
	dp[k][0]=0;
	dp[k][1]=0;
	if (ls[k])
	{
		dfs(ls[k]);
		for (int i=siz[k];i>=0;i--)
			for (int j=siz[ls[k]];j>=0;j--)
				dp[k][i+j]=max(dp[k][i+j],dp[k][i]+dp[ls[k]][j]+(m-j)*j*(a[ls[k]]-a[k]));
		siz[k]+=siz[ls[k]];
	}
	if (rs[k])
	{
		dfs(rs[k]);
		for (int i=siz[k];i>=0;i--)
			for (int j=siz[rs[k]];j>=0;j--)
				dp[k][i+j]=max(dp[k][i+j],dp[k][i]+dp[rs[k]][j]+(m-j)*j*(a[rs[k]]-a[k]));
		siz[k]+=siz[rs[k]];
	}
}
signed main()
{
	n=read();m=read();
	for (int i=1;i<=n;i++) a[i]=read();
	rt=build(1,n);
	dfs(rt);
	writeln(dp[rt][m]);
}
/*

*/