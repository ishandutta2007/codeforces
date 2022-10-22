#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll a,k;
ll ff(ll p){
	ll x=0,y=10;
	while(p){
		ll t=p%10;
		x=max(x,t);
		y=min(y,t);
		p/=10;
	}
	return x*y;
}

int main() {
	int _; scanf("%d",&_);
	while(_--) {
		scanf("%lld%lld",&a,&k);
		for(ll i=2; i<=k; ++i) {
			ll t=ff(a);
			if(t==0) break;
			a+=t;
		}
		printf("%lld\n",a);
	}
	return 0;
}