#include<cstdio>
struct time
{
	short h,m;
}clock;
int ans;
inline short turn(short x)
{
	return x%10*10+x/10;
}
signed main()
{
	int i,j;
	scanf("%hd",&clock.h);
	getchar();
	scanf("%hd",&clock.m);
	while(turn(clock.h)!=clock.m)
	{
		ans++;
		clock.m++;
		if(clock.m==60)
		{
			clock.m=0;
			clock.h++;
			if(clock.h==24)
				clock.h=0;
		}
	}
	printf("%d\n",ans);
	return 0;
}