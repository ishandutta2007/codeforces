#include<cstdio>
const int N=300,M=1000000007;
typedef long long ll;
ll n,k,i,j,ans,s1,s2;
ll c[N][N];
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
int main(){
	for(i=0;i<N;i++){
		c[i][0]=1;
		for(j=1;j<=i;j++)
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%M;
	}
	scanf("%lld%lld",&n,&k);
	for(i=0;i<=n;i++)
		for(j=0;j<=n;j++){
			s1=(n-i)*(n-j);
			s2=n*n-s1;
			ans=(ans+((i+j)%2?-1:1)*ksm(k,s1)*ksm(k-1,s2)%M*c[n][i]%M*c[n][j]%M+M)%M;
		}
	/*i=n;j=n;
	s1=(n-i)*(n-j);
			s2=n*n-s1;
	ans=(ans+((i+j)%2?-1:1)*ksm(k,s1)*ksm(k-1,s2)%M*c[n][i]%M*c[n][j]%M)%M;*/
	printf("%lld",ans);
	//while(1);
}