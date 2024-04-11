#include<cstdio>
#include<algorithm>
using namespace std;

const long long md=228258092113ll;
int a[101],z[101];
long long f[101][10001];
long long c[101][101];
int main(){
	int n;
	scanf("%d",&n);
	c[0][0]=1;
	for(int i=1;i<=n;i++){
		c[i][0]=1;
		for(int j=1;j<=i;j++)
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%md;
	}
	int kd=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(!z[a[i]])kd++;
		z[a[i]]++;
	}
	if(kd<=2){
		printf("%d\n",n);
		return 0;
	}
	f[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=i-1;j>=0;j--)
			for(int k=0;k<=j*100;k++)
				f[j+1][k+a[i]]=(f[j+1][k+a[i]]+f[j][k])%md;
	int ans=0;
	for(int i=1;i<=100;i++)
		for(int j=1;j<=z[i];j++)
			if(f[j][j*i]==c[z[i]][j])ans=max(ans,j);
	printf("%d\n",ans);	
}