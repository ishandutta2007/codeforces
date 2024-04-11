#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
long long n,k,a[222222],sum,pos,pre;
char s[222222];
priority_queue<long long> q;
int main()
{
	scanf("%lld%lld",&n,&k);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		sum+=a[i];
	}
	scanf("%s",s);
	pos=0;
	while(pos<n)
	{
		pre=pos;
		while(!q.empty()) q.pop();
		while(pos<n && s[pos]==s[pre])
		{
			q.push(-a[pos+1]);
			pos++; 
		}
		while(q.size()>k)
		{
			sum+=q.top();
			q.pop();
		}
	}
	printf("%lld\n",sum);
	return Accepted;
}