#include<bits/stdc++.h>
#define re register
int vv[1010][1010],rvv[1010][1010],vvc[1010][1010],vvr[1010][1010],ax,ay,av,bx,by,rv;
char ss[100100];
void rx()
{
	if(bx)bx=0;
	else
	{
		if(by)rv^=1;
		else bx=1;
	}
}
void ry()
{
	if(by)by=0;
	else
	{
		if(bx)rv^=1;
		else by=1;
	}
}
int main()
{
	re int T,n,m;
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&n,&m);
		ax=ay=av=0;
		bx=0,by=0,rv=0;
		for(re int i=0;i<n;i++)
			for(re int j=0;j<n;j++)scanf("%d",&vv[i][j]),rvv[j][i]=vv[i][j];
		scanf("%s",ss+1);
		for(re int i=1;i<=m;i++)
		{
			switch(ss[i])
			{
				case 'R':ay++;break;
				case 'L':ay--;break;
				case 'D':ax++;break;
				case 'U':ax--;break;
				case 'C':std::swap(ax,av);ry();break;
				case 'I':std::swap(ay,av);rx();break;
			}
		}
		if(rv)
		for(re int i=0;i<n;i++)
			for(re int j=0;j<n;j++)vv[i][j]=rvv[i][j];
		for(re int i=0;i<n;i++)
			for(re int j=0;j<n;j++)vvr[i][vv[i][j]-1]=j,vvc[j][vv[i][j]-1]=i;
		for(re int i=0;i<n;i++)
			for(re int j=0;j<n;j++)
			{
				re int ii=i-ax,jj=j-ay,vc;
				ii=(ii%n+n)%n;jj=(jj%n+n)%n;
				if(bx)
				{
					vc=vvr[ii][jj];
				}
				else if(by)vc=vvc[jj][ii];
				else
				{
					vc=vv[ii][jj]-1;
				}
				vc=(vc+av)%n;
				vc=(vc+n)%n;
				printf("%d%c",vc+1,(j==n-1?'\n':' '));
			}
		puts("");
	}
}