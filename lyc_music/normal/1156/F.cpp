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
#define mod 998244353
#define int ll
#define N 5005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,a[N],b[N],ans=0,f[N][N],s[N][N],c[N],d[N],ny[N];
int quickPower(int x,int y)
{
	int res=1;
	while (y>0)
	{
		if (y%2==1) res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
signed main()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read(),b[a[i]]++;
	sort(a+1,a+n+1);
//	for (int i=1;i<=n;i++)	a[i]=-a[i];
	d[n]=n+1;
	for (int i=n-1;i>=1;i--)
		if (a[i]==a[i+1]) c[i]=c[i+1]+1,d[i]=d[i+1];
		else c[i]=0,d[i]=i+1;
//	for (int i=1;i<=n;i++)
		s[1][1]=quickPower(n,mod-2);
	for (int i=0;i<=n;i++)
		ny[i]=quickPower(i,mod-2);
	for (int i=1;i<=n;i++)
	{
		for (int j=i;j>=1;j--)
		{
			s[i][j]=(s[i][j]+s[i-1][j])%mod;
			f[j][i]=s[i][j];
//			s[j]=0;
			if (b[a[i]]>1)
				ans=(ans+f[j][i]*ny[n-j]%mod*(b[a[i]]-1)%mod)%mod;
//			cout<<f[j][i]<<" "<<i<<" "<<j<<" "<<ans<<endl;
			s[d[i]][j+1]=(s[d[i]][j+1]+f[j][i]*ny[n-j]%mod)%mod;
		}
	}
	writeln(ans);
			
}
/*

*/