#include<cstdio>
typedef long long ll;
ll a,b,c,d;
int main(){
	int t; scanf("%d",&t);
	while(t--){
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		printf("%lld\n",(c-a)*(d-b)+1);
	}
	return 0;
}