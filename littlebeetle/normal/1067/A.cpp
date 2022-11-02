#include<cstdio>
const int N=100020,M=998244353,K=200;
unsigned n,a,i,j,k,g[K+2],f[K+2],G[K+2],F[K+2],ans,S1[N],S2[N];
int main(){
	f[1]=1;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a);
		for(j=1;j<=K;j++)
			S1[j]=(S1[j-1]+g[j]+f[j])%M;
		for(j=K;j;j--)
			S2[j]=(S2[j+1]+f[j])%M;
		for(j=1;j<=K;j++){
			if(!(a!=-1&&a!=j)){
				G[j]=S1[j-1];
				F[j]=(S2[j+1]+g[j]+f[j])%M;
			}
			f[j]=F[j];
			g[j]=G[j];
			F[j]=0;
			G[j]=0;			
		}
	}
	for(i=1;i<=K;i++)
		ans=(1ll*ans+f[i])%M;
	printf("%d",ans);
}