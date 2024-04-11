#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=100000;
int t,n,m,a[maxn+5],b[maxn+5],v[maxn+5];
signed main()
{
	scanf("%lld",&t);
	for(int tot=1;tot<=t;tot++)
	{
		scanf("%lld%lld",&n,&m);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		for(int i=1;i<=m;i++) scanf("%lld",&b[i]);
		for(int i=1;i<=n;i++) v[i]=0;
		deque<int> c,d;
		for(int i=1;i<=n;i++) c.push_back(a[i]);
		int sz=0,ans=0;
		for(int i=1;i<=m;i++)
		{
			if(v[b[i]]) 
			{
				ans++,sz--;
				continue;
			} 
			while(c.front()!=b[i]) v[c.front()]=1,d.push_back(c.front()),c.pop_front();
			v[c.front()]=1,d.push_back(c.front()),c.pop_front();
			ans+=2*((int)d.size()+sz)-1;
			sz--;
		}
		printf("%lld\n",ans);
	}
	return 0;
}