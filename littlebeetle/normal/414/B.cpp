#include<cstdio>
const int N=2002,M=1000000007;
int n,k,i,j,p,f[N][N],ans;
int main(){
	scanf("%d%d",&n,&k);
	f[0][1]=1;
	for(i=0;i<k;i++)
		for(j=1;j<=n;j++)
			for(p=1;j*p<=n;p++)
				f[i+1][j*p]=(f[i+1][j*p]+f[i][j])%M;
	for(i=1;i<=n;i++)	
		ans=(ans+f[k][i])%M;
	printf("%d",ans);
}