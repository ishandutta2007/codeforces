#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=50;
typedef long long ll;
const ll INF=1ll<<60;
ll n,m,ans;
int tot,p[MAXN],c[MAXN];
ll pw(ll a,ll b){
	ll res=1;
	while(b--) res*=a;
	return res;
}
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%lld%lld",&n,&m);
		if(n%m){
			printf("%lld\n",n);
			continue;
		}
		ll nn=n,mm=m;
		ans=INF;
		for(ll i=2;i*i<=m;i++){
			if(m%i) continue;
			while(m%i==0)
				m/=i,n/=i;
			ll x=i;
			while(n%i==0)
				x*=i,n/=i;
			ans=min(ans,x);
		}
		if(m>1){
			ll x=1;
			while(n%m==0)
				x*=m,n/=m;
			ans=min(ans,x);
		}
		ans=nn/ans;
		printf("%lld\n",ans);
	}
	return 0;
}