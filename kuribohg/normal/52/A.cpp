#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
int n,p,a[4];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&p);
		a[p]++;
	}
	sort(a+1,a+4);
	printf("%d\n",a[1]+a[2]);
	return 0;
}