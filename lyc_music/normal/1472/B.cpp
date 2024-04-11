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
//#define int ll
//#define N
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int f[205];
int T,n;
signed main()
{
	T=read();
	while (T--)
	{
		n=read();
		memset(f,0,sizeof(f));
		f[0]=1;
		int sm=0;
		for (int i=1;i<=n;i++)
		{
			int x=read();
			for (int j=200;j>=x;j--)
				f[j]|=f[j-x];
			sm+=x;
		}
		if (sm%2==0&&f[sm/2]) puts("YES");
		else puts("NO");
	}
}
/*

*/