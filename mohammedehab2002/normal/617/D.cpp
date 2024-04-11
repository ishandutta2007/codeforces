#include <iostream>
using namespace std;
int ans=3;
int main()
{
	int x1,y1,x2,y2,x3,y3;
	scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
	if ((x1==x2 && x2==x3) || (y1==y2 && y2==y3))
	{
		puts("1");
		return 0;
	}
	if (x1==x2)
	{
		if (!(y3>min(y1,y2) && y3<max(y1,y2)))
		ans=2;
	}
	if (x1==x3)
	{
		if (!(y2>min(y1,y3) && y2<max(y1,y3)))
		ans=2;
	}
	if (x3==x2)
	{
		if (!(y1>min(y3,y2) && y1<max(y3,y2)))
		ans=2;
	}
	if (y1==y2)
	{
		if (!(x3>min(x1,x2) && x3<max(x1,x2)))
		ans=2;
	}
	if (y1==y3)
	{
		if (!(x2>min(x1,x3) && x2<max(x1,x3)))
		ans=2;
	}
	if (y3==y2)
	{
		if (!(x1>min(x3,x2) && x1<max(x3,x2)))
		ans=2;
	}
	printf("%d",ans);
}