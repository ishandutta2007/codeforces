#include<stdio.h>
int main(void)
{
	int n,m,b[105],ans[105]={0};
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) {
		scanf("%d",&b[i]);
		for(int j=b[i];j<=n;j++) if(ans[j]==0) ans[j]=b[i];
	}
	for(int k=1;k<=n;k++) printf("%d ",ans[k]);
}