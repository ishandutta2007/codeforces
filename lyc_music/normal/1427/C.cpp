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
int n,m,x[N],y[N],t[N],dp[N],f[N];
int dis(int i,int j)
{
	return abs(x[i]-x[j])+abs(y[i]-y[j]);
}
signed main()
{
	n=read();m=read();
	x[0]=y[0]=1;
	for (int i=1;i<=m;i++)
	{
		t[i]=read(),x[i]=read(),y[i]=read();
		dp[i]=-m*114;
		for (int j=max(0ll,i-2*n);j<i;j++)
			if (dis(i,j)<=t[i]-t[j])
				dp[i]=max(dp[i],dp[j]+1);
		if (i-2*n>=0) dp[i]=max(dp[i],f[i-2*n]+1);
		f[i]=max(f[i-1],dp[i]);
	}
	writeln(f[m]);
}
/*

*/