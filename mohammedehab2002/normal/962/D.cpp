#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;
map<long long,set<long long> > m;
set<long long> s;
long long ans[150005];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		m[a].insert(i);
		if (m[a].size()==2)
		s.insert(a);
		ans[i]=a;
	}
	while (!s.empty())
	{
		long long cur=*s.begin();
		auto it=m[cur].begin();
		ans[*it]=0;
		ans[*next(it)]=cur*2;
		m[2*cur].insert(*next(it));
		m[cur].erase(next(it));
		m[cur].erase(it);
		if (m[cur].size()<2)
		s.erase(s.begin());
		if (m[2*cur].size()>1)
		s.insert(2*cur);
	}
	vector<long long> v;
	for (int i=0;i<n;i++)
	{
		if (ans[i])
		v.push_back(ans[i]);
	}
	printf("%d\n",v.size());
	for (long long i:v)
	printf("%I64d ",i);
}