#include<iostream>
#include<cstdio>
using namespace std;
int n,a[3333],ran[2222][2222],mx[2222][2222],ans,cur,num;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
	{
		cur=0;
		for (int j=i;j<=n;j++)
		{
			if (a[j]==1) cur++;
			else cur--;
			ran[i][j]=cur;
		}
	}
	for (int i=1;i<=n+1;i++)
	{
		for (int j=1;j<=n+1;j++)
		mx[i][j]=-1e9;
	}
	for (int i=n;i>=1;i--)
	{
		for (int j=1;j<=n;j++)
		{
			mx[i][j]=mx[i+1][j];
			if (i+j-1<=n) mx[i][j]=max(mx[i][j],ran[i][i+j-1]);
 		}
	}
	for (int i=1;i<=n;i++)
	{
		if (a[i]==2) num++; 
	}
	if (num==n)
	{
		printf("%d\n",num);
		return 0;
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=i;j++)
		{
			ans=max(ans,num+ran[1][j-1]+mx[j][i-j+1]);
		}
	}
	printf("%d\n",ans);
	return 0;
}