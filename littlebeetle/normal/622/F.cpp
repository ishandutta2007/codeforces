#include<cstdio>
const int N=1000003,M=1000000007;
typedef long long ll;
ll n,k,i,inv[N],Inv[N],y,tmp,q,p,aq[N],bq[N],ans;
ll Pow(ll x,ll k){
	ll s=1;
	while(k){
		if(k&1)
			s=s*x%M;
		k>>=1;
		x=x*x%M;
	}
	return s;
}
int main(){
	scanf("%I64d%I64d",&n,&k);
	for(i=2,inv[1]=1;i<=k+2;i++)
		inv[i]=(M-M/i)*inv[M%i]%M;
	tmp=(k+2)%2?-1:1;
	Inv[0]=1;
	for(i=1;i<=k+2;i++)
		Inv[i]=inv[i]*Inv[i-1]%M;
	for(i=1,aq[0]=1;i<=k+2;i++)
		aq[i]=aq[i-1]*(n-i)%M;
	for(i=k+2,bq[k+3]=1;i;i--)
		bq[i]=bq[i+1]*(n-i)%M;
	for(i=1;i<=k+2;i++){
		y=(y+Pow(i,k))%M;
		q=Inv[i-1]*Inv[k+2-i]%M;
		tmp*=-1;
		ans=(ans+tmp*y*(aq[i-1]*bq[i+1]%M)%M*q%M)%M;
	}
	printf("%I64d",(ans+M)%M);
}