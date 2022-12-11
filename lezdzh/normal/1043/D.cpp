#include<cstdio>

using namespace std;

int a[11][100001],b[100001],c[100001];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			if(i==1)b[a[i][j]]=j,a[i][j]=j;
			else a[i][j]=b[a[i][j]];
		}
	for(int i=2;i<=m;i++)
		for(int j=1;j<=n;j++)
			if(a[i][j]==1||a[i][j-1]+1!=a[i][j])
				c[a[i][j]]=1;
	long long ans=0;
	for(int i=1;i<=n;){
		int j;
		for(j=i;j<n&&!c[j+1];j++);
		ans+=1ll*(j-i+2)*(j-i+1)/2;
		i=j+1;
	}
	printf("%I64d\n",ans);
}