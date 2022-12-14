#include<iostream>
#include<cstdio>
using namespace std;
int n,a,b,t,tota,totb,totk,ans;
int main()
{
	scanf("%d%d%d",&n,&a,&b);
	tota=a;totb=b;totk=0;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&t);
		if (t==1)
		{
			if (tota) tota--;
			else if (totb)
			{
				totb--;
				totk++;
			}
			else if (totk) totk--;
			else ans++;
		}
		else
		{
			if (totb) totb--;
			else ans+=2;
		}
	}
	printf("%d\n",ans);
	return 0;
}