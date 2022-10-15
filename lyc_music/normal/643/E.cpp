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
#define N 700005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
//#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
double dp[N][65];
int q,x,now,fa[N],n,siz[N];
signed main()
{
	q=read();
	n=1;
	for (int j=0;j<=60;j++)
		dp[n][j]=1;
	while (q--)
	{
		x=read();
		if (x==1)
		{
			re int y=read();
			++n;
			fa[n]=y;
			int now=n;
			for (int j=0;j<=60;j++)
				dp[n][j]=1;
			re int t=0;
			re double ls=1;
			while (fa[now]!=0&&t<=60)
			{
				re double ls1=dp[fa[now]][t];
				dp[fa[now]][t]/=(1+ls);
				dp[fa[now]][t]*=(((t==0)?(0.0):(dp[now][t-1]))+1);
				now=fa[now];
				t++;
				ls=ls1;
			}
		}
		else 
		{
			re int y=read();
			re double sum=0;
			for (int i=1;i<=60;i++) 
			{
				sum+=(dp[y][i]-dp[y][i-1])*(i);
//				printf("%.10lf ",dp[y][i]);
			}
			printf("%.10lf\n",sum);
		}
	}
}
/*

*/