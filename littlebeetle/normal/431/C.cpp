#include<cstdio>
const int N=102,M=1000000007;
int n,k,d,f[N*2][2],i,j;
int main(){
	scanf("%d%d%d",&n,&k,&d);
	f[0][0]=1;
	for(i=0;i<=n;i++){
		for(j=1;j<d;j++)
			f[i+j][0]=(f[i+j][0]+f[i][0])%M,
			f[i+j][1]=(f[i+j][1]+f[i][1])%M;
		for(;j<=k;j++)
			f[i+j][1]=(1ll*f[i+j][1]+f[i][0]+f[i][1])%M;
	}
	printf("%d",f[n][1]);
}