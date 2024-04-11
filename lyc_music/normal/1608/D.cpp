//The Hunting Party - Keys To The Kingdom
//~
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
#define N 2000005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int fac[N],inv[N];
int n;
int C(int x,int y)
{
	if (x<y||y<0||x<0) return 0;
	return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
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
void What_will_Diana_eat_today()
{
	IOS;
	cin>>n;
	fac[0]=1;
	for (int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	inv[n]=quickPower(fac[n],mod-2);
	for (int i=n;i>=1;i--)
		inv[i-1]=inv[i]*i%mod;
	int bl=0,bl1=1,bl2=1;
	int X=0,x=0,y=0,a=0,b=0;
	for (int i=1;i<=n;i++)
	{
		char ch;
		cin>>ch;
		if (ch=='?') x++;
		else if (ch=='W') y++;
		
		char ch1;
		cin>>ch1;
		if (ch1=='?') a++;
		else if (ch1=='B') b++;
		
		if (ch=='?'&&ch1=='?') X++;
		else if (ch==ch1) bl=1;
		
		if (ch=='W') bl1=0;
		if (ch=='B') bl2=0;
		if (ch1=='W') bl2=0;
		if (ch1=='B') bl1=0;
	}
	int ans=0;
	for (int i=0;i<=n;i++) ans=(ans+C(x,i-y)*C(a,i-b)%mod)%mod;
	if(!bl)
	{
		int xx=1;
		for (int i=1;i<=X;i++) xx=xx*2%mod;
		ans=(ans-xx+mod)%mod;
		ans+=bl1+bl2;
		ans%=mod;
	}
	cout<<ans<<endl;
}
signed main()
{
	int T=1;
	while (T--)
	{
	 	  What_will_Diana_eat_today();
	}
}
/*

*/