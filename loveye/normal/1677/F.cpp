#include<cstdio>
#include<functional>
#include<numeric>
#include<cassert>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
ll read();
#define fr(i,l,r) for(int i=(l);i<=(r);++i)
#define rf(i,l,r) for(int i=(l);i>=(r);--i)
#define fo(i,l,r) for(int i=(l);i<(r);++i)
#define foredge(i,u,v) for(int i=fir[u],v;v=to[i],i;i=nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)
#define reset(f,n) memset(f,0,sizeof(ll)*(n))
#define copy(f,g,n) memcpy(f,g,sizeof(ll)*(n))

const int N=1e5+5,MOD=998244353;
int calc(int x) {return 1<<__lg(x-1)+1;}
ll qpow(ll a,int x) {
	ll z=1;
	for(;x;x>>=1,a=a*a%MOD)
		if(x&1) z=z*a%MOD;
	return z;
}
#define N NN
namespace Poly_base {
	const int N=1<<18|1;
	ull ome[N<<1]; int Lim,rv[N];
	void prepare(int lim) {
		Lim=lim;
		ll t=ome[lim+1]=qpow(3,(MOD-1)/lim);
		fr(i,lim+2,lim*2) ome[i]=ome[i-1]*t%MOD;
		rf(i,lim,1) ome[i]=ome[i<<1];
		fo(i,1,lim) rv[i]=rv[i>>1]>>1|(i&1)*(lim/2);
	}
	void NTT(ll *f,ll *g,int lim,int job) {
		static ull t[N];
		int k=__lg(Lim/lim);
		fo(i,0,lim) t[rv[i]>>k]=(f[i]+MOD)%MOD;
		for(int len=1;len<lim;len<<=1) {
			for(int st=0;st<lim;st+=len<<1) {
				ull *l=t+st,*r=l+len,*o=ome+(len<<(job==1?1:2)),t;
				fo(d,0,len) {
					t=*r**o%MOD;
					*r=MOD-t+*l;
					*l+=t;
					++l,++r,o+=job;
				}
			}
		}
		fo(i,0,lim) g[i]=t[i]%MOD;
	}
	void MUL(ll *f,ll *g,ll *h,int lim) {
		static ll t1[N],t2[N];
		NTT(f,t1,lim,1); NTT(g,t2,lim,1);
		fo(i,0,lim) h[i]=t1[i]*t2[i]%MOD;
		NTT(h,h,lim,-1); ll iv=qpow(lim,MOD-2);
		fo(i,0,lim) h[i]=h[i]*iv%MOD;
	}
} using Poly_base::MUL;
namespace Poly {
	const int N=1<<18|1;
	void getinv(ll *f,ll *g,int n) {
		static ll t[N];
		reset(g,n); g[0]=qpow(f[0],MOD-2);
		for(int lim=2;lim<=n;lim<<=1) {
			copy(t,g,lim); MUL(t,f,t,lim);
			reset(t,lim/2); t[0]=1; fo(i,lim/2,lim) t[i]=-t[i];
			MUL(t,g,t,lim);
			copy(g+lim/2,t+lim/2,lim/2);
		}
	}
	typedef vector<ll> poly;
#define turn(t,f) copy(t,&f[0],f.size()),reset(t+f.size(),lim-f.size())
	poly operator * (const poly &a,const poly &b) {
		int lim=calc(a.size()+b.size());
		static ll t1[N],t2[N]; 
		turn(t1,a); turn(t2,b);
		MUL(t1,t2,t1,lim);
		return poly(t1,t1+a.size()+b.size()-1);
	}
	poly MULT(poly a,poly b) {
		static ll t1[N],t2[N];
		int lim=calc(a.size());
		turn(t1,a); turn(t2,b);
		reverse(t2,t2+b.size());
		MUL(t1,t2,t1,lim);
		return poly(t1+b.size()-1,t1+a.size());
	}
	poly Eval(poly f,poly g) {
		static poly sg[N<<2]; static ll t1[N],t2[N];
#define mid l+r>>1
		function<void(int,int,int)> solve1=[&](int k,int l,int r) {
			if(l==r-1) return sg[k]=poly{1,-g[l]},void();
			solve1(k<<1,l,mid); solve1(k<<1|1,mid,r);
			sg[k]=sg[k<<1]*sg[k<<1|1];
		}; solve1(1,0,g.size());
		int lim=calc(g.size()+1);
		turn(t1,sg[1]); getinv(t1,t2,lim);
		lim=calc(f.size()+g.size());
		reverse(t2,t2+g.size()+1); reset(t2+g.size()+1,lim-g.size()-1);
		turn(t1,f);
		MUL(t1,t2,t1,lim);
		f.resize(g.size()+1); fr(i,0,g.size()) f[i]=i+g.size()<lim?t1[i+g.size()]:0;
		function<void(int,int,int,poly)> solve2=[&](int k,int l,int r,poly f) {
			if(l==r-1) return g[l]=f[0],void();
			solve2(k<<1,l,mid,MULT(f,sg[k<<1|1]));
			solve2(k<<1|1,mid,r,MULT(f,sg[k<<1]));
		}; solve2(1,0,g.size(),f);
#undef mid
		return g;
	}
} using namespace Poly;
#undef NN

