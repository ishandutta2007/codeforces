#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,m,x,y,xx,yy;
int main()
{
	scanf("%d%d",&n,&m);
	x=1;y=n;
	while(x<=y)
	{
		if (x==y)
		{
			xx=1;yy=m;
			while(xx<=yy)
			{
				if (xx<=yy) printf("%d %d\n",x,xx);
				xx++;
				if (xx<=yy) printf("%d %d\n",x,yy);
				yy--;
			}
			break;
		}
		else
		{
			for (int j=1;j<=m;j++)
			{
				printf("%d %d\n",x,j);
				printf("%d %d\n",y,m-j+1);
			}
			x++;y--;
		}
	}
	return Accepted;
}