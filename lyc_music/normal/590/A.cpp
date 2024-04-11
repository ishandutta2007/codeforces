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
//#define int ll
#define N 2000005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int a[N],b[N],c[N],d[N],l,r;
pa g[N];
int n,ans;
signed main()
{
	n=read();
	for (re int i=1;i<=n;i++) c[i]=read();
	int l=0;
	for (re int i=1;i<=n;i++)
	{
		g[++l]={i,0};
		int m=0;
		while (c[i+1]^c[i]==1&&i+1<=n) i++,m++;
		g[l].se=i;ans=max(ans,m>>1);
	}
	for (int p=1;p<=l;p++)
	{
		pa u=g[p];
		for (re int i=u.fi;i<=u.fi+(u.se-u.fi)/2;i++) d[i]=c[u.fi];
		for (re int i=u.fi+(u.se-u.fi)/2+1;i<=u.se;i++) d[i]=c[u.se];
	}
	writeln(ans);
	for (re int i=1;i<=n;i++) writesp(d[i]);
}
/*

*/