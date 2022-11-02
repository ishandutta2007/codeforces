#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=100010;
priority_queue<ll,vector<ll>,greater<ll> > que;
int a[maxn],b[maxn];
int n;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	ll all=0;
	for (int i=1;i<=n;i++)
	{
		ll sum=0;
		que.push(a[i]+all);
		all+=b[i];
		while (!que.empty() && que.top()<=all)
		{
			sum+=que.top()-all+b[i];
			que.pop();
		}
		printf("%lld%c",sum+que.size()*1LL*b[i],i==n?'\n':' ');
	}
	return 0;
}