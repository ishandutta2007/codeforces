#include<cstdio>
typedef long long ll;
ll n,a;
ll isprime(ll n){
	for(ll i=2;i*i<=n;i++)
		if(n%i==0)
			return i;
	return 0;
}
int main(){
	scanf("%lld",&n);
	a=isprime(n);
	if(a==0){
		printf("1");
		return 0;
	}
	if(a==2){
		printf("%lld",n/2);
		return 0;
	}
	printf("%lld",(n-a)/2+1);
	return 0;
}