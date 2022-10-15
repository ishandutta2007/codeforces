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
#define N 200005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,q,a[N],b[N],c[N],s[N],s1[N];
set<int>S;
int ans;
inline quickPower(int x,int y)
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
inline int work(int x,int y)
{
	int val=(s[y-2]-((x==1)?0ll:s[x-2])+mod)%mod;
	return val*b[y-1]%mod;
}
inline void ad(int &x,int y)
{
	y=(y+mod)%mod;
	x=(x+y)%mod;
}
signed main()
{
	n=read();q=read();
	b[0]=c[0]=1;
	s[0]=1;
	for (int i=1;i<=n;i++) a[i]=read()*quickPower(100,mod-2)%mod,b[i]=quickPower(a[i],mod-2)*b[i-1]%mod,s[i]=(s[i-1]+quickPower(b[i],mod-2)%mod)%mod;
	ad(ans,work(1,n+1));
//	writeln(work(1,n+1));
	S.insert(1);
	S.insert(n+1);
	while (q--)
	{
		int x=read();
		if (S.count(x))
		{
			S.erase(x);
			int u=(*(--S.lower_bound(x))),v=(*S.lower_bound(x+1));
			ad(ans,-work(u,x));
			ad(ans,-work(x,v));
			ad(ans,work(u,v));
		} else
		{
			int u=(*(--S.lower_bound(x))),v=(*S.lower_bound(x+1));
			S.insert(x);
			ad(ans,work(u,x));
			ad(ans,work(x,v));
			ad(ans,-work(u,v));
		}
		writeln(ans);
	}
			
}
/*
3 0
10 20 50
*/