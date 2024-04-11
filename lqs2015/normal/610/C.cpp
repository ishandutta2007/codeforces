#include<iostream>
#include<cmath>
using namespace std;
char a[555][555];
int m,n,x,y;
int main()
{
	cin>>m;
	a[1][1]='+';
	n=pow(2,m);
	for (int i=1;i<=m;i++)
	{
		x=pow(2,i-1);
		y=pow(2,i);
		for (int j=x+1;j<=y;j++)
		{
			for (int k=1;k<=x;k++)
			a[j][k]=a[j-x][k];
		}
		for (int j=1;j<=x;j++)
		{
			for (int k=x+1;k<=y;k++)
			a[j][k]=a[j][k-x];
		}
		for (int j=x+1;j<=y;j++)
		{
			for (int k=x+1;k<=y;k++)
			{
				if (a[j-x][k-x]=='*') a[j][k]='+';
				else a[j][k]='*';
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		cout<<a[i][j];
		cout<<endl;
	}
	return 0;
}