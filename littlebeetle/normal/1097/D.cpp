#include<cstdio>
const int M=1000000007;
typedef long long ll; 
ll n,i,j,ans=1,f[10002][60],inv[60];
int k;
ll d(ll i,ll j){
	int u,v,w;
	long long Ans=0,x;
	for(u=0;u<=k;u++)
		for(v=0;v<=j;v++)
			f[u][v]=0;
	f[0][j]=1;
	for(u=0;u<k;u++)
		for(v=0;v<=j;v++)
			for(w=0;w<=v;w++)
				f[u+1][w]=(f[u+1][w]+f[u][v]*inv[v+1])%M;
	for(v=0,x=1;v<=j;v++,x=x*i%M)
		Ans=(Ans+f[k][v]*x)%M;
	return Ans;
}
int main(){
	scanf("%I64d%d",&n,&k);
	inv[1]=1;
	for(i=2;i<60;i++)
		inv[i]=inv[M%i]*(M-M/i)%M;
	for(i=2;i*i<=n;i++){
		if(n%i==0){
			j=0;
			while(n%i==0)
				n/=i,j++;
			ans=ans*d(i,j)%M;
		}
	}
	if(n!=1)
		ans=ans*d(n,1)%M;
	printf("%I64d",ans);
}