#include<bits/stdc++.h>
#define int long long
using namespace std;const int N=1e5;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int P,n,m,pc,p[15],php,pt,res,l,r;
inline int ksm(int x,int q) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*x*r%P;return r;}
inline int gph(int x) {int r=x;for(int i=2;i*i<=x;i++) {if(x%i==0) r=r/i*(i-1);while(x%i==0) x/=i;}return (x^1)?r/x*(x-1):r;}
struct num
{
	int fc,iv,a[15];
	inline void Pt() {printf("%d , %lld : ",fc,1ll*fc*iv%P);for(int i=1;i<=pc;i++) printf("%d%c",a[i],i==pc?'\n':' ');}
	inline int get() {int r=fc;for(int i=1;i<=pc;i++) r=1ll*r*ksm(p[i],a[i])%P;return r;}
	inline void add(int v) {for(int i=1;i<=pc;i++) while(v%p[i]==0) v/=p[i],a[i]++;fc=1ll*fc*v%P,iv=1ll*iv*ksm(v,php-1)%P;}
	inline num operator/(num b) {num x=*this;for(int i=1;i<=pc;i++) x.a[i]-=b.a[i];x.fc=1ll*x.fc*b.iv%P;return x;}
}fc[N+5];
inline int C(int n,int m) {if(n<m||m<0) return 0;else return (fc[n]/fc[m]/fc[n-m]).get();}
signed main()
{
	read(n),read(P),read(l),read(r),php=gph(P),fc[0].fc=fc[0].iv=1,pc=0,r=min(r,n);
	pt=P;for(int i=2;i*i<=pt;i++) for(pt%i==0?p[++pc]=i:0;pt%i==0;) pt/=i;if(pt^1) p[++pc]=pt;
	memset(fc[0].a+1,0,sizeof(int)*14);for(int i=1;i<=N;i++) fc[i]=fc[i-1],fc[i].add(i);
	res=0;for(int i=0;i<=n-l;i++) res=(res+1ll*(C(n-i,(n-i-l)>>1)-C(n-i,(n-i-r-1)>>1)+P)%P*C(n,i)%P)%P;
	// for(int i=0;i<=n-l;i++) printf("(C(%d,%d) - C(%d,%d))*C(%d,%d)\n",n-i,(n-i-l)>>1,n-i,(n-i-r-1)>>1,n,i);
	return printf("%lld\n",(res+P)%P),0;
}