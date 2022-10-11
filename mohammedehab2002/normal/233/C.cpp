#include <iostream>
using namespace std;
int mat[105][105];
int main()
{
	int n;
	scanf("%d",&n);
	int i;
	for (i=1;n;i++)
	{
		mat[0][i]=1;
		mat[i][0]=1;
		for (int x=1;x<i;x++)
		{
			if (n<x)
			break;
			mat[i][x]=1;
			mat[x][i]=1;
			n-=x;
		}
	}
	printf("%d\n",i);
	for (int x=0;x<i;x++)
	{
		for (int j=0;j<i;j++)
		printf("%d",mat[x][j]);
		printf("\n");
	}
}