#include<bits/stdc++.h>
using namespace std;
#define re register
int qwq[110][110];
int main()
{
	re int n,x,bl=-1;
	scanf("%d",&n);
	for(re int i=1;i<=n;i++)for(re int j=1;j<=n;j++)qwq[i][j]=-1;
	qwq[1][1]=1;qwq[n][n]=0;qwq[1][2]=1;
	for(re int i=1;i<=n;i+=2)
	{
		for(re int j=1;j<=n;j++)if(qwq[i][j]==-1)
		{
			re int x1,y1;
			if(j<=2)x1=i-2,y1=j;
			else x1=i,y1=j-2;
			printf("? %d %d %d %d\n",x1,y1,i,j);
			fflush(stdout);
			scanf("%d",&x);
			qwq[i][j]=qwq[x1][y1]^x^1;
		}
	}
	for(re int i=2;i<=n;i+=2)
	{
		for(re int j=2;j<=n;j++)if(qwq[i][j]==-1)
		{
			re int x1,y1;
			x1=i-1,y1=j-1;
			printf("? %d %d %d %d\n",x1,y1,i,j);
			fflush(stdout);
			scanf("%d",&x);
			qwq[i][j]=qwq[x1][y1]^x^1;
		}
	}
	for(re int i=2;i<=n;i+=2)if(qwq[i][1]==-1)
	{
		printf("? %d 1 %d 2\n",i,i+1);
		fflush(stdout);
		scanf("%d",&x);
		qwq[i][1]=qwq[i+1][2]^x^1;
	}
	for(re int i=1;i<=n&&bl==-1;i+=2)
	{
		for(re int j=(i&1?1:2);j<=n&&bl==-1;j+=2)
		for(re int x1=1;x1<=2&&bl==-1;x1++)
		for(re int xx=-1;xx<=1&&bl==-1;xx+=2)
		for(re int yy=xx;yy<=xx&&bl==-1;yy+=2)
		if(i+x1*xx<=n&&i+x1*xx>0)
		if(j+(3-x1)*yy<=n&&j+(3-x1)*yy>0){
		
		{
			re int xx1,yy1,xx2,yy2;
			if(x1==1)
			{
				xx1=i+xx;yy1=j+yy;
				xx2=i;yy2=j+2*yy;
			}else xx1=i+2*xx,yy1=j,xx2=i+xx,yy2=j+yy;
			if((qwq[i][j]^qwq[i+xx*x1][j+yy*(3-x1)])==(qwq[i+xx][j]^qwq[xx1][yy1])||(qwq[i][j]^qwq[i+xx*x1][j+yy*(3-x1)])==(qwq[i][j+yy]^qwq[xx2][yy2]))
			{
				if(xx==1)printf("? %d %d %d %d\n",i,j,i+xx*x1,j+yy*(3-x1));
				else printf("? %d %d %d %d\n",i+xx*x1,j+yy*(3-x1),i,j);
				fflush(stdout);
				scanf("%d",&x);
				bl=qwq[i][j]^qwq[i+xx*x1][j+yy*(3-x1)]^x^1;
			}
		}		
		}
	}
	puts("!");
	for(re int i=1;i<=n;i++){for(re int j=1;j<=n;j++)printf("%d",((i+j)&1)?qwq[i][j]^bl:qwq[i][j]);puts("");}
}