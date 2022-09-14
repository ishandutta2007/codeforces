#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
main()
{
	double r,d;
	scanf("%lf%lf",&r,&d);
	int n;cin>>n;
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		double x,y,rr;
		scanf("%lf%lf%lf",&x,&y,&rr);
		cnt+=hypot(x,y)+rr<=r&&hypot(x,y)-rr>=r-d;
	}
	printf("%d\n",cnt);
}