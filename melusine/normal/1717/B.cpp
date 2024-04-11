#include<iostream>
#include<cstdio>
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
int dyy[1005];
int main()
{
	int t,n,k,r,c,x,y;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		k=read();
		r=read();
		c=read();
		r=(r-1)%k+1;
		c=(c-1)%k+1;
		dyy[r]=c;
		x=1;
		y=1;
		if(r==1)x++;
		if(c==1)y++;
		while(x<=k)
		{
			dyy[x]=y;
			x++;
			if(x==r)x++;
			y++;
			if(y==c)y++;
		}
		//for(int i=1;i<=k;i++)printf("%d ",dyy[i]);
		//printf("\n");
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if((j-1)%k+1==dyy[(i-1)%k+1])printf("X");
				else printf(".");
			}
			printf("\n");
		}
	}
	return 0;
}