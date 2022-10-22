#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> e[200010];
ll ans,a[200010];
ll dfs(int x,int f)
{
	ll m1=0,m2=0;
	for (auto p:e[x]) if (p!=f)
	{
		ll tp=dfs(p,x);
		if (tp>m1) m2=m1,m1=tp;
		else if (tp>m2) m2=tp;
	}
	if (f) if (a[x]>m1) ans+=a[x]-m1;
	if (!f)
	{
		if (!m2)
		{
			if (a[x]>m1) ans+=2*a[x]-m1;
			else ans+=a[x];
		}
		else ans+=max(0ll,a[x]-m1)+max(0ll,a[x]-m2);
	}
	return max(m1,a[x]);
}
int main()
{
	int n,i,o=0;cin>>n;
	for (i=1;i<=n;i++) {cin>>a[i];if (a[i]>a[o]) o=i;}
	for (i=1;i<n;i++)
	{
		int u,v;cin>>u>>v;
		e[u].push_back(v);e[v].push_back(u);
	}
	dfs(o,0);cout<<ans;
}