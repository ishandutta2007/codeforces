#include<cstdio>
const int N=100020,M=1000000007;
typedef long long ll;
int n,m,i;
ll fac[N],inv[N],ans;
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
ll C(int x,int y){
	return fac[x]*inv[y]%M*inv[x-y]%M;
}
int main(){
	fac[0]=1;
	for(i=1;i<N;i++)
		fac[i]=i*fac[i-1]%M;
	for(i=0;i<N;i++)
		inv[i]=ksm(fac[i],M-2)%M;
	scanf("%d%d",&n,&m);
	for(i=(n+1)/2;i<=n;i++)
		ans=(ans+C(i,n-i))%M;
	for(i=(m+1)/2;i<=m;i++)
		ans=(ans+C(i,m-i))%M;
	printf("%lld",(ans*2-2+M)%M);		
}