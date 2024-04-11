//The Hunting Party - Keys To The Kingdom
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
#define N 200005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,a[N],ans;
int quickPower(int x,int y)
{
	int res=1;
	while (y)
	{
		if (y&1) res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
void LYC_music()
{
	n=read();
	for (int i=1;i<=n;i++)
	{
		int x=read();
		while (!(x&1))
		{
			a[i]++;
			x/=2;
		}
	}
	for (int i=1;i<=30;i++)
	{
		int x=0,y=0;
		for (int j=1;j<=n;j++)
		{
			if (a[j]>i) x++;
			else if(a[j]==i) y++;
		}
		if (y)	
			ans=(ans+quickPower(2,x)*(quickPower(2,y-1)-1)%mod+mod)%mod;
	}
	int z=0;
	for (int j=1;j<=n;j++)
		if (a[j]==0) z++;
	ans=(ans+quickPower(2,n-z)*(quickPower(2,z)-1)%mod)%mod;
	writeln(ans);
}
signed main()
{
	int T=1;
	while (T--)
	{
		LYC_music();
	}
}
/*

*/