//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define ll long long
#define il inline
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
#define Endl endl
#define int ll
#define N 1005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int T,n,nowans,a[N][N],vis[N];
vector<int>b[N],ans,E[N];
signed main()
{
	T=read();
	while (T--)
	{
		n=read();
		nowans=1;ans.clear();
		for (int i=1;i<=2*n;i++)
		{
			E[i].clear();
			for (int j=1;j<=n;j++) a[i][j]=read();
		}
		for (int i=1;i<=2*n;i++)
			for (int j=1;j<=2*n;j++)
				for (int k=1;k<=n;k++)
					if (a[i][k]==a[j][k]) E[i].push_back(j),E[j].push_back(i);
		for (int i=1;i<=2*n;i++) vis[i]=0;
		for (int m=0;m<n;m++)
		{
			int now=0;
			for (int j=1;j<=n;j++)
			{
				for (int i=1;i<=n;i++) b[i].clear(); 
				for (int i=1;i<=2*n;i++)
				if (!vis[i])
				{
						b[a[i][j]].push_back(i);
				}
				for (int i=1;i<=n;i++)
					if (b[i].size()==1)
					{
						now=b[i][0];
						break;
					}
				if (now) break;
			}
			if (!now)
			{
				for (int i=1;i<=2*n;i++) 
					if (!vis[i])
					{
						now=i;break;
					}
					
				nowans*=2;nowans%=mod;
			}
			ans.push_back(now);
			vis[now]=1;
			for (auto u:E[now]) vis[u]=1;
		}
		writeln(nowans);
		for (auto u:ans) writesp(u);
		puts("");
	}
			
}
/*

*/