#include<iostream>
#include<cstdio>
using namespace std;
long long n,m,a[222222],cur;
int main()
{
	scanf("%I64d%I64d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%I64d",&a[i]);
		cur=cur+a[i];
		printf("%I64d ",cur/m);
		cur%=m;
	}
	return 0;
}