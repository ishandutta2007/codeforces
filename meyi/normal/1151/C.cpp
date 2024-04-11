#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10,mod=1e9+7;
int a[maxn],m,n,t_case;
ll l,r;
inline ll calc(ll k){
	ll cntA=0,cntB=0,pw2=1;
	bool flag=0;
	while(k>pw2){
		if(flag)cntB+=pw2;
		else cntA+=pw2;
		flag^=1,k-=pw2,pw2<<=1;
	}
	(flag?cntB:cntA)+=k;
	cntA%=mod,cntB%=mod;
	return (cntA*cntA+cntB*(cntB+1))%mod;
}
signed main(){
	scanf("%lld%lld",&l,&r);
	printf("%lld",(calc(r)-calc(l-1)+mod)%mod);
	return 0;
}