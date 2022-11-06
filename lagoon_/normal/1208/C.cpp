#include<bits/stdc++.h>
using namespace std;
#define re register
int a1[4][4]={8,9,1,13,3,12,7,5,0,2,4,11,6,10,15,14};
int qwq[1010][1010];
int main()
{
	re int n;
	scanf("%d",&n);
	for(re int i=1;i<=n/4;i++)
	{
		for(re int j=1;j<=n/4;j++)
		{
			re int x=((i-1)*n/4+j-1)*16;
			for(re int i1=0;i1<=3;i1++)
			{
				for(re int j1=0;j1<=3;j1++)
				{
					qwq[i*4+i1-3][j*4+j1-3]=a1[i1][j1]+x;
				}
			}
		}
	}
	for(re int i=1;i<=n;i++)for(re int j=1;j<=n;j++)printf("%d%c",qwq[i][j],(j==n)?'\n':' ');
}