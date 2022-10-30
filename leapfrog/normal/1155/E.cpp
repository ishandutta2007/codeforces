//{{{
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
const int P=1000003;int n,y[2005],iv[2005],K;
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
inline int Cal(int n,int K,int *y)
{
	int res=0;for(int i=0,w=1;i<=n;res=(res+1ll*w*y[i])%P,w=1,i++)
		for(int j=0;j<=n;j++) if(i^j) w=1ll*w*(K-j)%P;
	return res;
}
inline int Q(int a) {int w;return printf("? %d\n",a),fflush(stdout),read(w),w;}
inline void A(int w) {printf("! %d\n",w),fflush(stdout);}
int main()
{
	for(int i=0;i<=10;i++) y[i]=Q(i);
	for(int i=0;i<=10;i++) if(!y[i]) return A(i),0;
	for(int i=0;i<=10;i++) for(int j=0;j<=10;j++) if(i^j) y[i]=1ll*y[i]*ksm(i-j)%P;
	iv[1]=1;for(int i=2;i<=10;i++) iv[i]=1ll*iv[P%i]*(P-P/i)%P;
	for(int i=11;i<P;i++) if(!Cal(10,i,y)) return A(i),0;
	//printf("%.10lf\n",1.0*clock()/CLOCKS_PER_SEC);
	return A(-1),0;
}