#include <iostream>
#include <math.h>
using namespace std;
long long sh[62];
int ilog(long long x)
{
	int ans=0;
	while ((1LL<<ans)<=x)
	ans++;
	return ans-1;
}
void go(long long x,int dep)
{
	if (dep==-1)
	return;
	printf("%I64d ",(x-sh[dep]+(1LL<<dep))%(1LL<<dep)+(1LL<<dep));
	go(x/2,dep-1);
}
int main()
{
	int q;
	scanf("%d",&q);
	while (q--)
	{
		int t;
		long long x;
		scanf("%d%I64d",&t,&x);
		int dep=ilog(x);
		if (t==3)
		{
			go((x+sh[dep])%(1LL<<dep),dep);
			printf("\n");
		}
		else
		{
			long long k;
			scanf("%I64d",&k);
			int sign=(k>=0);
			k=abs(k);
			if (t==1)
			sh[dep]=(sh[dep]+(sign? k:-k)%(1LL<<dep)+(1LL<<dep))%(1LL<<dep);
			else
			{
				for (int i=dep;i<62;i++)
				{
					sh[i]=(sh[i]+(sign? k:-k)%(1LL<<i)+(1LL<<i))%(1LL<<i);
					k=((2*k)&((1LL<<61)-1));
				}
			}
		}
	}
}