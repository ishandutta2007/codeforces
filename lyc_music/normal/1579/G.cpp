//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define re register
#define inf 1e18
#define mod 998244353
#define int ll
#define N 2000005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int T,n,a[N],ans;
int check(int x)
{
	bitset<20000>dp,now;
	dp=now=0;
	for (int i=0;i<=min(x,19999ll);i++)
		now[i]=1;
	dp=now;
	for (int i=1;i<=n;i++)
		dp=((dp<<a[i])|(dp>>a[i]))&now;
	return dp.count();
}
signed main()
{
	T=read();
	while (T--)
	{
		n=read();
		for (int i=1;i<=n;i++)
		{
			a[i]=read();
		}
		int l=1,r=20000000;
		while (l<=r)
		{
			int mid=l+(r-l)/2;
			if (check(mid))
			{
				ans=mid;
				r=mid-1;
			} else l=mid+1;
		}
		writeln(ans);
	}
}
/*

*/