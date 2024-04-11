#include<iostream>
#include<cstdio>
#include<algorithm>
#include<utility>
using namespace std;
pair<long long,int>c[3<<17];
int n;
bool f(long long x1,long long x2,bool whichis)
{
	for(long long i=0;i<n;i++)
	{
		long long F=0,L=i+1;
		while(L-F>1)
		{
			long long M=(F+L)/2;
			if(c[i].first*(i+1-M)>=x2)F=M;
			else L=M;
		}
		if(F>0&&x1<=c[F-1].first*F)
		{
			puts("Yes");
			if(whichis)
			{
				printf("%lld %lld\n",F,i+1-F);
				for(int j=0;j<F;j++)printf("%d%c",c[j].second,j==F-1?'\n':' ');
				for(int j=F;j<=i;j++)printf("%d%c",c[j].second,j==i?'\n':' ');
			}
			else
			{
				printf("%lld %lld\n",i+1-F,F);
				for(int j=F;j<=i;j++)printf("%d%c",c[j].second,j==i?'\n':' ');
				for(int j=0;j<F;j++)printf("%d%c",c[j].second,j==F-1?'\n':' ');
			}
			return true;
		}
	}
	return false;
}
main()
{
	long long X1,X2;
	scanf("%d%lld%lld",&n,&X1,&X2);
	for(int i=0;i<n;i++)
	{
		long long a;scanf("%lld",&a);
		c[i].first=a;
		c[i].second=i+1;
	}
	sort(c,c+n,greater<pair<long long,int> >());
	if(!f(X1,X2,1)&&!f(X2,X1,0))puts("No");
	return 0;
}