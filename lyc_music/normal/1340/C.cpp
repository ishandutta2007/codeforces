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
#define int ll
#define N 10005
#define M 1005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
deque<pa>q;
int n,m,a[N];
int vis[N][M];
int g,r,ans=inf;
signed main()
{
	n=read(),m=read();
	for (int i=1;i<=m;i++) a[i]=read();
	sort(a+1,a+m+1);
	g=read(),r=read();
	vis[1][0]=1;
	q.push_front({1,0});
	while (!q.empty())
	{
		pa u=q.front();
		q.pop_front();
		int x=u.fi,y=u.se;
//		cout<<x<<" "<<y<<endl;
		int i=x;
		if (x>1)
		{
			if (y+a[i]-a[i-1]<g)
			{
				if (!vis[i-1][y+a[i]-a[i-1]])
				{
					vis[i-1][y+a[i]-a[i-1]]=vis[x][y];
					q.push_front({i-1,y+a[i]-a[i-1]});
				}
			} else
			if (y+a[i]-a[i-1]==g)
			{
				if (!vis[i-1][0])
				{
					vis[i-1][0]=vis[x][y]+1;
					q.push_back({i-1,0});
				}
			}
		}
		if (x<m)
		{
			if (y+a[i+1]-a[i]<g)
			{
				if (!vis[i+1][y+a[i+1]-a[i]])
				{
					vis[i+1][y+a[i+1]-a[i]]=vis[x][y];
					q.push_front({i+1,y+a[i+1]-a[i]});
				}
			} else
			if (y+a[i+1]-a[i]==g)
			{
				if (!vis[i+1][0])
				{
					vis[i+1][0]=vis[x][y]+1;
					q.push_back({i+1,0});
				}
			}
		}
	}
	for (int i=0;i<g;i++)
	{
		int x=(vis[m][i]-1)*(g+r)+i;
		if (!vis[m][i]) continue;
		if (!i&&vis[m][i]>1) x-=r;
			ans=min(ans,x);
	}
	if (ans==inf) puts("-1");
	else
	writeln(ans);
	
				
}
/*

*/