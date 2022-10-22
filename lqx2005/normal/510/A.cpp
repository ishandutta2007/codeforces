#include<bits/stdc++.h>
using namespace std;
const int N=50;
char a[N+5][N+5];
int n,m;
int main()
{
	scanf("%d%d",&n,&m);
	memset(a,'#',sizeof(a));
	for(int i=1;i<=n;i++)
	{
		if(i%2==0)
		{
			if(i%4==2) for(int j=1;j<=m-1;j++) a[i][j]='.';
			else for(int j=2;j<=m;j++) a[i][j]='.';
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cout<<a[i][j];
		}
		cout<<endl;
	}
	return 0;
}