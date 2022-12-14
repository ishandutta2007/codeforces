#include<bits/stdc++.h>
using namespace std;
int test,num,t,aa[4],bb[4];
long long n,ans,cur,pp;
int main()
{
	scanf("%d",&test);
	aa[0]=0;aa[1]=2;aa[2]=3;aa[3]=1;
	bb[0]=0;bb[1]=3;bb[2]=1;bb[3]=2;
	while(test--)
	{
		scanf("%lld",&n);
		cur=1;num=0;
		while(cur*4<=n)
		{
			cur*=4;
			num++;
		}
		n-=cur;
		if (n%3==0)
		{
			t=1;
		}
		else if (n%3==1)
		{
			t=2;
		}
		else t=3;
		n/=3;
		if (t==1)
		{
			ans=cur+n;
		}
		else if (t==2)
		{
			pp=1;ans=2ll*cur;
			for (int i=1;i<=num;i++)
			{
				ans+=(pp*aa[n%4]);
				n/=4;
				pp*=4;
			}
		}
		else
		{
			pp=1;ans=3ll*cur;
			for (int i=1;i<=num;i++)
			{
				ans+=(pp*bb[n%4]);
				n/=4;
				pp*=4;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}