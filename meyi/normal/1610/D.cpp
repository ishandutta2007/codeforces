#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10,mod=1e9+7;
template<class T>inline void ckmax(T &x,const T &y){if(x<y)x=y;}
template<class T>inline void ckmin(T &x,const T &y){if(x>y)x=y;}
int a[maxn],cnt[35],m,n,t_case;
ll ans;
inline ll qpow(ll x,ll y){
	ll ret=1;
	for(;y;x=x*x%mod,y>>=1)if(y&1)ret=ret*x%mod;
	return ret;
}
int main(){
	scanf("%d",&n);
	for(ri i=1;i<=n;++i){
		scanf("%d",a+i);
		++cnt[__builtin_ctz(a[i])+1];
	}
	for(ri i=1;i<32;++i){
		cnt[i]+=cnt[i-1];
		if(cnt[i]>cnt[i-1])ans=(ans+(qpow(2,cnt[i]-cnt[i-1]-(i>1))+mod-1)*qpow(2,n-cnt[i]))%mod;
	}
	printf("%lld",ans);
	return 0;
}