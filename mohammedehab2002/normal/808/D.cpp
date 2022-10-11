#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <map>
using namespace std;
long long arr[100005],sum;
map<long long,int> m[2];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
    	scanf("%I64d",&arr[i]);
    	sum+=arr[i];
    	m[0][sum]=i+1;
	}
	sum=0;
	for (int i=n-1;i>=0;i--)
	{
		sum+=arr[i];
		m[1][sum]=i+1;
	}
	if (sum%2)
	{
		printf("NO");
		return 0;
	}
	sum/=2;
	bool b=0;
	for (int i=0;i<n;i++)
	{
		if (m[0][sum-arr[i]] && m[0][sum-arr[i]]<i+1)
		b=1;
		if (m[1][sum-arr[i]] && m[1][sum-arr[i]]>i+1)
		b=1;
		if (m[0][sum+arr[i]] && m[0][sum+arr[i]]>i+1)
		b=1;
		if (m[1][sum+arr[i]] && m[1][sum+arr[i]]<i+1)
		b=1;
	}
	if (b)
	printf("YES");
	else
	printf("NO");
}