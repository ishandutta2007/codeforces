#include<cstdio>
typedef long long ll;
int n;
ll x,y,ans;
ll gcd(ll x,ll y){
	return y?gcd(y,x%y):x;
}
int main(){
	scanf("%d%lld",&n,&x);
	while(--n)
		scanf("%lld",&y),x=gcd(x,y);
	for(y=1;y*y<=x;y++)
		if(x%y==0){
			ans++;
			if(y*y!=x)
				ans++;
		}
	printf("%lld",ans);
}