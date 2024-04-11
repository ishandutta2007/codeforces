#pragma GCC optimize("Ofast",3,"inline")
#include<bits/stdc++.h>
typedef long long LL;
#define Deg //fprintf(stderr,"Passing [%s] line %d\n",__FUNCTION__,__LINE__)
using namespace std;
const int maxn=210000;
struct node
{
	LL a,b,d;
	node(LL A,LL B,LL D):a(A),b(B),d(D){}
	bool operator <(const node &x) const
	{
		return d>x.d;
	}
};
LL n,k;
LL a[maxn],b[maxn];
int check(LL x)
{
	priority_queue<node> q;
	for(register int i=1;i<=n;i++) q.push(node(a[i],b[i],a[i]/b[i]));
	for(register int i=1;i<=k-1;i++)
	{
		node S=q.top();
		q.pop();
		if(S.d<i-1) return 0;
		S.a+=x;
		S.d=S.a/S.b;
		q.push(S);
	}
	node S=q.top();
	if(S.d<k-1) return 0;
	return 1;
}
signed main()
{
	scanf("%lld%lld",&n,&k);
	for(register int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(register int i=1;i<=n;i++) scanf("%lld",&b[i]);
	LL inf=b[1];
	for(register int i=2;i<=n;i++) inf=max(inf,b[i]);
	LL l=0,r=inf*(k-1),best=-1;
	while(l<=r)
	{
		LL mid=(l+r)/2;
		if(check(mid)) best=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%lld\n",best); 
	return 0;
}