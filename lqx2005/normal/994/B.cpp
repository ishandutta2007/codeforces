#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=100000;
struct node
{
	ll p,c,id;
	bool operator < (const node &a) const
	{
		return a.c>c;
	}
}a[N+5];
priority_queue<node> q,p;
bool cmp(node a,node b)
{
	return a.p<b.p;
}
ll n,k,ans[N+5];
int main()
{
	scanf("%lld%lld",&n,&k);
	for(ll i=1;i<=n;i++) scanf("%lld",&a[i].p);
	for(ll i=1;i<=n;i++) scanf("%lld",&a[i].c);
	for(ll i=1;i<=n;i++) a[i].id=i;
	sort(a+1,a+n+1,cmp);
	for(ll i=1;i<=n;i++)
	{
		ans[a[i].id]+=a[i].c;
		for(ll j=1;j<=k&&!q.empty();j++)
		{
			node now=q.top();
			q.pop();
			ans[a[i].id]+=now.c;
			p.push(now);
		}
		while(!p.empty()) q.push(p.top()),p.pop();
		q.push(a[i]);
	}
	for(ll i=1;i<=n;i++) printf("%lld ",ans[i]);
	printf("\n");
	return 0;
}