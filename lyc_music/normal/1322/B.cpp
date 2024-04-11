//The Hunting Party - Keys To The Kingdom
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
#define N 400005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,a[N],ans,b[N];
void LYC_music()
{
	n=read();
	for (int i=1;i<=n;i++)
	{
		b[i]=read();
	}
	for (int now=1;now<=20000000;now*=2)
	{
		for (int i=1;i<=n;i++) a[i]=b[i]%(now*2);
		sort(a+1,a+n+1);
		int l=0,r=0,x=0;
		for (int i=n;i>=1;i--)
		{		
			while (r+1<=n&&(a[i]+a[r+1]<=now*2-1)) r++;
			while (l+1<=n&&(a[i]+a[l+1]<now)) l++;
//			cout<<l<<" "<<r<<endl;
			x+=r-l-(l<i&&i<=r);
		}
		l=0,r=0;
		for (int i=n;i>=1;i--)
		{		
			while (r+1<=n&&(a[i]+a[r+1]<=now*4-1)) r++;
			while (l+1<=n&&(a[i]+a[l+1]<now*2+now)) l++;
			x+=r-l-(l<i&&i<=r);
		}
		x/=2;
		if (x&1) ans+=now;
		
	}
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