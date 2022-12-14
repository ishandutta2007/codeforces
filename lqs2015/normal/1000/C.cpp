#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long n,l,r,pos,cnt,ans[222222],cur;
pair<long long,long long> k[444444];
int main()
{
	scanf("%I64d",&n);
	for (long long i=1;i<=n;i++)
	{
		scanf("%I64d%I64d",&l,&r);
		k[i*2-1]=make_pair(l,0);
		k[i*2]=make_pair(r,1);
	}
	sort(k+1,k+2*n+1);
	cur=1;
	while(cur<=2*n)
	{ 
		pos=cur;
		while(pos<=2*n && k[pos].first==k[cur].first && k[pos].second==0)
		{
			cnt++;
			pos++;
		}
		ans[cnt]++;
		while(pos<=2*n && k[pos].first==k[cur].first)
		{
			cnt--;
			pos++;
		}
		cur=pos;
		if (cur<=2*n) ans[cnt]+=(k[cur].first-k[cur-1].first-1);
	}
	for (long long i=1;i<=n;i++) printf("%I64d ",ans[i]);
	return 0;
}