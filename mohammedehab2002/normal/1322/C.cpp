#include <bits/stdc++.h>
using namespace std;
map<vector<int>,long long> w;
vector<int> v[500005];
long long c[500005];
long long gcd(long long a,long long b)
{
	if (!a || !b)
	return (a^b);
	return __gcd(a,b);
}
int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		long long g=0;
		w.clear();
		for (int i=1;i<=n;i++)
		{
			scanf("%I64d",&c[i]);
			v[i].clear();
		}
		while (m--)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			v[b].push_back(a);
		}
		for (int i=1;i<=n;i++)
		{
			sort(v[i].begin(),v[i].end());
			if (!v[i].empty())
			w[v[i]]+=c[i];
		}
		for (auto p:w)
		g=gcd(g,p.second);
		printf("%I64d\n",g);
	}
}