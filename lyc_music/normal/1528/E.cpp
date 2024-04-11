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
#define N 1000005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,f[N],s[N],g[N],ans;
int C(int x,int y)
{
	if (x<y) return 0;
	if (y==2) return x*(x-1)%mod*499122177%mod;
	else
	{
		return x*(x-1)%mod*(x-2)%mod*166374059%mod;
	}
}
void LYC_music()
{
	n=read();
	f[0]=1;s[0]=1;
	g[0]=0;
	f[1]=2,s[1]=3;
	g[1]=1;
	for (int i=2;i<=n;i++)
	{
		f[i]=(f[i-1]+f[i-1]*s[i-2]%mod+C(f[i-1]+1,2))%mod;
		s[i]=(s[i-1]+f[i])%mod;
		g[i]=(f[i]-f[i-1]+mod)%mod;
	}
	ans=2*(C(f[n-1]+2,3)+f[n])%mod;
	if (n>=2) ans=(ans+(f[n-1]*C(s[n-2]+1,2)%mod+C(f[n-1]+1,2)*s[n-2]%mod)*2%mod)%mod;
	for (int i=0;i<n;i++)
		ans=(ans+(f[i]-1)*(g[n-i-1])%mod)%mod;
	writeln((ans-1+mod)%mod);
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