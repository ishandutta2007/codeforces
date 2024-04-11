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
#define N 100005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,m,l[N],r[N],f[N],s[N],g[N];
signed main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++) l[i]=read(),r[i]=read();
	for (int i=1;i<=m;i++)
	{
		int lim=m/i;
		for (int j=0;j<=lim;j++) f[j]=0,s[j]=1;
		f[0]=s[0]=1;
		for (int j=1;j<=n;j++)
		{
			int x=l[j]/i,y=r[j]/i;
			if (l[j]%i!=0) x++;
			for (int k=0;k<=lim;k++) f[k]=0;
			for (int k=lim;k>=0;k--)
			{
				int R=k-x,L=k-y-1;
				f[k]=(((R>=0)?s[R]:0ll)-((L>=0?s[L]:0ll))+mod)%mod;
				f[k]%=mod;
//				cout<<k<<","<<f[k]<<endl;
			}
			s[0]=f[0];
			for (int k=1;k<=lim;k++)
				s[k]=(s[k-1]+f[k])%mod;
		}
		g[i]=s[lim];
//		g[i]=(g[i]+mod)%mod;
//		cout<<(g[i]-1+mod)%mod<<endl;
	}
	for (int i=m;i>=1;i--)
	{
//		cout<<i<<" "<<g[i]<<endl;
		for (int j=2*i;j<=m;j+=i)
			g[i]=(g[i]-g[j]+mod)%mod;
	}
	writeln(g[1]);
	
	
}
/*

*/