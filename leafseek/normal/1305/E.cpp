#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
int main()
{
	register int n,m;
	scanf("%d%d",&n,&m);
	if(n==1)
	{
		if(m==0)
			printf("1 \n");
		else
			printf("-1\n");
		return 0;
	}
	register int pit=0,ext=0,cnt,Max,Sum=0;
	while((Sum+(pit>>1))<=m)
		++pit,Sum+=((pit-1)>>1);
	if(m!=Sum)
		ext=(pit-(m-Sum))<<1;
	cnt=(pit+((ext==0)?0:1));
	if(cnt<=n)
	{
		rep(i,1,pit)
			printf("%d ",i);
		if(ext!=0)
			printf("%d ",ext);
		Max=max(pit,ext);
		rep(i,cnt+1,n)
			printf("%d ",Max*((i-cnt)<<1|1));
		printf("\n");
	}
	else
		printf("-1\n");
	return 0;
}