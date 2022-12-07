#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,a[5010][5010],c[5010],ans;
char str[5010][5010];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",str[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=m;j>=1;j--)
			if(str[i][j]=='1') a[i][j]=a[i][j+1]+1;
	for(int j=1;j<=m;j++)
	{
		for(int i=1;i<=m;i++) c[i]=0;
		for(int i=1;i<=n;i++) c[a[i][j]]++;
		for(int i=m-1;i>=1;i--) c[i]+=c[i+1];
		for(int i=1;i<=m;i++) ans=max(ans,c[i]*i);
	}
	printf("%d\n",ans);
	return 0;
}