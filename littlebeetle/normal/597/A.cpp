#include<cstdio>
typedef long long ll;
ll k,a,b;
ll d(ll x){
	return x/k+1;
}
int main(){
	scanf("%lld%lld%lld",&k,&a,&b);
	if(a==0){
		printf("%lld",d(b));
		return 0;
	}
	if(b==0){
		printf("%lld",d(-a));
		return 0;
	}
	if(a>0){
		printf("%lld",d(b)-d(a-1));
		return 0;
	}
	if(b<0){
		printf("%lld",d(-a)-d(-b-1));
		return 0;
	}
	printf("%lld",d(b)+d(-a)-1);
	return 0;
}