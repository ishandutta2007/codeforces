#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
long long n,m,a[333333],b[333333],sum,ans,cnt;
map<long long,long long> mp;
int main()
{
	scanf("%I64d",&n);
	for (long long i=1;i<=n;i++)
	{
		scanf("%I64d",&a[i]);
		sum+=a[i];
		mp[sum]=1;
	}
	scanf("%I64d",&m);
	for (long long i=1;i<=m;i++)
	{
		scanf("%I64d",&b[i]);
		cnt+=b[i];
		if (mp.find(cnt)!=mp.end()) ans++;
	}
	if (cnt!=sum) printf("-1\n");
	else printf("%I64d\n",ans);
	return 0;
}