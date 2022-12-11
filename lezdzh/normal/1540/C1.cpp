#include<cstdio>

using namespace std;

const int md=1000000007;
int f[101][10001];
int a[101],b[101],x[100001];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=2;i<=n;i++){
		scanf("%d",&b[i]);
		b[i]+=b[i-1];
	}
	for(int i=2;i<=n;i++)
		b[i]+=b[i-1];
	int q;
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
		scanf("%d",&x[i]);
	f[0][0]=1;
	for(int i=0;i<n;i++)
		for(int j=0;j<=10000;j++){
			if(f[i][j]==0)continue;
			for(int k=0;k<=a[i+1];k++)
				if(j+k-b[i+1]>=(i+1)*x[1])
					f[i+1][j+k]=(f[i+1][j+k]+f[i][j])%md;
		}
	int ans=0;
	for(int j=0;j<=10000;j++)
		ans=(ans+f[n][j])%md;
	printf("%d\n",ans);
}