#include<bits/stdc++.h>
using namespace std;

const int maxn=200010;
typedef long long ll;
struct Event
{
	ll x,op;
}	e[maxn<<1];
int cnt,n;
ll ans[maxn];
bool cmp(const Event &a,const Event &b)
{
	if (a.x!=b.x)	return a.x<b.x;
	return a.op<b.op;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		ll l,r;
		scanf("%lld%lld",&l,&r);
		cnt++;
		e[cnt].x=l;
		e[cnt].op=1;
		cnt++;
		e[cnt].x=r+1;
		e[cnt].op=-1;
	}
	sort(e+1,e+cnt+1,cmp);
	int i=1;
	int now=0;
	ll pre=0;
	while (i<=cnt)
	{
		ll x=e[i].x;
		if (now!=0)	ans[now]+=x-pre;
		while (i<=cnt && e[i].x==x)	now+=e[i].op,i++;
		pre=x;
	}
	for (int i=1;i<=n;i++)	printf("%lld ",ans[i]);
	return 0;
}