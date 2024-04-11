#include<cstdio>
const int N=5110,M=998244353;
typedef long long ll;
int p,r,s,i,j,x;
ll c[N][N],inv[N],ans;
void Uzi(){
	for(i=0;i<N;i++){
		c[i][0]=1;
		for(j=1;j<=i;j++)
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%M;
	}
	inv[1]=1;
	for(i=2;i<N;i++)
		inv[i]=(M-M/i)*inv[M%i]%M;
}
void init(){
	scanf("%d%d%d",&p,&s,&r);
}
ll C(int x,int y){
	if(x==y)
		return 1;
	if(x<y||x<0||y<0)
		return 0;
	return c[x][y];
}
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
ll Inv(ll x){
	return ksm(x,M-2);
}
void work(){
	for(x=r;x<=s;x++)
		for(i=1;i<=p;i++)
			for(j=0;i+j<=p;j++){
				//printf("%d %lld\n",i,c[p-1][i-1]*((j%2?-1:1)*c[p-i][j]*C(s-i*x-j*x+p-i-1,p-i-1)%M)*inv[i]);
				ans=(ans+c[p-1][i-1]*((j%2?-1:1)*c[p-i][j]*C(s-i*x-j*x+p-i-1,p-i-1)%M)%M*inv[i])%M;
			}
	//printf("\n%lld\n",c[s-r+p-1][p-1]);
	ans=(ans+M)*Inv(c[s-r+p-1][p-1])%M;
	printf("%lld",ans);
}
int main(){
	Uzi();
	init();
	work();
	//while(1);
	return 0;
}