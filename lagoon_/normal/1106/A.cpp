#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
using namespace std;
#define re register
char c[510][510];
int main()
{
	re int n,ans=0;
	scanf("%d",&n);
	for(re int i=1;i<=n;i++)
	{
		scanf("%s",c[i]+1);
	}
	for(re int i=2;i<n;i++)
	{
		for(re int j=2;j<n;j++)
		{
			if(c[i][j]=='X'&&c[i-1][j+1]=='X'&&c[i+1][j+1]=='X'&&c[i-1][j-1]=='X'&&c[i+1][j-1]=='X')ans++;
		}
	}
	printf("%d\n",ans);
}