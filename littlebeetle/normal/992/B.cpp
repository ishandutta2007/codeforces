#include<cstdio>
typedef long long ll;
ll x,y,z,l,r,a,b;
ll gcd(ll x,ll y){
	return y?gcd(y,x%y):x;
}
ll d(ll r1,ll r2){
	if(y%x)return 0;
	ll s=0;
	z=y/x;
	for(ll i=1;i*i<=z;i++)
		if(z%i==0&&gcd(i,z/i)==1){
			a=x*i;
			b=x*z/i;
			if(a<=r1&&b<=r2)
				s++;
			if(a!=b){
			a=x*z/i;
			b=x*i;
			if(a<=r1&&b<=r2)
				s++;
			}
		}
	return s;
}
int main(){
	scanf("%lld%lld%lld%lld",&l,&r,&x,&y);
	printf("%lld",d(r,r)-d(l-1,r)*2+d(l-1,l-1));
	//while(1);
}