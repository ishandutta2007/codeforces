#include <iostream>
#include <vector>
#include <set>
using namespace std;
vector<int> path;
int n,par[100005],dep[100005],cnt[100005];
struct cmp
{
	bool operator()(const int &a,const int &b) const
	{
		if (dep[a]==dep[b])
		return (a<b);
		return (dep[a]>dep[b]);
	}
};
set<int,cmp> l;
long long go(int m)
{
	long long sum=1;
	dep[1]=1;
	path.clear();
	path.push_back(1);
	for (int i=2;i<=n;i++)
	{
		par[i]=(i-2)/m+1;
		dep[i]=dep[par[i]]+1;
		sum+=dep[i];
		if (par[i]==path.back())
		path.push_back(i);
	}
	return sum;
}
int main()
{
	long long s;
	scanf("%d%I64d",&n,&s);
	if (go(1)<s || go(n-1)>s)
	{
		printf("No");
		return 0;
	}
	int st=1,en=n-1;
	while (st!=en)
	{
		int mid=(st+en)/2;
		if (go(mid)<=s)
		en=mid;
		else
		st=mid+1;
	}
	long long sum=go(st);
	if (sum!=s)
	{
		for (int i=n;i>=2;i--)
		{
			cnt[par[i]]++;
			if (!cnt[i] && i!=path.back())
			l.insert(i);
		}
		while (1)
		{
			int node=*l.begin();
			l.erase(l.begin());
			if (sum+path.size()+1-dep[node]<s)
			{
				cnt[par[node]]--;
				if (!cnt[par[node]])
				l.insert(par[node]);
				par[node]=path.back();
				path.push_back(node);
				sum+=path.size()-dep[node];
			}
			else
			{
				par[node]=path[dep[node]+s-sum-2];
				break;
			}
		}
	}
	printf("Yes\n");
	for (int i=2;i<=n;i++)
	printf("%d ",par[i]);
}