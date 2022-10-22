#include<cstdio>
long long k,n,s,t;
int main(){
	scanf("%lld",&t);
	while(t--){
		scanf("%lld%lld%lld",&s,&n,&k);
		puts(s==k||s<(n/k)*k+n?"YES":"NO");
	}
	return 0;
}