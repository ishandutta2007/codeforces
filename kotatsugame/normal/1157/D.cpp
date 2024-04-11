#include<iostream>
#include<cstdio>
using namespace std;
long long N,K;
int a[1<<17];
main()
{
	cin>>N>>K;
	if(K*(K+1)>2*N)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	long long sum=N;
	for(int i=0;i<K;i++)
	{
		sum-=a[i]=i+1+(N-K*(K+1)/2)/K;
	}
	for(int ccc=0;ccc<1000;ccc++)
	{
		for(int i=K-1;i;i--)
		{
			long long di=a[i-1]*2-a[i];
			if(di<sum)
			{
				sum-=di;
				a[i]+=di;
			}
			else
			{
				a[i]+=sum;
				sum=0;
				break;
			}
		}
		if(sum==0)break;
	}
	if(sum)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES"<<endl;
	for(int i=0;i<K;i++)
	{
		printf("%d%c",a[i],i==K-1?'\n':' ');
	}
}