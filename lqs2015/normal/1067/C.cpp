#include<iostream>
#include<cstdio>
using namespace std;
int n,s,p,t;
int main()
{
	cin>>n;
	if (n>=38)
	{
		s=(n+1)/2;
		for (int i=0;i<s;i++)
		{
			printf("%d %d\n",i,0);
		}
		p=s/2;t=p;
		for (int i=s+1;i<=n;i++)
		{
			printf("%d %d\n",p,t);
			t--;
			if (!t) t--;
		}
	}
	else
	{
		p=n/2;
		for (int i=1;i<=p;i++)
		{
			printf("%d %d\n",i,0);
		}
		for (int i=1;i<=n-p;i++)
		{
			printf("%d %d\n",i,4);
		}
	}
	return 0;
}