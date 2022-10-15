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
//#define intas ll
#define N 6005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int T,n;
pa a[N];
vector<int>E[N],S[N];
int f[N][N];
int len;
signed main()
{
	T=read();
	while (T--)
	{
		vector<int>g;
		n=read();
		for (int i=1;i<=n;i++) 
		{
			a[i]={read(),read()};
			g.push_back(a[i].fi),g.push_back(a[i].se);
		}
		sort(g.begin(),g.end());
		g.erase(unique(g.begin(),g.end()),g.end());
		for (int i=1;i<=n;i++)
		{
			a[i].fi=lower_bound(g.begin(),g.end(),a[i].fi)-g.begin()+1;
			a[i].se=lower_bound(g.begin(),g.end(),a[i].se)-g.begin()+1;
			S[a[i].fi].push_back(i);E[a[i].se].push_back(i);
		}
		len=g.size();
		for (int l=1;l<=len;l++)
			for (int i=1;i+l-1<=len;i++)
			{
				int j=i+l-1;
				f[i][j]=max(f[i+1][j],f[i][j-1]);
				int dl=0;
				for (auto u:S[i])
				{
					if (a[u].se<j)
					{
						f[i][j]=max(f[i][j],f[a[u].se+1][j]+f[a[u].fi][a[u].se]);
					}
					if (a[u].se==j) dl=1;
				}
				for (auto u:E[j])
				{
					if (a[u].fi>i)
					{
						f[i][j]=max(f[i][j],f[i][a[u].fi-1]+f[a[u].fi][a[u].se]);
					}
				}
				f[i][j]=(f[i][j]+dl);
			}
		writeln(f[1][len]);
		for (int i=1;i<=len;i++)
		{
			S[i].clear(),E[i].clear();
			for (int j=i;j<=len;j++)
				f[i][j]=0;
		}
	}
}
/*

*/