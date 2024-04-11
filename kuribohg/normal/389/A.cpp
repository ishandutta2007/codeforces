#include<iostream>
#include<cstdio>
using namespace std;
int n,a[1001],ans;
int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
int main()
{
	scanf("%d",&n);
	scanf("%d",&a[1]);
	ans=a[1];
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&a[i]);
		ans=gcd(ans,a[i]);
	}
	printf("%d\n",ans*n);
	return 0;
}