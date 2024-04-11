#include<cstdio>
inline int abs(int x)
{
	return x<0?-x:x;
}
signed main()
{
	int x1,y1,x2,y2,ans;
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	if(x1==x2)
		x2++;
	if(y1==y2)
		y2++;
	ans=abs(x2-x1)+abs(y2-y1)+2;
	printf("%d\n",ans<<1);
	return 0;
}