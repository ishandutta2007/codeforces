#include<cstdio>
int T,x;
long long k;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%lld%d",&k,&x);
		printf("%lld\n",(k-1)*9+x);
	}
}