#include<iostream>
#include<algorithm>
using namespace std;
int n;
long long m,a[2<<17];
main()
{
	scanf("%d%lld",&n,&m);
	long asum=0;
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
		asum+=a[i];
	}
	if(asum<m)
	{
		cout<<-1<<endl;
		return 0;
	}
	sort(a,a+n);
	int L=0,R=n;
	while(R-L>1)
	{
		int M=(L+R)/2;
		long long sum=0;
		int id=0;
		for(int k=0;sum<m&&id<n;k++)
		{
			for(int i=0;i<M&&id<n;i++)
			{
				if(a[n-id-1]-k<0)
				{
					id=n;
					break;
				}
				sum+=a[n-id-1]-k;
				id++;
			}
		}
		if(sum<m)L=M;
		else R=M;
	}
	cout<<R<<endl;
}