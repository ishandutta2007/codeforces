#include<cstdio>
#include<algorithm>
using namespace std;

const int md=998244353;
int a[501],f[501][501];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		char c;
		scanf(" %c",&c);
		if(c=='+')scanf("%d",&a[i]);
		else a[i]=-1;
	}
	int sum=0;
	for(int i=1;i<=n;i++)
		if(a[i]!=-1){
			for(int j=0;j<=n;j++)
				for(int k=0;k<=n;k++)
					f[j][k]=0;
			f[0][0]=1;
			for(int j=0;j<n;j++)
				for(int k=0;k<=n;k++){
					if(f[j][k]==0)continue;
					if(j+1==i)f[j+1][k]=(f[j+1][k]+f[j][k])%md;
					else if(a[j+1]==-1){
						if(j+1<i||k!=0){
							f[j+1][k]=(f[j+1][k]+f[j][k])%md;
							f[j+1][max(0,k-1)]=(f[j+1][max(0,k-1)]+f[j][k])%md;
						}
						else f[j+1][k]=(f[j+1][k]+f[j][k])%md;
					}
					else if(a[j+1]<a[i]||a[j+1]==a[i]&&j+1<i){
							f[j+1][k]=(f[j+1][k]+f[j][k])%md;
							f[j+1][min(n,k+1)]=(f[j+1][min(n,k+1)]+f[j][k])%md;
					}
					else f[j+1][k]=(f[j+1][k]+2ll*f[j][k])%md;
				}
			int ans=0;
			for(int k=0;k<=n;k++)
				ans=(ans+f[n][k])%md;
			sum=(sum+1ll*a[i]*ans)%md;
		}
	printf("%d\n",sum);
}