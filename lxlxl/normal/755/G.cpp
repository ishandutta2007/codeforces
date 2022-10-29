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

const int maxn = 1<<18;
const int mod  = 998244353;
const int g = 3;

int pw(int x,int k)
{
	int re=1;
	for(;k;k>>=1,x=(ll)x*x%mod) if(k&1)
		re=(ll)re*x%mod;
	return re;
}
int inv(int x){ return pw(x,mod-2); }
inline int Add(int x,int y){ x+=y;if(x>=mod)x-=mod;return x; }
inline int Dec(int x,int y){ x-=y;if(x<0)x+=mod; return x; }

int n,K;

int id[maxn],N,ln,w[maxn];
void Pre()
{
	N=1,ln=0;
	while(N<=(K<<1)) N<<=1,ln++;
	for(int i=1;i<N;i++) id[i]=id[i>>1]>>1|(i&1)<<(ln-1);
	w[0]=1; w[1]=pw(g,(mod-1)/N);
	for(int i=2;i<=N;i++) w[i]=(ll)w[i-1]*w[1]%mod;
}
struct Poly
{
	int f[maxn];
	void init(){ memset(f,0,sizeof f); }
	void DFT(int sig)
	{
		for(int i=0;i<N;i++) if(i<id[i]) swap(f[i],f[id[i]]);
		for(int m=2;m<=N;m<<=1)
		{
			int t=m>>1,tt=N/m;
			for(int j=0;j<N;j+=m)
			{
				for(int i=0;i<t;i++)
				{
					int tx=f[j+i],ty=(ll)f[j+i+t]*(sig==1?w[i*tt]:w[N-i*tt])%mod;
					f[j+i]=Add(tx,ty);
					f[j+i+t]=Dec(tx,ty);
				}
			}
		}
		if(sig==-1) 
		{
			int invN=inv(N);
			for(int i=0;i<N;i++) f[i]=(ll)f[i]*invN%mod;
		}
	}
}ans,x0,x1,x2,nx0,nx1,tmp;

int t[maxn],tp;
void PW(int k)
{
	for(;k;k>>=1) t[++tp]=k&1;
	x0.init();  x1.init();
	x0.f[0]=1;
	for(int j=tp;j>=1;j--)
	{
		if(t[j])
		{
			tmp.f[0]=1;
			for(int i=1;i<=K;i++) tmp.f[i]=Add(Add(x0.f[i],x0.f[i-1]),x1.f[i-1]);
			for(int i=K+1;i<N;i++) tmp.f[i]=0;
			x1=x0; x0=tmp;
		}
		if(j==1) break;
		for(int i=1;i<=K;i++) x2.f[i-1]=Dec(Dec(x0.f[i],x1.f[i]),x1.f[i-1]);
		for(int i=K;i<N;i++) x2.f[i]=0;
		
		x0.DFT(1); x1.DFT(1); x2.DFT(1);
		
		for(int i=0;i<N;i++) nx1.f[i]=(ll)x0.f[i]*x1.f[i]%mod;
		for(int i=0;i<N;i++) tmp.f[i]=(ll)x1.f[i]*x2.f[i]%mod;
		nx1.DFT(-1); tmp.DFT(-1);
		for(int i=1;i<=K;i++) nx1.f[i]=Add(nx1.f[i],tmp.f[i-1]);
		for(int i=K+1;i<N;i++) nx1.f[i]=0;
		
		for(int i=0;i<N;i++) nx0.f[i]=(ll)x0.f[i]*x0.f[i]%mod;
		for(int i=0;i<N;i++) tmp.f[i]=(ll)x1.f[i]*x1.f[i]%mod;
		nx0.DFT(-1); tmp.DFT(-1);
		for(int i=1;i<=K;i++) nx0.f[i]=Add(nx0.f[i],tmp.f[i-1]);
		for(int i=K+1;i<N;i++) nx0.f[i]=0;
		
		for(int i=0;i<N;i++) x0.f[i]=nx0.f[i];
		for(int i=0;i<N;i++) x1.f[i]=nx1.f[i];
	}
	ans=x0;
	return;
}

int main()
{
	scanf("%d%d",&n,&K);
	Pre();
	
	PW(n);
	for(int i=1;i<K;i++) printf("%d ",ans.f[i]); printf("%d\n",ans.f[K]);
	
	return 0;
}