#include<bits/stdc++.h>
using namespace std;
long long p,ans;
int q,test,x;
void check(int x)
{
	long long c=p;
	while(c%q==0) c/=x;
	ans=max(ans,c);
}
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%lld%d",&p,&q);
		if (p%q) printf("%lld\n",p);
		else
		{
			x=sqrt(q);ans=-1e18;
			for (int i=2;i<=x;i++)
			{
				if (q%i==0)
				{
					check(i);
					check(q/i);
				}
			}
			check(q);
			printf("%lld\n",ans);
		}
	}
	return 0;
}