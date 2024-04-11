#include<cstdio>
const int N=5002,M=1000000007;
typedef long long ll;
int n,k,i,j;
ll S[N][N],x,y,ans;
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
	scanf("%d%d",&n,&k);
	S[0][0]=1;
	for(i=1;i<=k;i++)
		for(j=1;j<=i;j++)
			S[i][j]=(S[i-1][j-1]+S[i-1][j]*j)%M;
	for(i=0;i<=k&&i<=n;i++){
		x=1;
		for(j=0;j<i;j++)
			x=x*(n-j)%M;
		//	printf("%lld %lld %lld\n",S[k][i],x,ksm(2,n-i));
		ans=(ans+S[k][i]*x%M*ksm(2,n-i))%M;
	}
	printf("%lld",ans);
}