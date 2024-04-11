#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;
int n;
int a[20];
long long k=1000000000;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int l=0;l<k;l++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				l++;
				if(j>0 && a[j]<a[j-1])
				{
					a[j-1]+=a[j];
					a[j]=a[j-1]-a[j];
					a[j-1]=a[j-1]-a[j];
				}
			}
		}
	}
	
	for(int i=0;i<n;i++) printf("%d ",a[i]);
	return 0;
}