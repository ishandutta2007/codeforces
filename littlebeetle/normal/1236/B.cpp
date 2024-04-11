#include<cstdio>
const int M=1000000007;
typedef long long ll;
int n,m;
ll ksm(ll x,int p){
	ll s=1;
	while(p){
		if(p&1)
			s=s*x%M;
		p>>=1;
		x=x*x%M;
	}
	return s;
}
int main(){
	scanf("%d%d",&n,&m);
	printf("%lld\n",ksm(ksm(2,m)-1+M,n));
	return 0;
}