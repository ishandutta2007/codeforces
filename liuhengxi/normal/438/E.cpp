#include<cstdio>
#include<algorithm>
#include<random>
using namespace std;
#define POLYINV
#define POLYSQRT
#ifdef POLYEVAL
#define POLYMOD
#endif
#ifdef POLYMOD
#define POLYDIV
#endif
#ifdef POLYDIV
#define POLYINV
#endif
#ifdef POLYPOW
#define POLYEXP
#define POLYLN
#endif
#ifdef POLYEXP
#define POLYLN
#endif
#ifdef POLYLN
#define POLYINV
#endif
namespace poly
{
	#define F(i,l,r) for(ui i=l,i##_end=r;i<i##_end;++i)
	typedef unsigned ui;typedef unsigned long long ull;
	constexpr ui MOD=998244353,G=3,LogN=18,N=(1<<LogN)+5,INV2=(MOD+1)>>1;
	ull pow(ull a,ui b)
	{
		ull c=1;
		for(;b;b>>=1,(a*=a)%=MOD)if(b&1)(c*=a)%=MOD;
		return c;
	}
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
		void mul(const ui *aa,ui n,const ui *bb,ui m,ui *cc,ui k=-1)
		{
			static ui a[N],b[N],c[N];
			ui siz=getn(n+m-1);
			F(i,0,n)a[i]=aa[i];
			F(i,0,m)b[i]=bb[i];
			F(i,n,siz)a[i]=0;
			F(i,m,siz)b[i]=0;
			ntt(a,siz,1);
			ntt(b,siz,1);
			F(i,0,siz)c[i]=(ui)((ull)a[i]*b[i]%poly::MOD);
			ntt(c,siz,-1);
			F(i,0,min(k,n+m-1))cc[i]=c[i];
		}
	}
	using NTT::init;using NTT::ntt;using NTT::mul;
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
		g[0]=0;
		F(i,1,n+1)g[i]=(ui)(f[i-1]*(ull)inv[i]%MOD);
	}
#ifdef POLYINV
	void inv(const ui *ff,ui n,ui *g)
	{
		static ui f[N];
		if(n==1)return g[0]=(ui)pow(ff[0],MOD-2),void();
		inv(ff,(n+1)>>1,g);
		ui siz=getn(n<<1);
		F(i,0,n)f[i]=ff[i];
		F(i,n,siz)f[i]=0;
		F(i,(n+1)>>1,siz)g[i]=0;
		ntt(f,siz,1);
		ntt(g,siz,1);
		F(i,0,siz)g[i]=(ui)(g[i]*(2-(ull)g[i]*f[i]%MOD+MOD)%MOD);
		ntt(g,siz,-1);
		F(i,n,siz)g[i]=0;
	}
#endif
#ifdef POLYLN
	void ln(const ui *f,ui n,ui *g)
	{
		static ui f_[N],f_1[N],gg[N];
		derivative(f,n,f_);
		f_[n-1]=0;
		inv(f,n,f_1);
		mul(f_,n,f_1,n,gg,n);
		integrate(gg,n,g);
		g[n]=0;
	}
#endif
#ifdef POLYEXP
	void exp(const ui *ff,ui n,ui *g)
	{
		static ui f[N],lg[N];
		if(n==1)return g[0]=1,void();
		exp(ff,(n+1)>>1,g);
		ui siz=getn(n<<1);
		F(i,(n+1)>>1,siz)g[i]=0;
		ln(g,n,lg);
		F(i,0,n)f[i]=ff[i];
		F(i,n,siz)lg[i]=f[i]=0;
		ntt(f,siz,1);ntt(g,siz,1);ntt(lg,siz,1);
		F(i,0,siz)g[i]=(ui)(g[i]*(MOD+1ull-lg[i]+f[i])%MOD);
		ntt(g,siz,-1);
	}
