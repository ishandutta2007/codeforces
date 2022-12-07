#include<iostream>
#include<cstdio>
using namespace std;
int n;
long long ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
		ans+=i*(n-i);
	ans+=n;
	printf("%I64d\n",ans);
	return 0;
}