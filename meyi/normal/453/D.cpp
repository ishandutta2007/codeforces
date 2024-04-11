#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxm=21,maxn=1<<20|1;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
ll mod;
inline ll mul(ll x,ll y){
	ll ret=x*y-(ll)((long double)x/mod*y)*mod;
	return ret<0?ret+mod:ret;
}
int m,n;
inline void fwt_xor(ll *f){
	for(ri k=1,kk=2;kk<=n;k<<=1,kk<<=1)
		for(ri i=0;i<n;i+=kk)
			for(ri j=0;j<k;++j){
				ll x=f[i|j],y=f[i|j|k];
				f[i|j]=(x+y)%mod,f[i|j|k]=(x-y+mod)%mod;
			}
}
ll b[maxm],f[maxn],pop[maxn],t;
int main(){
	scanf("%d%lld%lld",&m,&t,&mod);
	mod<<=m,n=1<<m;
	for(ri i=0;i<n;++i)scanf("%lld",f+i);
	fwt_xor(f);
	for(ri i=0;i<=m;++i)scanf("%lld",b+i);
	for(ri i=0;i<n;++i)pop[i]=b[__builtin_popcount(i)];
	fwt_xor(pop);
	while(t){
		if(t&1){
			for(ri i=0;i<n;++i)f[i]=mul(f[i],pop[i]);
		}
		for(ri i=0;i<n;++i)pop[i]=mul(pop[i],pop[i]);
		t>>=1;
	}
	fwt_xor(f);
	for(ri i=0;i<n;++i)printf("%lld\n",f[i]>>m);
	return 0;
}