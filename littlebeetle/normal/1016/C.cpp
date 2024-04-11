#include<cstdio>
typedef long long ll;
const int N=300002;
int n,i,t;
ll ans,S;
struct P{
	ll x[N],sum[N],Rise[N],Down[N];
	void init(){
		int i;
		for(i=1;i<=n;i++){
			scanf("%lld",x+i);
			sum[i]=sum[i-1]+x[i];
			Rise[i]=Rise[i-1]+x[i]*i;
			Down[i]=Down[i-1]+x[i]*(n-i+1);
		}
	}
	ll Rs(int i){
		return Rise[n]-Rise[i-1]+(sum[n]-sum[i-1])*(t-i);
	}
	ll Dn(int i){
		return Down[n]-Down[i-1]+(sum[n]-sum[i-1])*(t+n-i);
	}
}a[2];
ll max(ll x,ll y){
	return x>y?x:y;
}
int main(){
	scanf("%d",&n);
	a[0].init();
	a[1].init();
	for(i=1;i<=n;i++){
		ans=max(ans,a[i&1^1].Rs(i)+a[i&1].Dn(i)+S);
		//printf("%lld\n",a[i&1^1].Rs(i)+a[i&1].Dn(i)+S);
		S+=(t++)*a[i&1^1].x[i];
		S+=(t++)*a[i&1].x[i];
	}
	printf("%lld",ans);
	//while(1);
}