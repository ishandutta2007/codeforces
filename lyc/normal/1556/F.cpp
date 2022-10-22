//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define ll long long
#define F(i,a,b) for (int i=(a);i<=(b);i++)
#define R(i,a,b) for (int i=(a);i<(b);i++)
#define D(i,a,b) for (int i=(a);i>=(b);i--)
#define go(i,x) for (int i=head[x];i;i=e[i].nx)
#define mp make_pair
#define pb push_back
#define pa pair < int,int >
#define fi first
#define se second
#define re register
#define be begin()
#define en end()
#define sqr(x) ((x)*(x))
#define ret return puts("-1"),0;
#define put putchar('\n')
#define inf 1000000005
#define mod 1000000007
#define int ll
#define N 15
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int P[N][N],f[1<<N],ans,n,a[N];
ll quickPower(int x,int y)
{
	int res=1;
	while (y)
	{
		if (y%2) res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
int work(int x,int y)
{
	vector<int>g;
	int res=1;
	for (int i=1;i<=n;i++)
	{
		if ((y>>(i-1))%2) g.push_back(i);
	}
	for (int i=1;i<=n;i++)
		if ((x>>(i-1))%2)
		{
			int now=1;
			for (auto u:g)
			{
				now=now*P[u][i]%mod;
			}
//			now=(1-now+mod)%mod;
			res=res*now%mod;
		}
	return res;
}
signed main()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) P[i][j]=a[i]*quickPower(a[i]+a[j],mod-2)%mod;
//	f[0]=1;
	for (int stat=1;stat<(1<<n);stat++)
	{
		f[stat]=1;
//		if (__builtin_popcount(stat)==1) f[stat]=1;
//		else
//		{
			for (int S=(stat-1)&stat;S;S=(S-1)&stat)
			{
				f[stat]=(f[stat]-f[S]*work(stat^S,S)%mod+mod)%mod;
				if (S==0) break;
			}
//		}
//		cout<<stat<<" "<<f[stat]<<endl;
		ans=(ans+__builtin_popcount(stat)*f[stat]%mod*work(((1<<n)-1)^stat,stat))%mod;
	}
	writeln(ans);
//	writeln(ans*quickPower(quickPower(2,n),mod-2)%mod);
		
}
/*

*/