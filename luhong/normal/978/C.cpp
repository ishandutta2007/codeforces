#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
long long a[1010000],sum[1010000],b[1010000];
int main()
{
	int n,m;scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%I64d",&a[i]),sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=m;i++)scanf("%I64d",&b[i]);
	for(int i=1;i<=m;i++)
	{
		int k=lower_bound(sum+1,sum+n+1,b[i])-sum;
		printf("%d %I64d\n",k,b[i]-sum[k-1]);
	}
	return 0;
}