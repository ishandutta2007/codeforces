#include <iostream>
#include <algorithm>
using namespace std;
long long arr[100005],n,m;
long long c[100005];
long long check(long long x)
{
	for (long long i=0;i<n;i++)
	c[i]=arr[i]+(i+1)*x;
	sort(c,c+n);
	long long sum=0;
	for (int i=0;i<x;i++)
	sum+=c[i];
	return sum;
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++)
    scanf("%d",&arr[i]);
    int st=0,en=n+1;
    while (st!=en)
    {
    	int mid=(st+en)/2;
    	if (check(mid)<=m)
    	st=mid+1;
    	else
    	en=mid;
	}
	printf("%d %I64d",st-1,check(st-1));
}