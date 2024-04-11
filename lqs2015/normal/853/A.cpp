#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
priority_queue<pair<long long,int> > pq;
long long n,k,c[333333],ans[333333],co;
int main()
{
	scanf("%I64d%I64d",&n,&k);
	for (int i=1;i<=n;i++)
	{
		scanf("%I64d",&c[i]);
	}
	for (int i=1;i<=k;i++) pq.push(make_pair(c[i],i));
	for (int i=k+1;i<=k+n;i++)
	{
		if (i<=n) pq.push(make_pair(c[i],i));
		int id=pq.top().second;
		pq.pop();
		co+=(i-id)*c[id];
		ans[id]=i; 
	} 
	printf("%I64d\n",co);
	for (int i=1;i<=n;i++)
	{
		printf("%I64d ",ans[i]);
	}
	return 0;
}