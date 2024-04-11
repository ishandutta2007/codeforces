#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e3+10;
const double eps=1e-10;
template<class T>inline void ckmax(T &x,const T &y){if(x<y)x=y;}
template<class T>inline void ckmin(T &x,const T &y){if(x>y)x=y;}
int a,b,cnta[maxn],cntb[maxn],n;
double ans1,ans2,f[maxn],x[maxn],y[maxn];
inline bool calc(double ka,double kb,bool t){
	for(ri i=1;i<=n;++i){
		cnta[i]=cnta[i-1],cntb[i]=cntb[i-1],f[i]=f[i-1];
		if(f[i-1]+x[i]-ka>f[i]+eps)
			cnta[i]=cnta[i-1]+1,cntb[i]=cntb[i-1],f[i]=f[i-1]+x[i]-ka;
		if(f[i-1]+y[i]-kb>f[i]+eps)
			cnta[i]=cnta[i-1],cntb[i]=cntb[i-1]+1,f[i]=f[i-1]+y[i]-kb;
		if(f[i-1]+x[i]-ka+y[i]-kb-x[i]*y[i]>f[i]+eps)
			cnta[i]=cnta[i-1]+1,cntb[i]=cntb[i-1]+1,f[i]=f[i-1]+x[i]-ka+y[i]-kb-x[i]*y[i];
	}
	if(t)printf("%lf",f[n]+a*ka+b*kb);
	return cntb[n]>b;
}
inline bool check(double k){
	double l=0,r=1;
	for(ri i=1;i<51;++i){
		double mid=(l+r)*0.5;
		if(calc(k,mid,0))ans2=l=mid;
		else r=mid;
	}
	return cnta[n]>a;
}
signed main(){
	scanf("%d%d%d",&n,&a,&b);
	for(ri i=1;i<=n;++i)scanf("%lf",x+i);
	for(ri i=1;i<=n;++i)scanf("%lf",y+i);
	double l=0,r=1;
	for(ri i=1;i<51;++i){
		double mid=(l+r)*0.5;
		if(check(mid))ans1=l=mid;
		else r=mid;
	}
	calc(ans1,ans2,1);
	return 0;
}