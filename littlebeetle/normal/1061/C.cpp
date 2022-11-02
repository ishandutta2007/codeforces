#include<cstdio>
const int N=1000020,M=1000000007;
int n,i,j,a,f[N]={1},ans;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a);
		for(j=1;1ll*j*j<a;j++)
			if(a%j==0)
				f[a/j]=(f[a/j]+f[a/j-1])%M;
		if(1ll*j*j==a)
			f[j]=(f[j]+f[j-1])%M;
		while(--j)
			if(a%j==0)
				f[j]=(f[j]+f[j-1])%M;
	}
	for(i=1;i<N;i++)
		ans=(ans+f[i])%M;
	printf("%d",ans);
}