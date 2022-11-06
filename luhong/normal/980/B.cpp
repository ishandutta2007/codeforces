#include<iostream>
#include<cstdio>
using namespace std;
int mp[101][101];
int main()
{
	int n,k;scanf("%d%d",&n,&k);
	if(k%2==0)
	{
		k/=2;
		for(int j=2;j<=k+1;j++)
		{
			mp[2][j]=mp[3][j]=1;
		}
	}
	else
	{
	for(int i=2;i<=3;i++)
	for(int j=2;j<=n/2;j++)
	{
		if(k>1)mp[i][j]=mp[i][n-j+1]=1,k-=2;
	}
	if(k==1)mp[2][n/2+1]=1;
	if(k==2)mp[3][n/2+1]=mp[2][n/2+1]=1;
	}
	puts("YES");
	for(int i=1;i<=4;i++,printf("\n"))
	for(int j=1;j<=n;j++)if(mp[i][j]==0)printf(".");else printf("#");
	return 0;
}