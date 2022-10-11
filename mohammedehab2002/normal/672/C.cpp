#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
double dist(long long x1,long long x2,long long y1,long long y2)
{
	return sqrt((pow(x1-x2,2)+pow(y1-y2,2)));
}
int main()
{
	long long ax,ay,bx,by,binx,biny,n;
	double o=0;
	cin >> ax >> ay >> bx >> by >> binx >> biny;
	cin >> n;
	pair<long long,long long> arr[n];
	for (int i=0;i<n;i++)
	{
		cin >> arr[i].first >> arr[i].second;
		o+=2.0*dist(arr[i].first,binx,arr[i].second,biny);
	}
	double arr1[n],arr2[n];
	for (int i=0;i<n;i++)
	{
		arr1[i]=dist(ax,arr[i].first,ay,arr[i].second)-dist(arr[i].first,binx,arr[i].second,biny);
		arr2[i]=dist(bx,arr[i].first,by,arr[i].second)-dist(arr[i].first,binx,arr[i].second,biny);
	}
	double obt1=arr2[0];
	int pos=0;
	for (int i=1;i<n;i++)
	{
		if (arr2[i]<obt1)
		{
			obt1=arr2[i];
			pos=i;
		}
	}
	double ans=1000000000000000000.0;
	for (int i=0;i<n;i++)
	{
		if (i==pos)
		{
			for (int x=0;x<n;x++)
			{
				if (x==i)
				continue;
				ans=min(ans,arr2[x]+arr1[i]);
			}
		}
		else
		ans=min(ans,obt1+arr1[i]);
	}
	double alla=o+arr1[0],allb=o+arr2[0];
	for (int i=1;i<n;i++)
	{
		alla=min(alla,arr1[i]+o);
		allb=min(allb,arr2[i]+o);
	}
	alla=min(alla,allb);
	ans=min(ans+o,alla);
	printf("%.8lf",ans);
}