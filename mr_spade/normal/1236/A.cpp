#include<cstdio>
#include<iostream>
using std::min;
int T;
int a,b,c;
inline void solve()
{
	int res=0;
	register int i;
	scanf("%d%d%d",&a,&b,&c);
	for(i=0;i<=a&&i*2<=b;i++)
	{
		if(3*i+3*min(c/2,b-2*i)>res)
			res=3*i+3*min(c/2,b-2*i);
	}
	printf("%d\n",res);
	return;
}
signed main()
{
	scanf("%d",&T);
	while(T--)
		solve();
	return 0;
}