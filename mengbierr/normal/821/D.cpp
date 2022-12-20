#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int inf=0x7f7f7f7f;
int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9')
	{f=(f<<1)+(f<<3)+ch-'0';
	ch=getchar();}
	return f;
}
int r[10005],c[10005],d[10005]={inf};
int n,m,k,jd;
bool flag=0,vis[10005];
int main()
{
	int i,id;
	n=read();m=read();k=read();
	for(int i=1;i<=k;i++)
	{
		scanf("%d %d",r+i,c+i);
		if(r[i]==n&&c[i]==m)
		flag=1;
		if(r[i]==1&&c[i]==1)
		jd=i;
		d[i]=inf;
	}
	if(!flag)
	{
		r[++k]=++n;
		c[k]=++m;
	}
	d[k]=0;
	while(1)
	{
		id=0;
		for(int i=1;i<=k;i++)
		{
			if(vis[i])
			continue;
			if(d[i]<d[id])
			id=i;
		}
		if(!id||jd==id)
		break;
		vis[id]=1;
		for(int i=1;i<=k;i++)
		{
			if(vis[i])
			continue;
			if(abs(r[i]-r[id])+abs(c[i]-c[id])<=1)
			d[i]=d[id];
			else if(abs(r[i]-r[id])<=2||abs(c[i]-c[id])<=2)
			d[i]=min(d[id]+1,d[i]);
		}
	}
	if(d[jd]==inf)
	printf("-1");
	else printf("%d",d[jd]);
}