#include<cstdio>
typedef long long ll;
ll T,a,b;
bool check(ll x){
	for(ll i=2;i*i<=x;i++)
		if(x%i==0)
			return 0;
	return 1;
}
int main(){
	scanf("%lld",&T);
	while(T--){
		scanf("%lld%lld",&a,&b);
		if(a-b>1)
			printf("NO\n");
		else
			printf("%s\n",check(a+b)?"YES":"NO");
	}
	//while(1);
}