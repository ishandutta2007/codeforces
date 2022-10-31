#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 500
int n,k,cnt;
int a[MAXN+10][MAXN+10],ans;
int main()
{
	scanf("%d%d",&n,&k);
	int i,j;
	cnt=n*n;
	for(i=n;i;i--){
		for(j=n;j>=k;j--)
			a[i][j]=cnt--;
		ans+=a[i][k];
	}
	cnt=0;
	for(i=1;i<=n;i++)
		for(j=1;j<k;j++)
			a[i][j]=++cnt;
	printf("%d\n",ans);
	for(i=1;i<=n;i++){
		for(j=1;j<n;j++)
			printf("%d ",a[i][j]);
		printf("%d\n",a[i][j]);
	}
}