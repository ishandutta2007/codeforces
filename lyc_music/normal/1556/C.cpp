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
#define inf 1e18
#define mod 998244353
#define int ll
#define N 1005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,a[N],mn[N][N],s[N],ans;
signed main()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read(),s[i]=s[i-1]+((i%2==0)?(-1):(1))*a[i];
	for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j++)
		{
			if (i==j) mn[i][j]=s[i];
			else 
			mn[i][j]=min(mn[i][j-1],s[j]);
		}	
	for (int i=1;i<=n;i++)
	{
		if (i%2==1) continue;
		for (int j=i-1;j>=1;j--)
			if (j%2==1)
			{
				int p=mn[j+1][i-1]-s[j];
				if (j+1>i-1) p=0;
				int x=s[i-1]-s[j];
//				cout<<p<<endl;
				if (a[j]>=-p)
				{
					int y=-p,z=0;
					x+=-p;
					if (x<=a[i])
					{
						z+=x;
						y=max(y,1ll),z=max(z,1ll);
//						cout<<x<<" "<<y<<" "<<z<<","<<p<<endl;
						ans+=(min(a[j]-y+1,a[i]-z+1));
					}
				}
//				cout<<j<<" "<<i<<" "<<ans<<endl;
			}
	}
	writeln(ans);
}
/*

*/