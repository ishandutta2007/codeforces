#include<bits/stdc++.h>
using namespace std;
int n,m,sx,sy;
int main()
{
	scanf("%d%d%d%d",&n,&m,&sx,&sy);
	for(int i=sx;i>=1;i--)
	{
		if((sx-i)&1) for(int j=1;j<=sy;j++) printf("%d %d\n",i,j);
		else for(int j=sy;j>=1;j--) printf("%d %d\n",i,j);
	}
	int z=(sx-1)&1;
	for(int i=sx+1;i<=n;i++)
	{
		if(((i-sx)&1)^z) for(int j=1;j<=sy;j++) printf("%d %d\n",i,j);
		else for(int j=sy;j>=1;j--) printf("%d %d\n",i,j);
	}
	for(int i=n;i>=1;i--)
	{
		if((i-sx)&1) for(int j=sy+1;j<=m;j++) printf("%d %d\n",i,j);
		else for(int j=m;j>sy;j--) printf("%d %d\n",i,j);
	}
	return 0;
}