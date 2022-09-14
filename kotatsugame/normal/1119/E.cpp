#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int N;
long long a[333333],ans,s;
main()
{
	scanf("%d",&N);
	long long now=0;
	for(int i=0;i<N;i++)
	{
		scanf("%lld",a+i);
		if(a[i]%2==1&&a[i]>=3)
		{
			a[i]-=3;
			now++;
		}
	}
	int id=0;
	for(int i=0;i<N;i++)
	{
		if(a[i]==1)
		{
			if(id<=i)id=i+1;
			while(id<N&&a[id]<2)id++;
			if(id==N)break;
			a[i]--;
			a[id]-=2;
			now++;
		}
	}
	for(int i=0;i<N;i++)if(a[i]>=2)s+=a[i];
	printf("%lld\n",now+s/3);
}