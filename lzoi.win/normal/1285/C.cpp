#include<cstdio>
typedef long long ll;
ll x,ans;
ll gcd(ll a,ll b){
	if(!b) return a;
	return gcd(b,a%b);
}
int main(){
	scanf("%lld",&x);
	for(ll i=1;i*i<=x;i++)
		if(x%i==0&&gcd(i,x/i)==1) ans=i;
	printf("%lld %lld\n",ans,x/ans);
	return 0;
}