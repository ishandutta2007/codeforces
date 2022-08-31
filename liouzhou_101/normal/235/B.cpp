#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
	int n;
	cin>>n;
	double sum=0,get=0;
	for (int i=1;i<=n;++i)
	{
		double x;
		scanf("%lf",&x);
		sum=sum+(get*2+1)*x;
		get=(get+1)*x;
	}
	printf("%.10lf\n",sum);
	return 0;
}