#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long ans=0;
vector<long long> c;
int p[200005],vis[200005];
long long go(int node)
{
	if (vis[node])
	return 0;
	vis[node]=1;
	return 1+go(p[node]);
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	scanf("%d",&p[i]);
	for (int i=1;i<=n;i++)
	{
		if (!vis[i])
		c.push_back(go(i)),ans+=c.back()*c.back();
	}
	sort(c.begin(),c.end());
	if (c.size()>1)
	ans+=2LL*c[c.size()-1]*c[c.size()-2];
	printf("%I64d",ans);
}