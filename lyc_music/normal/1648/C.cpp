//~~
#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
#define N 200005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int tr[N];
int fac[N];
int s[N];
int a[N];
int b[N];
int n,m;
int ans;
int quickPower(int x,int y)
{
	x=(x+mod)%mod;
	int res=1;
	while (y)
	{
		if (y&1) res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
int inv(int x)
{
	return quickPower(x,mod-2);
}
void update(int x,int y)
{
	y=(y+mod)%mod;
	while (x<=200000)
	{
		tr[x]=(tr[x]+y)%mod;
		x+=x&-x;
	}
}
int query(int x)
{
	int res=0;
	while (x>0)
	{
		res=(res+tr[x])%mod;
		x-=x&-x;
	}
	return res;
}
void BellaKira()
{
	n=read(),m=read();
	fac[0]=1;
	for (int i=1;i<=n;i++)
		fac[i]=fac[i-1]*i%mod;
	int sm=1;
	for (int i=1;i<=n;i++) 
	{
		a[i]=read();
		sm=sm*(fac[s[a[i]]])%mod;
		s[a[i]]++;
		update(a[i],1);
		
		sm=sm*inv(fac[s[a[i]]])%mod;
	}
	for (int i=1;i<=m;i++) b[i]=read();
	bool bl=1;
	for (int i=1;i<=min(n,m);i++)
	{
		ans=(ans+query(b[i]-1)*sm%mod*fac[n-i]%mod)%mod;
		if (s[b[i]]==0)
		{
			bl=0;
			
			break;
		} else
		{
			sm=sm*(fac[s[b[i]]])%mod;
			
			s[b[i]]--;
			
			update(b[i],-1);
			
			sm=sm*inv(fac[s[b[i]]])%mod;
		}
	}
	if (bl)
	{
		if (n<m) ans=(ans+1)%mod;
	}
	writeln(ans);
		
}
signed main()
{
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}
/*

*/