#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;
int n;
int a[200000];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	sort(a,a+n);
	for(int i=0;i<n-2;i++)
	{
		if(a[i]+a[i+1]>a[i+2])
		{
			printf("YES");
			return 0;
		}
	}
	printf("NO");
	return 0;
}