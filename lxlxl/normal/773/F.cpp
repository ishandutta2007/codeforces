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

const int maxn = 130000;
const double pi = acos(-1);

struct E
{
	double x,y;
	E(){}
	E(const double _x,const double _y){x=_x;y=_y;}
}w[maxn],t0[maxn],t1[maxn]; int id[maxn];
inline E operator +(const E &x,const E &y){return E(x.x+y.x,x.y+y.y);}
inline E operator -(const E &x,const E &y){return E(x.x-y.x,x.y-y.y);}
inline E operator *(const E &x,const E &y){return E(x.x*y.x-x.y*y.y,x.y*y.x+x.x*y.y);}

ll Mod;
int b;
int N,ln,n;
void DFT(E s[],const int sig)
{
	for(int i=0;i<N;i++) if(i<id[i]) swap(s[i],s[id[i]]);
	
	for(int m=2;m<=N;m<<=1)
	{
		int t=m>>1,tt=N/m;
		for(int j=0;j<N;j+=m)
		{
			for(int i=0;i<t;i++)
			{
				E wn=sig==1?w[i*tt]:w[N-i*tt];
				E tx=s[j+i],ty=s[j+i+t]*wn;
				s[j+i]=tx+ty;
				s[j+i+t]=tx-ty;
			}
		}
	}
	if(sig==-1) for(int i=0;i<N;i++) s[i].x/=(double)N;
}

ll re=0;
ll f0[maxn],f1[maxn],temp[maxn];
ll nf0[maxn],nf1[maxn];
void solve()
{
	f0[0]=1;
	int now=0;
	for(int i=30;i>=1;i--)
	{
		if(now&1)
		{
			for(int j=0;j<=n;j++) t0[j]=E((f0[j]+f1[j])%Mod,0);
			for(int j=0;j<=n;j++) t1[j]=E(f1[j],0);
			for(int j=n+1;j<N;j++) t0[j]=t1[j]=E(0,0);
			DFT(t0,1); DFT(t1,1);
			for(int j=0;j<N;j++) t0[j]=t0[j]*t1[j];
			DFT(t0,-1);
			for(int j=0;j<=n;j++) nf0[j]=(f0[j]+((ll)(t0[j].x+0.5)))%Mod;
			
			for(int j=0;j<=n;j++) t0[j]=E((f0[j]+f1[j])%Mod,0);
			for(int j=0;j<=n;j++) t1[j]=E(f0[j],0);
			for(int j=n+1;j<N;j++) t0[j]=t1[j]=E(0,0);
			DFT(t0,1); DFT(t1,1);
			for(int j=0;j<N;j++) t0[j]=t0[j]*t1[j];
			DFT(t0,-1);
			for(int j=0;j<=n;j++) nf1[j]=(/*f1[j]+*/((ll)(t0[j].x+0.5))%Mod-f0[j]+Mod)%Mod;
		}
		else
		{
			for(int j=0;j<=n;j++) t0[j]=E((f0[j]+f1[j])%Mod,0);
			for(int j=0;j<=n;j++) t1[j]=E(f0[j],0);
			for(int j=n+1;j<N;j++) t0[j]=t1[j]=E(0,0);
			DFT(t0,1); DFT(t1,1);
			for(int j=0;j<N;j++) t0[j]=t0[j]*t1[j];
			DFT(t0,-1);
			for(int j=0;j<=n;j++) nf0[j]=(((ll)(t0[j].x+0.5))%Mod-f1[j]+Mod)%Mod;
			
			for(int j=0;j<=n;j++) t0[j]=E((f0[j]+f1[j])%Mod,0);
			for(int j=0;j<=n;j++) t1[j]=E(f1[j],0);
			for(int j=n+1;j<N;j++) t0[j]=t1[j]=E(0,0);
			DFT(t0,1); DFT(t1,1);
			for(int j=0;j<N;j++) t0[j]=t0[j]*t1[j];
			DFT(t0,-1);
			for(int j=0;j<=n;j++) nf1[j]=(f1[j]+((ll)(t0[j].x+0.5))%Mod)%Mod;
		}
		for(int j=0;j<=n;j++) f0[j]=nf0[j],f1[j]=nf1[j];
		now<<=1;
		
		if((b&(1<<i))>0)
		{
			for(int j=n;j>=1;j--) f1[j]=(f1[j]+f0[j-1]+f1[j-1])%Mod;
			now|=1;
		}
		for(int j=1;j<=n;j+=2) re+=f1[j];
		re%=Mod;
	}
}

int main()
{
	scanf("%d%d%I64d",&n,&b,&Mod);
	
	N=1,ln=0; while(N<=2*n) N<<=1,ln++;
	for(int i=1;i<N;i++) id[i]=(id[i>>1]>>1)|((i&1)<<ln-1);
	for(int m=2;m<=N;m<<=1)
	{
		int t=m>>1,tt=N/m;
		for(int i=0;i<t;i++)
		{
			w[i*tt]=E(cos(2*pi*i/m),sin(2*pi*i/m));
			w[N-i*tt]=E(cos(2*pi*i/m),sin(-2*pi*i/m));
		}
	}
	
	solve();
	printf("%I64d\n",re);
	
	return 0;
}