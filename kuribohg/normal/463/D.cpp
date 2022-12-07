#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
int n,len,a[100010][6],f[100010],b[100010][6],ans;
bool p=true;
int main()
{
	scanf("%d%d",&len,&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=len;j++)
			scanf("%d",&a[j][i]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=len;j++)
			b[a[j][i]][i]=j;
	//for(int i=1;i<n;i++) if(a[1][i]!=a[1][i+1]) p=false;
	//if(p) f[1]=1;else f[1]=0;
	for(int i=1;i<=len;i++)
	{
		for(int j=0;j<i;j++)
		{
			p=true;
			for(int k=1;k<=n;k++) if(b[a[j][1]][k]>b[a[i][1]][k]) p=false;
			if(p) f[i]=max(f[i],f[j]+1);
		}
	}
	for(int i=1;i<=len;i++) ans=max(ans,f[i]);
	printf("%d\n",ans);
	return 0;
}