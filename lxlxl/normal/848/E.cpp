#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

const int maxn = 210000;
const ll Mod = 998244353;
const ll g = 3;

ll pw(ll x,int k)
{
    ll re=1ll;
    for(;k;k>>=1,(x*=x)%=Mod)
        if(k&1) (re*=x)%=Mod;
    return re;
}

int N,ln;
ll ni,w[maxn];
int id[maxn];

void DFT(ll f[],const int n,const int sig)
{
	for(int i=0;i<n;i++) if(i<id[i]) swap(f[i],f[id[i]]);
	
	int kk=N/n;
	for(int m=2;m<=n;m<<=1)
	{
		int t=m>>1,tt=n/m;
		for(int j=0;j<n;j+=m)
		{
			for(int i=0;i<t;i++)
			{
				ll wn=sig==1?w[i*tt*kk]:w[(n-i*tt)*kk];
				
				ll tx=f[j+i],ty=f[j+i+t]*wn%Mod;
				f[j+i]=(tx+ty)%Mod;
				f[j+i+t]=(tx-ty+Mod)%Mod;
			}
		}
	}
	if(sig==-1) 
	{
		ni=pw(n,Mod-2);
		for(int i=0;i<n;i++) (f[i]*=ni)%=Mod;
	}
}
void prepare(const int n,const int ln)
{
	for(int i=1;i<n;i++) id[i]=(id[i>>1]>>1)|((i&1)<<ln-1);
}
ll t1[maxn],t2[maxn];/*
void get_inv(ll f[],ll H[],const int n,const int ln)
{
	if(n==1) { H[0]=pw(f[0],Mod-2); return; }
	get_inv(f,H,n>>1,ln-1);
	
	prepare(n<<1,ln+1);
	for(int i=0;i<n;i++) t1[i]=f[i],t1[i+n]=0,H[i+n]=0;
	DFT(t1,n<<1,1); DFT(H,n<<1,1);
	for(int i=0;i<(n<<1);i++) t1[i]=H[i]*(2ll-t1[i]*H[i]%Mod)%Mod;
	DFT(t1,n<<1,-1);
	for(int i=0;i<n;i++) H[i]=t1[i],H[i+n]=0;
}*/
void get_inv(ll a[],ll b[],const int n,const int ln)
{
    b[0]=pw(a[0],Mod-2);
    for(int m=2,ml=1;m<=n;m<<=1,ml++)
    {
        prepare(m<<1,ml+1);
        for(int i=0;i<m;i++) t1[i]=a[i],t1[i+m]=0,b[i+m]=0;
        DFT(t1,m<<1,1); DFT(b,m<<1,1);
        for(int i=0;i<(m<<1);i++) t1[i]=b[i]*(2ll-t1[i]*b[i]%Mod)%Mod;
        DFT(t1,m<<1,-1);
        for(int i=0;i<m;i++) b[i]=t1[i],b[i+m]=0ll;
    }
}
int n;
ll A[maxn],B[maxn],C[maxn],D[maxn];
ll f0[maxn],f1[maxn],FZ[maxn],FM[maxn];
ll G[maxn],G0[maxn],G1[maxn],G2[maxn];
ll F0[maxn],F1[maxn],F2[maxn];

ll sqr(const int i){return (ll)i*i%Mod;}

