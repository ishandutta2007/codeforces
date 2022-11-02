#include<cstdio>
typedef long long ll;
int q;
long long n,m;
ll work1(ll x){
	ll s=0;
	for(int i=1;i<=10;i++)
		s+=x*i%10;
	return s;
}
ll work2(ll x,ll y){
	ll s=0,p=0;
	while(p<=x){
		s+=p%10;
		p+=y;
	}
	return s;
}
int main(){
	scanf("%d",&q);
	while(q--){
		scanf("%lld%lld",&n,&m);
		printf("%lld\n",work1(m)*(n/10/m)+work2(n%(10*m),m));
	}
}