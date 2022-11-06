#include<bits/stdc++.h>
#define re register
int r[310],c[310],qx[310*310],qy[310*310],aa[310][310],ta;
int main()
{
	re int n,m,x,tx=0,ty=0;
	scanf("%d%d",&n,&m);
	for(re int i=1;i<=n;i++)
		for(re int j=1;j<=m;j++)scanf("%d",&x),r[i]=std::max(r[i],x),c[j]=std::max(c[j],x);
	std::sort(r+1,r+n+1);
	std::reverse(r+1,r+n+1);
	std::sort(c+1,c+m+1);
	std::reverse(c+1,c+m+1);
	re int hd=1; 
	for(re int i=n*m;i;i--)
	{
		re bool bl=0;
		if(tx<n&&r[tx+1]==i)
		{
			bl=1;
			tx++;
			for(re int j=ty;j;j--)qx[++ta]=tx,qy[ta]=j;
		}
		if(ty<m&&c[ty+1]==i)
		{
			bl=1;
			ty++;
			for(re int j=tx;j;j--)qx[++ta]=j,qy[ta]=ty;
		}
		if(hd>ta){puts("-1");return 0;}
		if(bl)aa[tx][ty]=i;
		else
		{
			while(aa[qx[hd]][qy[hd]])hd++;
			aa[qx[hd]][qy[hd]]=i,hd++;
		}
	}
	for(re int i=1;i<=n;i++,puts(""))
		for(re int j=1;j<=m;j++)printf("%d ",aa[i][j]);
}