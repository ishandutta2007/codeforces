#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
//#define int lld
#define N 200005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int T,n,m,a,b,c,vis[N];
signed main()
{
	T=read();
	while (T--)
	{
		n=read(),m=read();
		for (int i=1;i<=m;i++)
		{
			a=read(),b=read(),c=read();
			vis[b]=1;
		}
		int root=0;
		for (int i=1;i<=n;i++)
			if (!vis[i]) root=i;
		for (int i=1;i<=n;i++)
			if (i!=root) writesp(root),writeln(i);
		for (int i=1;i<=n;i++)vis[i]=0;
	}
}
/*

*/