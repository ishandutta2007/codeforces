#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[101000];
bool ok[101000];
int main()
{
	int n,k,l;scanf("%d%d%d",&n,&k,&l);
	for(int i=1;i<=n*k;i++)scanf("%d",&a[i]);
	sort(a+1,a+n*k+1);long long sum=0;int tot=n;
	int u=upper_bound(a+1,a+n*k+1,a[1]+l)-a-1;
	for(int i=1;i<=u;i+=k)ok[i]=1,tot--;
	for(int i=u;i>=1&&tot>0;i--)
		if(ok[i]!=1)ok[i]=1,tot--;
	if(tot>0)return 0*puts("0");
	for(int i=1;i<=n*k;i++)if(ok[i])sum+=a[i];
	printf("%lld",sum);return 0;
}