#endif
#ifdef POLYPOW
	void pow(const ui *ff,ui n,ui *g,ui k)
	{
		static ui lf[N];
		ln(ff,n,lf);
		F(i,0,n)lf[i]=(ui)(lf[i]*(ull)k%MOD);
		exp(lf,n,g);
	}
	void powa(const ui *ff,ui n,ui *g,ui k_mod_p,ui k_mod_phi_p,ui min_n_k)
	{
		static ui f[N];
		ui a=-1;ull b,ivb;
		F(i,0,n)if(ff[i]){b=ff[a=i];break;}
		if(!~a)
		{
			F(i,0,n)g[i]=0;
			return;
		}
		ivb=(ui)pow(b,MOD-2);
		F(i,0,n-a)f[i]=(ui)(ff[i+a]*ivb%MOD);
		F(i,n-a,n)f[i]=0;
		pow(f,n,g,k_mod_p);
		a=(ui)min((ull)n,a*(ull)min_n_k);
		b=(ui)pow(b,k_mod_phi_p);
		for(ui i=n-a;~--i;)g[i+a]=(ui)(g[i]*(ull)b%MOD);
		F(i,0,a)g[i]=0;
	}
#endif
#ifdef POLYDIV
	void div(const ui *f,ui n,const ui *g,ui m,ui *q)
	{
		static ui fr[N],gr[N],gri[N];
		F(i,0,n-m+1)fr[i]=f[n-1-i];
		F(i,0,min(n-m+1,m))gr[i]=g[m-1-i];
		F(i,min(n-m+1,m),n-m+1)gr[i]=0;
		inv(gr,n-m+1,gri);
		mul(gri,n-m+1,fr,n-m+1,q,n-m+1);
		F(i,0,(n-m+1)>>1)swap(q[i],q[n-m-i]);
	}
#endif
#ifdef POLYMOD
	void mod(const ui *f,ui n,const ui *g,ui m,ui *q,ui *r)
	{
		static ui qg[N];
		div(f,n,g,m,q);
		mul(q,n-m+1,g,m,qg,m-1);
		F(i,0,m-1)r[i]=f[i]-qg[i],r[i]+=(int)r[i]>>31&MOD;
	}
	void mod(const ui *f,ui n,const ui *g,ui m,ui *r)
	{
		static ui q[N];
		mod(f,n,g,m,q,r);
	}
#endif
#ifdef POLYSQRT
	namespace QR
	{
		mt19937 rnd(79774871);
		ui pow(ui aa,ui b,ui p)
		{
			ull a=aa,c=1;
			for(;b;b>>=1,(a*=a)%=p)if(b&1)(c*=a)%=p;
			return (ui)c;
		}
		ui quad_residue(ui n,ui p)
		{
			ull a=0,ar,ai,cr=1,ci=0,ii,tr,ti;
			if(pow(n,(p-1)>>1,p)!=1)return n?-1:0;
			while(pow((ui)((a*a-n+p)%p),(p-1)>>1,p)<=1)a=rnd()%p;
			if(a*a%p==n)return (ui)a;
			ii=(a*a-n)%p;
			ar=a;ai=1;
			for(ui b=(p+1)>>1;b;b>>=1,tr=(ar*ar+ai*ai%p*ii)%p,ti=(ai*ar<<1)%p,ar=tr,ai=ti)if(b&1)
			{
				tr=(cr*ar+ci*ai%p*ii)%p;ti=(cr*ai+ci*ar)%p;
				cr=tr;ci=ti;
			}
			return min((ui)cr,MOD-(ui)cr);
		}
	}
	using QR::quad_residue;
	void sqrt(const ui *f,ui n,ui *g,ui *g_)
	{
		static ui t[N],g__[N],gg[N];
		if(n==1)return g[0]=quad_residue(f[0],MOD),g_[0]=(ui)pow(g[0],MOD-2),void();
		sqrt(f,(n+1)>>1,g,g_);
		ui siz=getn(n<<1);
		F(i,0,(n+1)>>1)gg[i]=g[i];
		F(i,(n+1)>>1,siz)gg[i]=g_[i]=0;
		ntt(gg,siz,1);
		ntt(g_,siz,1);
		F(i,0,siz)g__[i]=(ui)(g_[i]*(2-(ull)gg[i]*g_[i]%MOD+MOD)%MOD);
		ntt(g__,siz,-1);
		mul(f,n,g__,n,t,n);
		F(i,0,n)
		{
			g[i]=t[i]+g[i];
			(g[i]>=MOD)&&(g[i]-=MOD);
			gg[i]=g[i]=(g[i]>>1)+(g[i]&1)*INV2;
		}
		F(i,n,siz)gg[i]=0;
		ntt(gg,siz,1);
		F(i,0,siz)g_[i]=(ui)(g_[i]*(2-(ull)gg[i]*g_[i]%MOD+MOD)%MOD);
		ntt(g_,siz,-1);
	}
	void sqrt(const ui *f,ui n,ui *g)
	{
		static ui g_[N];
		sqrt(f,n,g,g_);
	}
