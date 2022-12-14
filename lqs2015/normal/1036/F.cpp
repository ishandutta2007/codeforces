#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const double eps=1e-9;
long long t,n,ans,cur,cnt,x,pw[111];
long long pri[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61};
bool f;
int main()
{
	scanf("%I64d",&t);
	while(t--)
	{
		scanf("%I64d",&n);
		ans=n-1;
		for (long long i=2;i<=63;i++) 
		{
			pw[i]=(long long)pow((double)n,1.00/(double)i);
			pw[i]++;
			for (int j=1;j<=4;j++)
			{
				if (i&1)
				{
					cur=pow(pw[i],i/2);
					if (cur>n/cur/pw[i])
					{
						pw[i]--;
						continue;
					}
					else break;
				}
				else
				{
					cur=pow(pw[i],i/2);
					if (cur>n/cur)
					{
						pw[i]--;
						continue;
					}
					else break;
				}
			}
			pw[i]--;
		}
		ans-=pw[30];ans-=pw[42];
		for (long long i=0;i<18;i++)
		{
			ans-=pw[pri[i]];
		}
		for (long long i=0;i<18;i++)
		{
			for (long long j=i+1;j<18;j++)
			{
				if (pri[i]*pri[j]<=63) ans+=pw[pri[i]*pri[j]]; 
			}
		}
		printf("%I64d\n",ans);
	}
	return 0;
}