#include<cstdio>
typedef long long ll;
ll t,n,k;
ll work(ll x){
	if(x==0)return 0;
	if(x%k==0)return 1+work(x/k);
	return x%k+work(x-x%k);
}
int main(){
	scanf("%lld",&t);
	while(t--){
		scanf("%lld%lld",&n,&k);
		printf("%lld\n",work(n));
	}
}