int main()
{
	scanf("%d",&n);
	N=1,ln=0; while(N<=2*n) N<<=1,ln++;
	w[0]=1ll; w[1]=pw(g,(Mod-1)/N); for(int i=2;i<=N;i++) w[i]=(w[i-1]*w[1])%Mod;
	
	G[0]=1ll,G[2]=1ll;
	for(int i=4;i<=n;i+=2) G[i]=(G[i-2]+G[i-4])%Mod;
	for(int i=0;i<=n;i++) 
	{
		G0[i]=G[i]*sqr(i)%Mod;
		G1[i]=G[i]*sqr(i+1)%Mod;
		G2[i]=G[i]*sqr(i+2)%Mod;
	}
	for(int i=0;i<=n;i++)
	{
		if(i+1<=n) A[i+1]=G0[i],B[i+1]=G1[i];
		if(i+3<=n) C[i+3]=G1[i],D[i+3]=G2[i];
	}
	
	for(int i=0;i<N;i++) f0[i]=A[i],f1[i]=D[i];
	f0[0]=f1[0]=Mod-1;
	prepare(N,ln); DFT(f0,N,1); DFT(f1,N,1);
	for(int i=0;i<N;i++) FM[i]=f0[i]*f1[i]%Mod;
	DFT(FM,N,-1);
	for(int i=0;i<N;i++) f0[i]=B[i],f1[i]=C[i];
	DFT(f0,N,1); DFT(f1,N,1);
	for(int i=0;i<N;i++) f0[i]=f0[i]*f1[i]%Mod;
	DFT(f0,N,-1);
	for(int i=0;i<=n;i++) FM[i]=(FM[i]-f0[i]+Mod)%Mod;
	for(int i=n+1;i<N;i++) FM[i]=0;
	
	for(int i=0;i<N;i++) f0[i]=0;
	get_inv(FM,f0,N>>1,ln-1); for(int i=0;i<N;i++) FM[i]=(f0[i]+Mod)%Mod;
	prepare(N,ln); DFT(FM,N,1);
	
	for(int i=0;i<N;i++) f0[i]=C[i],f1[i]=G1[i];
	DFT(f0,N,1); DFT(f1,N,1);
	for(int i=0;i<N;i++) FZ[i]=f0[i]*f1[i]%Mod;
	DFT(FZ,N,-1); for(int i=n+1;i<N;i++) FZ[i]=0;
	for(int i=0;i<N;i++) f0[i]=G0[i],f1[i]=D[i]; f1[0]=Mod-1;
	DFT(f0,N,1); DFT(f1,N,1);
	for(int i=0;i<N;i++) f0[i]=f0[i]*f1[i]%Mod;
	DFT(f0,N,-1); for(int i=n+1;i<N;i++) f0[i]=0;
	for(int i=0;i<N;i++) FZ[i]=(FZ[i]-f0[i]+Mod)%Mod;
	DFT(FZ,N,1);
	for(int i=0;i<N;i++) F0[i]=FZ[i]*FM[i]%Mod;
	DFT(F0,N,-1); for(int i=n+1;i<N;i++) F0[i]=0;
	
	for(int i=0;i<N;i++) FZ[i]=G1[i];
	DFT(FZ,N,1);
	for(int i=0;i<N;i++) F1[i]=FZ[i]*FM[i]%Mod;
	DFT(F1,N,-1); for(int i=n+1;i<N;i++) F1[i]=0;
	
	for(int i=0;i<N;i++) FM[i]=(Mod-D[i])%Mod; FM[0]++;
	for(int i=0;i<N;i++) f0[i]=0;
	get_inv(FM,f0,N>>1,ln-1); for(int i=0;i<N;i++) FM[i]=(f0[i]+Mod)%Mod;
	prepare(N,ln); DFT(FM,N,1);
	
	for(int i=0;i<N;i++) f0[i]=B[i],f1[i]=F1[i];
	DFT(f0,N,1); DFT(f1,N,1);
	for(int i=0;i<N;i++) f0[i]=f0[i]*f1[i]%Mod;
	DFT(f0,N,-1); for(int i=n+1;i<N;i++) f0[i]=0;
	for(int i=0;i<N;i++) FZ[i]=(G2[i]+f0[i])%Mod;
	DFT(FZ,N,1);
	for(int i=0;i<N;i++) F2[i]=FZ[i]*FM[i]%Mod;
	DFT(F2,N,-1); for(int i=n+1;i<N;i++) F2[i]=0;
	
	//for(int i=0;i<=n;i++) printf("%lld %lld %lld\n",G0[i],G1[i],G2[i]);
	ll ans=(G[n-1]+G[n-3])%Mod*sqr(n-1)%Mod*(ll)n%Mod;
	for(int i=1;i<n-2;i++)
	{
		ans+=G0[i]*F0[n-i-2]%Mod*(ll)(i+1)%Mod;
		ans+=G1[i-1]*F1[n-i-3]%Mod*(ll)(i+1)%Mod*2ll%Mod;
		if(i>=2&&n-i-4>=0) ans+=G2[i-2]*F2[n-i-4]%Mod*(ll)(i+1)%Mod;
		//printf("%lld\n",ans%Mod);
	}
	printf("%I64d\n",ans%Mod);
	
	return 0;
}