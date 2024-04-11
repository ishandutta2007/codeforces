//xtwakioi! xtwddYnoi()!
#include <bits/stdc++.h>
#define ri register
#define int long long
#define E (n+1)
#define mk make_pair
using namespace std; const int N=4010, M=1000, Mod=1e9+7;
inline int read()
{
    int s=0, w=1; ri char ch=getchar();
    while(ch<'0'||ch>'9') { if(ch=='-') w=-1; ch=getchar(); }
    while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48), ch=getchar();
    return s*w;
}
int fac[N+10],inv[N+10];
int x[N],y[N],b[N],n,m,R,mp[M+10][M+10],res;
inline int ksc(int x,int pp) { int tt=1; for(;pp;pp>>=1, x=x*x%Mod) if(pp&1ll) tt=tt*x%Mod; return tt; }
inline int F(int lx,int ly,int rx,int ry)
{
	if(lx>rx || ly>ry) return 0;
	return mp[rx][ry]-mp[rx][ly-1]-mp[lx-1][ry]+mp[lx-1][ly-1];
}
inline int C(int x,int y)
{
	if(x<y) return 0;
	return fac[x]*inv[x-y]%Mod*inv[y]%Mod;
}
signed main()
{
    n=read(), m=read(), R=read();
	for(ri int i=1;i<=n;i++) x[i]=read(), y[i]=read(), b[i]=read();
	for(ri int i=1;i<=n;i++)
	{
		mp[x[i]][y[i]]++;
	}
	for(ri int i=1;i<=M;i++)
	for(ri int j=1;j<=M;j++)
	mp[i][j]+=mp[i-1][j]+mp[i][j-1]-mp[i-1][j-1];

	fac[0]=1;
	for(ri int i=1;i<=N;i++) fac[i]=fac[i-1]*i%Mod;
	inv[N]=ksc(fac[N],Mod-2);
	for(ri int i=N;i;i--) inv[i-1]=inv[i]*i%Mod;

	for(ri int i=1;i<=n;i++)
	{
		int w=F(max(1ll,x[i]-R),max(1ll,y[i]-R),min(M,x[i]+R),min(M,y[i]+R));
		res=(res+b[i]*b[i]%Mod*(C(n,m)-C(n-w,m)+Mod)%Mod)%Mod;
	}

	for(ri int i=1;i<=n;i++)
	for(ri int j=1;j<i;j++)
	{
		int gg=C(n,m);
		res=(res+gg*b[i]%Mod*b[j]%Mod*2%Mod)%Mod;
		int w1=F(max(1ll,x[i]-R),max(1ll,y[i]-R),min(M,x[i]+R),min(M,y[i]+R));
		res=(res-C(n-w1,m)*b[i]%Mod*b[j]%Mod*2%Mod+Mod)%Mod;
		int w2=F(max(1ll,x[j]-R),max(1ll,y[j]-R),min(M,x[j]+R),min(M,y[j]+R));
		res=(res-C(n-w2,m)*b[i]%Mod*b[j]%Mod*2%Mod+Mod)%Mod;
		int w3=F(max(max(1ll,x[i]-R),max(1ll,x[j]-R)),
				max(max(1ll,y[i]-R),max(1ll,y[j]-R)),
				min(min(M,x[i]+R),min(M,x[j]+R)),
				min(min(M,y[i]+R),min(M,y[j]+R)));
		res=(res+C(n-w1-w2+w3,m)*b[i]%Mod*b[j]%Mod*2%Mod)%Mod;
	}
	printf("%lld\n",(res%Mod+Mod)%Mod);
    return 0;
}