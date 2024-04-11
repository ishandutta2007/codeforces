#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{int a,b,h;bool operator<(node c) const {return b!=c.b?b>c.b:a>c.a;}}a[100005];
struct qnod{int w,h;bool operator<(qnod b) const {return h<b.h;}};
int ans,n,f[100005];priority_queue<qnod>q;
signed main()
{
	scanf("%lld",&n),ans=0;
	for(int i=1;i<=n;i++) scanf("%lld%lld%lld",&a[i].a,&a[i].b,&a[i].h);
	sort(a+1,a+n+1),q.push((qnod){0,0});
	for(int i=1;i<=n;i++)
	{
		while(q.top().w>=a[i].b) q.pop();
		f[i]=q.top().h+a[i].h,q.push((qnod){a[i].a,q.top().h+a[i].h}),ans=max(ans,f[i]);
	}
	return printf("%lld\n",ans),0;
}