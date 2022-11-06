#include<bits/stdc++.h>
#define re register
long long pl[2010][2010],d1[2010],d2[2010],dd[2010],p1[2010][2010],p2[2010][2010],f1[2010][2010],f2[2010][2010];
bool pk1[2010][2010],pk2[2010][2010];
int p[2010];
bool bo[2010];
int main()
{
	re int n,m,s,t,x,y,n1,n2;
	re long long z;
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(re int i=1;i<=n;i++)scanf("%d",&p[i]);
	for(re int i=1;i<=n;i++)for(re int j=1;j<=n;j++)pl[i][j]=1ll<<60; 
	for(re int i=1;i<=m;i++)scanf("%d%d%lld",&x,&y,&z),pl[x][y]=pl[y][x]=std::min(pl[x][y],z);
	for(re int i=0;i<=n;i++)d1[i]=d2[i]=1ll<<60;
	d1[s]=0;d2[t]=0;
	for(re int i=1;i<=n;i++)
	{
		re int no=0;
		for(re int j=1;j<=n;j++)if(!bo[j]&&d1[j]<d1[no])no=j;bo[no]=1;
		for(re int j=1;j<=n;j++)d1[j]=std::min(d1[j],d1[no]+pl[no][j]);
	}
	for(re int i=1;i<=n;i++)dd[i]=d1[i],bo[i]=0;
	std::sort(dd+1,dd+n+1);n1=std::unique(dd+1,dd+n+1)-dd-1;
	for(re int i=1;i<=n;i++)d1[i]=std::lower_bound(dd+1,dd+n1+1,d1[i])-dd;
	for(re int i=1;i<=n;i++)
	{
		re int no=0;
		for(re int j=1;j<=n;j++)if(!bo[j]&&d2[j]<d2[no])no=j;bo[no]=1;
		for(re int j=1;j<=n;j++)d2[j]=std::min(d2[j],d2[no]+pl[no][j]);
	}
	for(re int i=1;i<=n;i++)dd[i]=d2[i];
	std::sort(dd+1,dd+n+1);n2=std::unique(dd+1,dd+n+1)-dd-1;
	for(re int i=1;i<=n;i++)d2[i]=std::lower_bound(dd+1,dd+n2+1,d2[i])-dd;
	for(re int i=1;i<=n;i++)p1[d1[i]][d2[i]]+=p[i],p2[d1[i]][d2[i]]+=p[i],pk1[d1[i]][d2[i]]=pk2[d1[i]][d2[i]]=1;
	for(re int i=n1;i>=0;i--)
		for(re int j=n2;j>=0;j--)
		{
			p1[i][j]+=p1[i][j+1];p2[i][j]+=p2[i+1][j];
			pk1[i][j]|=pk1[i][j+1];pk2[i][j]|=pk2[i+1][j];
		}
	for(re int i=n1;i>=0;i--)
		for(re int j=n2;j>=0;j--)
		{
			if(i==n1)f1[i][j]=f2[i][j];
			else
			{
				f1[i][j]=f1[i+1][j]+p1[i+1][j+1];
				if(pk1[i+1][j+1])f1[i][j]=std::max(f1[i][j],f2[i+1][j]+p1[i+1][j+1]);
			}
			if(j==n2)f2[i][j]=f1[i][j];
			else
			{
				f2[i][j]=f2[i][j+1]-p2[i+1][j+1];
				if(pk2[i+1][j+1])f2[i][j]=std::min(f2[i][j],f1[i][j+1]-p2[i+1][j+1]);
			}
		}
	if(f1[0][0]<0)puts("Cry");
	else if(f1[0][0]>0)puts("Break a heart");
	else puts("Flowers");
}