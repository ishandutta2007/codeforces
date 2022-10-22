#include <iostream>
#include <cstdio>
using namespace std;
int n;
int t;
int a[300000];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=0;i<n/2;i++)
	{
		if(i%2==0)
		{
			t=a[n-i-1];
			a[n-i-1]=a[i];
			a[i]=t;
		}
	}
	for(int i=0;i<n;i++) printf("%d ",a[i]);
	return 0;
}