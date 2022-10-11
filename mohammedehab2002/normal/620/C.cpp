#include <iostream>
#include <vector>
#include <set>
using namespace std;
set<int> s;
vector<pair<int,int> > v;
int main()
{
	int n;
	scanf("%d",&n);
	v.push_back(make_pair(0,0));
	for (int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		if (s.find(a)!=s.end())
		v.push_back(make_pair(v.back().second+1,i+1)),s.clear();
		else
		s.insert(a);
	}
	v[v.size()-1].second=n;
	if (v.size()==1)
	{
		printf("-1");
		return 0;
	}
	printf("%d\n",v.size()-1);
	for (int i=1;i<v.size();i++)
	printf("%d %d\n",v[i].first,v[i].second);
}