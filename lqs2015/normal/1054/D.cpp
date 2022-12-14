#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
long long n,k,a[222222],sum[222222],ans,x,y,cur;
map<long long,long long> mp;
int main()
{
	scanf("%I64d%I64d",&n,&k);
	for (long long i=1;i<=n;i++) scanf("%I64d",&a[i]);
	mp[0]++;
	for (long long i=1;i<=n;i++) 
	{
		sum[i]=sum[i-1]^a[i];
		mp[sum[i]]++;
	}
	ans=n*(n+1)/2;
	for (map<long long,long long>::iterator it=mp.begin();it!=mp.end();it++)
	{
		x=it->first;y=(1<<k)-1-x;
		if (mp.find(x)!=mp.end() && mp.find(y)!=mp.end() && x>y) continue;
		cur=mp[x]+mp[y];
		ans-=((cur/2)*(cur/2-1)/2+(cur-cur/2)*(cur-cur/2-1)/2);
	}
	printf("%I64d\n",ans);
	return 0;
}