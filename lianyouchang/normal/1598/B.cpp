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
int T,n,b[6][N];
int ans;
signed main()
{
	T=read();
	while (T--)
	{
		n=read();ans=0;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=5;j++)
				b[j][i-1]=read();
		for (int i=1;i<=5;i++)
			for (int j=i+1;j<=5;j++)
			{
				int x=0,y=0,z=0;
				for (int k=1;k<=n;k++)
					if (b[j][k-1]&&b[i][k-1]) z++;
					else if (b[j][k-1]) x++;
					else if (b[i][k-1]) y++;
				if (x+y+z!=n) continue;
				if (min(x,y)+z>=max(x,y)) ans=1;
			}
		if (ans) puts("YES");
		else puts("NO");
	}
}
/*

*/