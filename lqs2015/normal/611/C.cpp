#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int sr[555][555],sc[555][555],n,m,q,lx,ly,rx,ry,res;
char bo[555][555];
bool a[555][555];
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%s",bo[i]);
		for (int j=1;j<=m;j++)
		{
			if (bo[i][j-1]=='.') a[i][j]=1;
			else a[i][j]=0;
		}
	}
	for (int i=1;i<=n;i++)
	{
		sr[i][1]=0;
		for (int j=2;j<=m;j++)
		{
			if (a[i][j] && a[i][j-1]) sr[i][j]=sr[i][j-1]+1;
			else sr[i][j]=sr[i][j-1];
		}
	}
	for (int i=1;i<=m;i++)
	{
		sc[i][1]=0;
		for (int j=2;j<=n;j++)
		{
			if (a[j][i] && a[j-1][i]) sc[i][j]=sc[i][j-1]+1;
			else sc[i][j]=sc[i][j-1];
		}
	}
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d%d%d",&lx,&ly,&rx,&ry);
		res=0;
		for (int i=lx;i<=rx;i++)
		{
			res=res+sr[i][ry]-sr[i][ly];
		}
		for (int i=ly;i<=ry;i++)
		{
			res=res+sc[i][rx]-sc[i][lx];
		}
		printf("%d\n",res);
	}
	return 0;
}