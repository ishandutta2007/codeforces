#include<cstdio>
typedef long long ll;
const int N=2002,M=998244353;
int n,m,k,i,j,c[N][N],Pow[N],f[N],ans;
void prepare(){
	for(i=0;i<=n;i++){
		c[i][0]=1;
		for(j=1;j<=i;j++)
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%M;
	}
	for(Pow[0]=1,i=1;i<=n;i++)
		Pow[i]=1ll*m*Pow[i-1]%M;
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	prepare();
	k=n-1-k;
	for(i=k;i<=n;i++){
		f[i]=1ll*c[n-1][n-i-1]*Pow[n-i]%M;
	}
	for(i=k;i<=n;i++)
		ans=(ans+1ll*((i-k)%2==0?1:-1)*f[i]*c[i][k])%M;
	printf("%d",(ans+M)%M);
}