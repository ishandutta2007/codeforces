#include<bits/stdc++.h>
using namespace std;

int n;
int a[1010];
bool ok(int x)
{
	if (x<0)	return false;
	int y=sqrt(x);
	if (x==y*y)	return true;
	return false;
}
int main()
{
	scanf("%d",&n);
	int num=0;
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
	if (!ok(a[i]))
	{
		if (num==0 || a[i]>a[num])	num=i;
	}
	printf("%d\n",a[num]);
	return 0;
}