#include<cstdio>
const int N=2000020,M=1000000007;
typedef long long ll;
int n,m,i,j,k,a[N],mu[N];
ll p[N],Ans,c[N];
bool f[N];
ll ksm(ll x,int b){
	ll s=1;
	while(b){
		if(b&1)
			s=s*x%M;
		b>>=1;
		x=x*x%M;
	}
	return s;
}
void init(){
	scanf("%d%d",&n,&m);
	mu[1]=1;
	for(i=2;i<=m;i++){
		if(!f[i])a[k++]=i,mu[i]=-1;
		for(j=0;(!j||i%a[j-1])&&i*a[j]<=m;j++){
			f[i*a[j]]=1;
			mu[i*a[j]]=i%a[j]?-mu[i]:0;
		}
	}
	for(i=1;i<=m;i++)
		p[i]=ksm(i,n);
}
void work(){
	for(i=1;i<=m;i++)
		if(mu[i])
		for(j=i;j<=m;j+=i)
			c[j]=(c[j]+mu[i]*(p[j/i]-p[j/i-1]))%M;
	for(i=1;i<=m;i++)
		c[i]=(c[i]+c[i-1]+M+M)%M,
		Ans=(Ans+(c[i]^i))%M;
	printf("%lld",Ans);
}
int main(){
	init();
	work();
	//while(1);
	return 0;
}