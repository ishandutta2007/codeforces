#include<cstdio>
typedef long long ll;
ll x,y;
ll p(ll x){
	for(ll i=2;i*i<=x;i++)
		if(x%i==0)
			return i;
	return 0;
}
int main(){
	scanf("%lld",&x);
	y=p(x);
	if(y==0){
		printf("%lld",x);
		return 0;
	}
	while(x%y==0)
		x/=y;
	if(x==1){
		printf("%lld",y);
		return 0;
	}
	printf("1");
}