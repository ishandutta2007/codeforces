//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define ll long long
#define y1 nmsl
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
#define mod 1000000007
#define Endl endl
//#define int ll
//#define N
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int T,n,x,y,b[200005],a[200005],m,ans[200005];vector<int>G[200005],g;
string st;
signed main()
{
	cin>>T;
	while (T--)
	{
		cin>>n>>m;
		x=0,y=0;
		for (int i=1;i<=n;i++)
		{
			a[i]=read(),b[a[i]]++,G[a[i]].push_back(i);
			ans[i]=0;
		}
		for (int i=1;i<=n;i++)
		{
			if (b[i]>=m) 
			{
				y++;
				for (int j=0;j<m;j++) ans[G[i][j]]=j+1;
			}
			else 
			{
				for (int j=0;j<G[i].size();j++) g.push_back(G[i][j]);
				
				x+=b[i];
			}
		}
		for (int i=0;i<(x/m)*m;i++) ans[g[i]]=i%m+1;
		for (int i=1;i<=n;i++) writesp(ans[i]);
		puts("");
		for (int i=1;i<=n;i++) b[i]=0,G[i].clear(),ans[i]=0;
		g.clear();
	}
}
/*

*/