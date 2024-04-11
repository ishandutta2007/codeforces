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
#define N 400005
#define B 450
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int b[1005][1005];
int n,m,a[N],x[N],y[N],s[N];
int ans;
signed main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++)
	{
		x[i]=read(),y[i]=read();
	}
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		if (u==1)
		{
			if (x[v]+y[v]<=B)
			{
				int z=x[v]+y[v];
				for (int j=i+x[v];j<i+x[v]+y[v];j++)
					b[z][j%z]++;
			}
			else
			{
				for (int j=i;j<=m;j+=x[v]+y[v])
				{
					if (j+x[v]<=m) s[j+x[v]]++;
					if (j+x[v]+y[v]<=m)s[j+x[v]+y[v]]--;
				}
			}
			a[v]=i;
		}
		else
		{
			if (x[v]+y[v]<=B)
			{
				int z=x[v]+y[v];
				for (int j=a[v]+x[v];j<a[v]+x[v]+y[v];j++)
					b[z][j%z]--;
			}
			else
			{
				for (int j=a[v];j<=m;j+=x[v]+y[v])
				{
					if (j+x[v]<=m)s[j+x[v]]--;
					if (j+x[v]+y[v]<=m) s[j+x[v]+y[v]]++;
					if (j+x[v]<i-1&&j+x[v]+y[v]>=i-1) s[i]--;
				}
			}
		}
		s[i]+=s[i-1];
		ans=s[i];
		for (int j=1;j<=B;j++)
			ans+=b[j][i%j];
		writeln(ans);
	}
				
					
}
/*

*/