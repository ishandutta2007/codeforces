#include <bits/stdc++.h>
using namespace std;
const int maxn=100;
int n,m;
int a[maxn+5],b[maxn+5],e[maxn+5][maxn+5];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=m;i++) scanf("%d",&b[i]);
	int sum=0;
	for(int i=1;i<=n;i++) sum^=a[i];
	for(int i=1;i<=m;i++) sum^=b[i];
	if(sum!=0) 
	{
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	for(int i=2;i<=n;i++) e[i][1]=a[i];
	for(int i=2;i<=m;i++) e[1][i]=b[i];
	e[1][1]=a[1];
	for(int i=2;i<=m;i++) e[1][1]^=b[i];
	for(int i=1;i<=n;i++) 
	{
		for(int j=1;j<=m;j++) printf("%d ",e[i][j]);
		printf("\n");
	}
	return 0;
}