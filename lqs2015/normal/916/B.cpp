#include<iostream>
#include<cstdio>
using namespace std;
long long n,k,cur,num[111111],sum,re,pp,pos;
long long max(long long a,long long b)
{
	if (a>b) return a;
}
long long pow(long long a,long long b)
{
	long long res=1;
	for (int i=1;i<=b;i++)
	res*=a;
	return res;
}
int main()
{
	scanf("%I64d%I64d",&n,&k);
	for (long long i=60;i>=0;i--)
	{
		if (n>=pow(2,i))
		{
			num[i+100000]++;
			sum++;
			n-=pow(2,i);
		}
	}
	if (sum>k) 
	{
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	re=k-sum;
	for (long long i=60;i>=-30;i--)
	{
		if (re<=0) break;
		if (num[i+100000]>0)
		{
			if (re<num[i+100000])
			{
				for (int j=-30;j<=i;j++) 
				{
					if (num[j+100000]>0)
					{
						pos=j;
						break;
					}
				}
				re++;
				num[pos+100000]--;
				for (int k=1;k<=re-2;k++)
				{
					num[pos+100000-k]++;
				}
				num[pos+100001-re]+=2;
				re=0;
			}
			else
			{
				pp=num[i+100000];
				num[i+100000]-=pp;
				num[i+99999]+=pp*2;
				re-=pp;
			}
		}
	}
	for (long long i=60;i>=-100000;i--)
	{
		for (long long j=1;j<=num[i+100000];j++)
		{
			printf("%I64d ",i);
		}
	}
	printf("\n");
	return 0;
}