#endif
#ifdef POLYCZT
	void chirpz(const ui *f,ui n,ui c,ui m,ui *g)
	{
		static ui bc[N],ibc[N],a[N],tg[N];ull ic=pow(c,MOD-2),pc=1,ipc=1;
		F(i,ibc[0]=bc[0]=1,n+m-1)
		{
			bc[i]=(ui)(bc[i-1]*pc%MOD),(pc*=c)%=MOD;
			ibc[i]=(ui)(ibc[i-1]*ipc%MOD),(ipc*=ic)%=MOD;
		}
		F(i,0,n)a[n-1-i]=(ui)((f[i]*(ull)ibc[i])%MOD);
		ui siz=getn(n+m);
		F(i,n+m,siz)bc[i]=0;
		F(i,n,siz)a[i]=0;
		ntt(bc,siz,1);
		ntt(a,siz,1);
		F(i,0,siz)tg[i]=(ui)((ull)bc[i]*a[i]%MOD);
		ntt(tg,siz,-1);
		F(i,0,m)g[i]=(ui)(tg[i+n-1]*(ull)ibc[i]%MOD);
	}
#endif
#ifdef POLYEVAL
	namespace EVAL
	{
		#define lc (p<<1)
		#define rc (p<<1|1)
		ui pool[N*(LogN+3)],*cur;
		ui *g[N<<2],tmp[N];
		void init(const ui *a,ui l,ui r,ui p)
		{
			g[p]=cur;cur+=r-l+1;
			if(r-l==1)
			{
				*g[p]=-a[l];*g[p]+=(int)*g[p]>>31&MOD;
				g[p][1]=1;
				return;
			}
			ui mid=(l+r)>>1;
			init(a,l,mid,lc);
			init(a,mid,r,rc);
			mul(g[lc],mid-l+1,g[rc],r-mid+1,g[p]);
		}
		void eval(ui *f,ui m,ui p)
		{
			if(m==1)return;
			ui l=m>>1;
			F(i,0,m)tmp[i]=f[i];
			mod(tmp,m,g[lc],l+1,f);
			mod(tmp,m,g[rc],m-l+1,f+l);
			eval(f,l,lc);
			eval(f+l,m-l,rc);
		}
		void eval(const ui *f,ui n,const ui *a,ui m,ui *v)
		{
			cur=pool;
			init(a,0,m,1);
			if(n<=m)
			{
				F(i,0,n)v[i]=f[i];
				F(i,n,m)v[i]=0;
			}
			else mod(f,n,g[1],m+1,v);
			eval(v,m,1);
		}
		#undef lc
		#undef rc
	}
	using EVAL::eval;
#endif
}
using poly::ui;using poly::ull;using poly::MOD;using poly::N;
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
ui m,n,g[N],s14g[N],f1[N],f[N];
int main()
{
	read(m,n);++n;
	poly::init(n<<1);
	g[0]=1;
	F(i,0,m)
	{
		ui x;read(x);
		g[x]=MOD-4;
	}
	poly::sqrt(g,n,s14g);
	(++s14g[0])%=MOD;
	poly::inv(s14g,n,f1);
	F(i,0,n)f[i]=f1[i]<<1,(f[i]>=MOD)&&(f[i]-=MOD);
	F(i,1,n)printf("%u\n",f[i]);
	return 0;
}