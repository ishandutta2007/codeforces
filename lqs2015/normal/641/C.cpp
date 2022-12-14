#include<iostream>
#include<cstdio>
using namespace std;
int n,q,x,y,tp,w,ans[1111111];
int main()
{
	scanf("%d%d",&n,&q);
	x=1,y=2;
	while(q--)
	{
		scanf("%d",&tp);
		if (tp==1)
		{
			scanf("%d",&w);
			x+=w;
			if (x>n) x-=n;
			if (x<=0) x+=n;
			y+=w;
			if (y>n) y-=n;
			if (y<=0) y+=n;
		}
		else 
		{
			if (x&1) x++;
			else x--;
			if (y&1) y++;
			else y--;
		}
	}
	for (int i=1;i<=n;i++)
	{
		if (i&1) 
		{
			ans[x]=i;
			x+=2;
			if (x>n) x-=n;
		}
		else
		{
			ans[y]=i;
			y+=2;
			if (y>n) y-=n;
		}
	}
	for (int i=1;i<=n;i++)
	printf("%d ",ans[i]);
	printf("\n");
	return 0;
}