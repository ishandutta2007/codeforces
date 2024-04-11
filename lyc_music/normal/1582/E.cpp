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
#define N 100005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,T,a[N],s[N],f[N][505];
int ans;
signed main()
{
	T=read();
	while (T--)
	{
		n=read();
		for (int i=1;i<=n;i++) a[i]=read(),s[i]=s[i-1]+a[i];
		int B=500;
		for (int i=1;i<=B;i++) f[n+1][i]=0;
		ans=1;
		for (int i=n;i>=1;i--)
		{
			f[i][1]=max(f[i+1][1],a[i]);
			for (int j=B;j>=2;j--)
			{
				f[i][j]=0;
				if (i+j<=n)
				{
					if ((s[i+j-1]-s[i-1])<f[i+j][j-1])
						f[i][j]=(s[i+j-1]-s[i-1]),ans=max(ans,j);
				}
				f[i][j]=max(f[i][j],f[i+1][j]);
			}
		}
		writeln(ans);
	}
}
/*
1
18
5 2 3 5 5 2 1 1 1 2 4 2 4 6 5 4 6 1

*/