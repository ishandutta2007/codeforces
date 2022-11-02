#include<cstdio>
const int N=50;
typedef long long ll;
int n,h,i,j,k,l;
ll f[N][N];
int main(){
	scanf("%d%d",&n,&h);
	f[0][0]=1;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			for(k=0;k<i;k++){
				for(l=0;l+1<j;l++)
					f[i][j]+=f[k][j-1]*f[i-k-1][l]+f[k][l]*f[i-k-1][j-1];
				f[i][j]+=f[k][j-1]*f[i-k-1][j-1];
			}
	for(i=n;i>=h;i--)
	f[n][i]+=f[n][i+1];
	printf("%lld",f[n][h]);
}