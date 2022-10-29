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

inline void read(int &x)
{
	char c; while(!((c=getchar())>='0'&&c<='9'));
	x=c-'0';
	while((c=getchar())>='0'&&c<='9') (x*=10)+=c-'0';
}
const int maxn = 810000;
const ll Mod = 998244353;
const ll g = 3;

ll T[maxn],G[maxn],H[maxn],F[maxn],t1[maxn],t2[maxn];
ll w[maxn],inv2;
int N,id[maxn];

ll pw(ll x,int k)
{
	ll re=1ll;
	for(;k;k>>=1,(x*=x)%=Mod)
		if(k&1) (re*=x)%=Mod;
	return re;
}
void pre(const int n,const int ln)
{
	for(int i=1;i<n;i++) id[i]=(id[i>>1]>>1)|((i&1)<<ln-1);
}
void DFT(ll s[],const int n,const int sig)
{
	for(int i=0;i<n;i++) if(i<id[i]) swap(s[i],s[id[i]]);
	
	int kk=N/n;
	for(int m=2;m<=n;m<<=1)
	{
		int t=m>>1,tt=n/m;
		for(int j=0;j<n;j+=m)
		{
			for(int i=0;i<t;i++)
			{
				ll wn=sig==1?w[kk*i*tt]:w[kk*(n-i*tt)];
				ll tx=s[j+i],ty=s[j+i+t]*wn%Mod;
				s[j+i]=(tx+ty)%Mod;
				s[j+i+t]=(tx-ty)%Mod;
			}
		}
	}
	if(sig==-1)
	{
		ll tinv=pw(n,Mod-2);
		for(int i=0;i<n;i++) (s[i]*=tinv)%=Mod;
	}
}
void get_inv(ll a[],ll b[],const int n,const int ln)
{
	b[0]=pw(a[0],Mod-2);
	for(int m=2,ml=1;m<=n;m<<=1,ml++)
	{
		pre(m<<1,ml+1);
		for(int i=0;i<m;i++) t1[i]=a[i],t1[i+m]=0,b[i+m]=0;
		DFT(t1,m<<1,1); DFT(b,m<<1,1);
		for(int i=0;i<(m<<1);i++) t1[i]=b[i]*(2ll-t1[i]*b[i]%Mod)%Mod;
		DFT(t1,m<<1,-1);
		for(int i=0;i<m;i++) b[i]=t1[i],b[i+m]=0ll;
	}
}
void get_root(ll a[],ll b[],const int n,const int ln)
{
	b[0]=1ll;
	for(int m=2,ml=1;m<=n;m<<=1,ml++)
	{
		get_inv(b,t2,m,ml);
		pre(m<<1,ml+1);
		for(int i=0;i<m;i++) t1[i]=a[i],t1[i+m]=0;
		DFT(t1,m<<1,1); DFT(b,m<<1,1); DFT(t2,m<<1,1);
		for(int i=0;i<(m<<1);i++) t1[i]=(b[i]*inv2%Mod+t1[i]*inv2%Mod*t2[i]%Mod)%Mod;
		DFT(t1,m<<1,-1);
		for(int i=0;i<m;i++) b[i]=t1[i],b[i+m]=0;
	}
}
int n,m;
char po[20]; int pn;
void Out(ll x)
{
	if(!x) putchar('0');
	pn=0; while(x) po[++pn]=x%10+'0',x/=10;
	while(pn) putchar(po[pn--]);
}
void solve()
{
	inv2=pw(2,Mod-2);
	int ln=0;N=1; while(N<=n) N<<=1,ln++;
	N<<=1,ln++;
	w[0]=1ll; w[1]=pw(g,(Mod-1)/N);
	for(int i=2;i<=N;i++) w[i]=(w[i-1]*w[1])%Mod;
	
	get_root(T,H,N>>1,ln-1);
	H[0]++;
	get_inv(H,F,N>>1,ln-1);
	for(int i=1;i<=m;i++) 
	{
		(F[i]*=2)%=Mod;
		if(F[i]<0) F[i]+=Mod;
		Out(F[i]); putchar('\n');
	}
}

int main()
{
	read(n); read(m);
	T[0]=1ll;
	for(int i=1;i<=n;i++)
	{
		int x; read(x);
		T[x]-=4;
	}n=m;
	solve();
	
	return 0;
}