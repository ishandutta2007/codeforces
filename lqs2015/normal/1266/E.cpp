#include<bits/stdc++.h>
using namespace std;
int n,a[222222],q,c[222222],s,t,u,b[222222];
long long ans;
map<pair<int,int>,int> mp;
void del(int s,int t,int u)
{
	mp[make_pair(s,t)]=0;
	ans-=max(0,a[u]-b[u]);
	ans+=max(0,a[u]-(b[u]-1));
	b[u]--;
}
void add(int s,int t,int u)
{
	mp[make_pair(s,t)]=u;
	ans-=max(0,a[u]-b[u]);
	ans+=max(0,a[u]-(b[u]+1));
	b[u]++;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) ans+=a[i];
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d%d",&s,&t,&u);
		if (mp[make_pair(s,t)])
		{
			del(s,t,mp[make_pair(s,t)]);
		}
		if (u)
		{
			add(s,t,u);
		}
		printf("%lld\n",ans);
	}
	return 0;
}