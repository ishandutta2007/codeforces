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
#define N 2005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,m,q,a[N][N],x,y,t,t1,now,now1;
ll ans;
int vis[N][N][2];
int nowx;
int X,Y;
int dfs(int x,int y,int delx,int dely)
{
	if (x>n||y>m) return 0;
	vis[x][y][dely]=1;
	return dfs(x+delx,y+dely,delx^1,dely^1)+1;
}
signed main()
{
	n=read(),m=read(),q=read();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			if (!vis[i][j][1])
			{
				int now=dfs(i,j,0,1);
				ans+=now*(now-1)/2+now;
			}
			if (!vis[i][j][0])
			{
				int now=dfs(i,j,1,0);
				ans+=now*(now-1)/2+now;
			}
		}
	nowx=n*m;
	for (int i=1;i<=q;i++)
	{
		X=read(),Y=read();
		x=X,y=Y;
		t=1;t1=0;now=1;
		while (x-t1>=1&&(y-t)>=1)
		{
			x-=t1;
			y-=t;
			t^=1;
			t1^=1;
			if (a[x][y]==1)
			{
				break;
			}
			now++;
		}
		x=X,y=Y;
		t=0;t1=1;now1=1;
		while (x+t1<=n&&(y+t)<=m)
		{
			x+=t1;
			y+=t;
			t^=1;
			t1^=1;
			if (a[x][y]==1)
			{
				break;
			}
			now1++;
		}
		if (a[X][Y]==1) ans+=now*now1;
		else ans-=now*now1;
		
		x=X,y=Y;
		t=0;t1=1;now=1;
		while (x-t1>=1&&(y-t)>=1)
		{
			x-=t1;
			y-=t;
			t^=1;
			t1^=1;
			if (a[x][y]==1)
			{
				break;
			}
			now++;
		}
		x=X,y=Y;
		t=1;t1=0;now1=1;
		while (x+t1<=n&&(y+t)<=m)
		{
			x+=t1;
			y+=t;
			t^=1;
			t1^=1;
			if (a[x][y]==1)
			{
				break;
			}
			now1++;
		}
		if (a[X][Y]==1) ans+=now*now1,nowx+=1;
		else ans-=now*now1,nowx-=1;
		a[X][Y]^=1;
		writeln(ans-nowx);
	}		
}
/*

*/