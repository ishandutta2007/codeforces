#include<iostream>
#include<cstdio>
using namespace std;
int mp[101][101];
bool ok[101][101];
int main()
{
	int n,k;scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		char s[110];scanf("%s",s);
		for(int j=0;j<n;j++)ok[i][j+1]=(s[j]=='.'?1:0);
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n-k+1;j++)
	{
		bool okk=0;
		for(int l=0;l<k;l++)
		{
			if(!ok[i][j+l]){okk=1;break;}
		}
		if(!okk)for(int l=0;l<k;l++)mp[i][j+l]++;
	}
	for(int i=1;i<=n-k+1;i++)
	for(int j=1;j<=n;j++)
	{
		bool okk=0;
		for(int l=0;l<k;l++)
		{
			if(!ok[i+l][j]){okk=1;break;}
		}
		if(!okk)for(int l=0;l<k;l++)mp[i+l][j]++;
	}
	int Max=-1,I,J;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	if(mp[i][j]>Max)I=i,Max=mp[i][j],J=j;
	printf("%d %d",I,J);return 0;
}