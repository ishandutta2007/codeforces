#include<iostream>
#include<cstdio>
using namespace std;
long long hzh[222222],num,sum,k,a[222222],sz;
int n,tp;
int main()
{
	scanf("%d",&n);
	sz=1.00;
	a[1]=0.00;
	while(n--)
	{
		scanf("%d",&tp);
		if (tp==1)
		{
			scanf("%I64d%I64d",&k,&num);
			hzh[k]+=num;
			sum+=k*num;
		}
		else if (tp==2)
		{
			scanf("%I64d",&num);
			sum+=num;
			sz+=1.00;
			a[sz]=num;
		}
		else
		{
			hzh[sz-1]+=hzh[sz];
			sum-=(a[sz]+hzh[sz]);
			hzh[sz]=0.00;
			sz-=1.00;
		}
		printf("%.6lf\n",(double)sum/(double)sz);
	}
	return 0;
}