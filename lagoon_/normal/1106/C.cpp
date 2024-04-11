#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
using namespace std;
#define re register
#define dmin(a,b) ((a)<(b)?(a):(b))
int a[1001000];
int main()
{
	re int n;
	re long long s=0;
	scanf("%d",&n);
	for(re int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	for(re int i=1;i*2<=n;i++)s+=(long long)(a[i]+a[n-i+1])*(a[i]+a[n-i+1]);
	printf("%lld",s);
}