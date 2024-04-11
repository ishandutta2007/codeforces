#include<cstdio>
typedef long long LL;
inline LL Phi(const LL x){
	LL p=x,ss=x;
	for(register int i=2;1ll*i*i<=p;i++){
		if(p%i==0){
			ss=ss/i*(i-1);
			while(p%i==0) p/=i;
		}
	}
	if(p>1) ss=ss/p*(p-1);
	return ss;
}
inline LL Gcd(const LL x,const LL y){
	return !y?x:Gcd(y,x%y);
}
LL a,m;
int T;
int main(){
	for(scanf("%d",&T);T;T--){
		scanf("%lld %lld",&a,&m);
		printf("%lld\n",Phi(m/Gcd(a,m)));
	}
	return 0;
}