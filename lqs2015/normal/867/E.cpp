#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
priority_queue<long long> pq;
long long ans,n,p,x,pp;
int main()
{
	scanf("%I64d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%I64d",&x);
		if (pq.empty()) 
		{
			pq.push(-x);
			continue; 
		}
		p=-pq.top();
		if (x<=p) pq.push(-x);
		else
		{
			ans+=(x-p);
			pq.pop();
			pq.push(-x);
			pq.push(-x); 
		} 
	}
	printf("%I64d\n",ans);
	return 0;
}