#include<iostream>
#include<cstdio>
using namespace std;
int a[1001],n,m;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&m);
		a[m]++;
	}
	for(int i=1;i<=1000;i++)
		if(a[i]>((n+1)>>1))
		{
			puts("NO");
			return 0;
		}
	puts("YES");
	return 0;
}