#include<cstdio>
const int N=1002,M=1000000007;
typedef long long ll;
ll k,pa,pb,i,j,f[N][N],A,B,C;
ll ksm(ll x,ll b){
	ll s=1;
	while(b){
		if(b%2)
			s=s*x%M;
		b/=2;
		x=x*x%M;
	}
	return s;
}
ll inv(ll x){
	return ksm(x%M,M-2);
}
int main(){
	scanf("%lld%lld%lld",&k,&pa,&pb);
	A=pa*inv(pa+pb)%M;
	B=pb*inv(pa+pb)%M;
	C=A*inv(B)%M;
	for(i=k;i>=0;i--)
		for(j=k;j>=0;j--)
			f[i][j]=i+j>=k?(i+j+C)%M:(A*f[i+1][j]+B*f[i][i+j])%M;
	printf("%lld",f[1][0]);
	//while(1);
}