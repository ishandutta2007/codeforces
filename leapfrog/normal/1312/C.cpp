#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,k;long long a[35],g,mx;
priority_queue<int>q;
signed main()
{
	for(scanf("%lld",&t);t--;)
	{
		scanf("%lld%lld",&n,&k),g=1,mx=0;while(!q.empty()) q.pop();
		for(int i=1;i<=n;i++) scanf("%lld",a+i),mx=max(mx,a[i]);
		for(int i=1;i<=n;i++) if(a[i]) q.push(a[i]);
		while(g*k<=mx) g*=k;
		for(;g>=1&&!q.empty();g/=k)
		{
			int x=q.top();
			if(x<g) continue;else q.pop(),x-=g;
			if(x!=0) q.push(x);
			// printf("%lld\n",q.top());
		}
		if(q.empty()||q.top()==0) puts("YES");else puts("NO");
	}
	return 0;
}