#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
namespace poly
{
	#define F(i,l,r) for(ui i=l,i##_end=r;i<i##_end;++i)
	typedef unsigned ui;typedef unsigned long long ull;
	constexpr ui MOD=998244353,G=3,LogN=16,N=(1<<LogN)+5,INV2=(MOD+1)>>1;
	constexpr ull pow(ull a,ui b)
	{
		ull c=1;
		for(;b;b>>=1,(a*=a)%=MOD)if(b&1)(c*=a)%=MOD;
		return c;
	}
	constexpr ui I=pow(G,(MOD-1)>>2);
	ui getn(ui n){return n<2?1:1<<(32-__builtin_clz(n-1));}
	namespace NTT
	{
		ui mxn,mxlgn,r[N],g[N];
		void init(ui n)
		{
			mxn=n=getn(n);mxlgn=31-__builtin_clz(mxn);
			F(i,1,n)r[i]=r[i>>1]>>1|(i&1)<<(mxlgn-1);
			g[0]=1;g[1]=(ui)pow(3,(MOD-1)/n);
			F(i,1,n)g[i+1]=(ui)(g[i]*(ull)g[1]%MOD);
		}
		void ntt(ui *a,ui n,ui opt)
		{
			static ull gg[N];
			ui lgn=31-__builtin_clz(n),dlg=mxlgn-lgn;
			F(i,0,n)if((r[i]>>dlg)>i)swap(a[r[i]>>dlg],a[i]);
			F(i,0,lgn)
			{
				ui h=1<<i,s=2<<i;
				ui *u=&g[0],*v,delta=mxn/s,tmp;
				F(j,0,h)gg[j]=*u,u+=delta;
				for(ui l=0,mid=h,k;l<n;l+=s,mid+=s)
					for(u=a+l,v=a+mid,k=0;k<h;++k,++u,++v)
					{
						tmp=(ui)(gg[k]**v%MOD);
						*v=*u-tmp;*v+=(int)*v>>31&MOD;
						(*u)+=tmp;(*u>=MOD)&&(*u-=MOD);
					}
			}
			if(!~opt)
			{
				F(i,1,n>>1)swap(a[i],a[n-i]);
				ull invn=pow(n,MOD-2);
				F(i,0,n)a[i]=(ui)(a[i]*invn%MOD);
			}
		}
	}
	using NTT::init;using NTT::ntt;
	void derivative(const ui *f,ui n,ui *g)
	{
		F(i,0,n-1)g[i]=(ui)(f[i+1]*(i+1ull)%MOD);
	}
	void integrate(const ui *f,ui n,ui *g)
	{
		static ui inv[N],maxn=0;
		if(n>maxn)
		{
			if(!maxn)inv[++maxn]=1;
			F(i,maxn+1,n+1)inv[i]=(ui)(inv[MOD%i]*(ull)(MOD-MOD/i)%MOD);
			maxn=n;
		}
		for(ui i=n;i;--i)g[i]=(ui)(f[i-1]*(ull)inv[i]%MOD);
		g[0]=0;
	}
}
using poly::ui;using poly::ull;using poly::MOD;using poly::N;
ui k,kk,x[N];
ui **solve(ui n)
{
	ui *ff=new ui[4*N];
	ui **f=new ui*[4];
	f[0]=ff;f[1]=ff+N;f[2]=ff+2*N;f[3]=ff+3*N;
	if(n==0)
	{
		f[0][0]=1;
		f[1][0]=1;f[1][1]=1;
		f[2][0]=1;f[2][1]=3;f[2][2]=1;
		f[3][0]=1;f[3][1]=5;f[3][2]=5;f[3][3]=1;
		return f;
	}
	if(n==1)
	{
		f[0][0]=1;f[0][1]=1;
		f[1][0]=1;f[1][1]=3;f[1][2]=1;
		f[2][0]=1;f[2][1]=5;f[2][2]=5;f[2][3]=1;
		f[3][0]=1;f[3][1]=7;f[3][2]=13;f[3][3]=7;f[3][4]=1;
		return f;
	}
	ui **g=solve((n>>1)-1);
	if(n&1)
	{
		poly::ntt(g[0],kk,1);
		poly::ntt(g[1],kk,1);
		poly::ntt(g[2],kk,1);
		poly::ntt(g[3],kk,1);
		ull t0,t1,t2,t3,t4,t5,xx;
		F(i,0,kk)
		{
			t0=(ull)g[0][i]*g[1][i]%MOD;
			t1=(ull)g[1][i]*g[1][i]%MOD;
			t2=(ull)g[1][i]*g[2][i]%MOD;
			t3=(ull)g[2][i]*g[2][i]%MOD;
			t4=(ull)g[2][i]*g[3][i]%MOD;
			t5=(ull)g[3][i]*g[3][i]%MOD;
			xx=x[i];
			f[0][i]=(ui)((t0*xx+t2)%MOD);
			f[1][i]=(ui)((t1*xx+t3)%MOD);
			f[2][i]=(ui)((t2*xx+t4)%MOD);
			f[3][i]=(ui)((t3*xx+t5)%MOD);
		}
		poly::ntt(f[0],kk,-1);
		poly::ntt(f[1],kk,-1);
		poly::ntt(f[2],kk,-1);
		poly::ntt(f[3],kk,-1);
		memset(f[0]+k,0,(kk-k)*sizeof(ui));
		memset(f[1]+k,0,(kk-k)*sizeof(ui));
		memset(f[2]+k,0,(kk-k)*sizeof(ui));
		memset(f[3]+k,0,(kk-k)*sizeof(ui));
	}
	else
	{
		poly::ntt(g[0],kk,1);
		poly::ntt(g[1],kk,1);
		poly::ntt(g[2],kk,1);
		poly::ntt(g[3],kk,1);
		ull t0,t1,t2,t3,t4,t5,xx;
		F(i,0,kk)
		{
			t0=(ull)g[0][i]*g[0][i]%MOD;
			t1=(ull)g[0][i]*g[1][i]%MOD;
			t2=(ull)g[1][i]*g[1][i]%MOD;
			t3=(ull)g[1][i]*g[2][i]%MOD;
			t4=(ull)g[2][i]*g[2][i]%MOD;
			t5=(ull)g[2][i]*g[3][i]%MOD;
			xx=x[i];
			f[0][i]=(ui)((t0*xx+t2)%MOD);
			f[1][i]=(ui)((t1*xx+t3)%MOD);
			f[2][i]=(ui)((t2*xx+t4)%MOD);
			f[3][i]=(ui)((t3*xx+t5)%MOD);
		}
		poly::ntt(f[0],kk,-1);
		poly::ntt(f[1],kk,-1);
		poly::ntt(f[2],kk,-1);
		poly::ntt(f[3],kk,-1);
		memset(f[0]+k,0,(kk-k)*sizeof(ui));
		memset(f[1]+k,0,(kk-k)*sizeof(ui));
		memset(f[2]+k,0,(kk-k)*sizeof(ui));
		memset(f[3]+k,0,(kk-k)*sizeof(ui));
	}
	return f;
}
ui n;
int main()
{
	read(n,k);
	poly::init(2*k+1);
	x[1]=1;
	kk=poly::getn(2*k+1);
	poly::ntt(x,kk,1);
	++k;
	ui **f=solve(n);
	F(i,1,k)printf("%u ",f[0][i]);
	puts("");
	return 0;
}