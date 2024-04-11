#include <iostream>
#include <vector>
#include <set>
using namespace std;
multiset<pair<int,int> > s;
vector<pair<int,int> > v;
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	while (n--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		s.insert(make_pair(a,0));
		s.insert(make_pair(b,1));
	}
	int cnt=0;
	while (s.size())
	{
		pair<int,int> p=*(s.begin());
		s.erase(s.begin());
		if (p.second==0)
		{
			cnt++;
			if (cnt==k)
			v.push_back(p);
		}
		else
		{
			cnt--;
			if (cnt==k-1)
			v[v.size()-1].second=p.first;	
		}
	}
	printf("%d\n",v.size());
	for (int i=0;i<v.size();i++)
	printf("%d %d\n",v[i].first,v[i].second);
}