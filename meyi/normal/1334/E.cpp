#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10,mod=998244353;
template<class T>inline void ckmax(T &x,const T &y){if(x<y)x=y;}
template<class T>inline void ckmin(T &x,const T &y){if(x>y)x=y;}
int cnt,q;
ll d,dv[maxn],fac[maxn],ifac[maxn];
inline ll qpow(ll x,int y){
	ll ret=1;
	for(;y;x=x*x%mod,y>>=1)if(y&1)ret=ret*x%mod;
	return ret;
}
inline ll calc(ll k){
	ll ret1=1;
	int ret2=0;
	for(ri i=1;i<=cnt&&dv[i]<=k;++i)
		if(k%dv[i]==0){
			int tmp=0;
			do ++tmp,k/=dv[i];while(k%dv[i]==0);
			ret1=ret1*ifac[tmp]%mod,ret2+=tmp;
		}
	return fac[ret2]*ret1%mod;
}
int main(){
	scanf("%lld%d",&d,&q);
	ri dcnt=0;
	for(ll i=2;;++i){
		if(i*i>d)break;
		if(d%i==0){
			dv[++cnt]=i;
			do d/=i,++dcnt;while(d%i==0);
		}
	}
	if(d>1)dv[++cnt]=d,++dcnt;
	fac[0]=1;
	for(ri i=1;i<=dcnt;++i)fac[i]=fac[i-1]*i%mod;
	ifac[dcnt]=qpow(fac[dcnt],mod-2);
	for(ri i=dcnt;i;--i)ifac[i-1]=ifac[i]*i%mod;
	while(q--){
		ll x,y;
		scanf("%lld%lld",&x,&y);
		ll g=__gcd(x,y);
		printf("%lld\n",calc(x/g)*calc(y/g)%mod);
	}
	return 0;
}