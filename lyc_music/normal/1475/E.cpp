//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 1000000007
#define int ll
#define N 1005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int T,n,m,a[N],b[N],c[N];
int C[N][N];
signed main()
{
	T=read();
	C[0][0]=1;
	for (int i=1;i<=1000;i++)
	{
		C[i][0]=1;
		for (int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	}
	while (T--)
	{
		n=read(),m=read();
		for (int i=1;i<=n;i++) a[i]=read(),b[a[i]]++,c[a[i]]++;
		sort(a+1,a+n+1);
		int sm=0;
		for (int i=n;i>=n-m+1;i--) sm+=a[i],b[a[i]]--;
		writeln(C[c[a[n-m+1]]][b[a[n-m+1]]]);
		for (int i=1;i<=n;i++) b[a[i]]=0,c[a[i]]=0;
	}
}
/*

*/