#include<cstdio>
const int N=1000002,M=1000000007;
typedef long long ll;
int n,k,i,w;
ll sum,fac[N];
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
ll inv(ll x){
	return ksm(x,M-2);
}
ll S(int n,int k){
	ll s=0;
	fac[0]=1;
	for(i=1;i<=k;i++)
		fac[i]=fac[i-1]*i%M;
	for(i=0;i<=k;i++)
		s=(s+(i%2?-1:1)*ksm(k-i,n)*inv(fac[i]*fac[k-i]%M)%M)%M;
	return (s+M)%M;
}
int main(){
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++){
		scanf("%d",&w);
		sum=(sum+w)%M;
	}
	printf("%lld\n",sum*(S(n,k)+(n-1)*S(n-1,k)%M)%M);
	//while(1);
}