#include<cstdio>
typedef long long ll;
const int M=1000000007;
ll x,i,n,ans=1;
ll ksm(ll x,ll p){
	ll s=1;
	while(p){
		if(p%2)
			s=s*x%M;
		p/=2;
		x=x*x%M;
	}
	return s;
}
ll d(ll p){
	ll m=n,sum=0;
	while(m)
		sum+=m/=p;
	return ksm(p,sum);
}
int main(){
	scanf("%lld%lld",&x,&n);
	for(i=2;i*i<=x;i++)
		if(x%i==0){
			ans=ans*d(i)%M;
			while(x%i==0)
				x/=i;
		}
	if(x!=1)
		ans=ans*d(x)%M;
	printf("%lld",ans);
}