int n,k,p,t[N];
ll fac[N],ifac[N],A[N],B[N];
struct Node {ll a[2][2]; Node(){memset(a,0,sizeof a);}} f[N];
void operator += (Node &a,const Node b) {fr(i,0,1) fr(j,0,1) (a.a[i][j]+=b.a[i][j])%=MOD;}
Node operator * (const Node &a,const Node &b) {
	Node c;
	fr(i1,0,1) fr(j1,0,1) fr(i2,0,1) fr(j2,0,1)
		if(i1+i2<=1&&j1+j2<=1) (c.a[i1+i2][j1+j2]+=a.a[i1][j1]*b.a[i2][j2])%=MOD;
	return c;
}
Node inverse(Node x) {
	Node y;
	y.a[0][0]=qpow(x.a[0][0],MOD-2);
	y.a[1][0]=-x.a[1][0]*y.a[0][0]%MOD*y.a[0][0]%MOD;
	y.a[0][1]=-x.a[0][1]*y.a[0][0]%MOD*y.a[0][0]%MOD;
	y.a[1][1]=-(x.a[0][1]*y.a[1][0]+x.a[1][0]*y.a[0][1]+x.a[1][1]*y.a[0][0])%MOD*y.a[0][0]%MOD;
	return y;
}
int main() {
	n=read(),k=read(),p=read();
	fr(i,1,n) t[i]=read();
	*fac=1; fr(i,1,k) fac[i]=fac[i-1]*i%MOD;
	ifac[k]=qpow(fac[k],MOD-2);
	rf(i,k,1) ifac[i-1]=ifac[i]*i%MOD;
	fr(i,0,k) A[i]=p*ifac[i]%MOD;
	Poly_base::prepare(1<<18);
	--A[0]; getinv(A,B,calc(k+1));
	poly a(B,B+k+1),b;
	reverse(a.begin(),a.end()); a[0]=0;
	fo(i,1,a.size()) a[i]=a[i]*ifac[i]%MOD;
	fr(i,1,n) b.push_back(t[i]+1);
	if(b.size()<a.size()) b.resize(a.size());
	b=Eval(a,b);
	fr(i,1,n) {
		ll tmp=qpow(p,t[i]+1);
		f[i].a[0][0]=f[i].a[0][1]=t[i];
		f[i].a[1][0]=f[i].a[1][1]=(tmp*b[i-1]+(tmp-1)*B[k])%MOD*fac[k]%MOD;
		++f[i].a[0][0];
	}
	Node sum,mul,imul,ans;
	sum.a[0][0]=mul.a[0][0]=imul.a[0][0]=1;
	fr(i,1,n) {
		mul=mul*f[i];
		ans+=mul*sum;
		imul=imul*inverse(f[i]);
		sum+=imul;
	}
	printf("%lld\n",(ans.a[1][1]+MOD)%MOD);
	return 0;
}

inline ll read() {
	static ll x,c,f;x=0;f=1;
	do c=getchar(),c=='-'&&(f=-1); while(!isdigit(c));
	do x=x*10+(c&15),c=getchar(); while(isdigit(c));
	return x*f;
}