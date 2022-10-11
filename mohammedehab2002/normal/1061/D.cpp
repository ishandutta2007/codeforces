#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
#define mod 1000000007
int main()
{
	int n;
	long long x,y;
	scanf("%d%I64d%I64d",&n,&x,&y);
	vector<pair<int,int> > e;
	for (int i=0;i<n;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		e.push_back({l,-r});
		e.push_back({r,0});
	}
	sort(e.begin(),e.end());
	multiset<int,greater<int> > m;
	long long ans=0;
	for (auto p:e)
	{
		if (!p.second)
		m.insert(p.first);
		else
		{
			long long cur=x;
			if (!m.empty())
			{
				if ((p.first-*m.begin())*y<cur)
				{
					cur=(p.first-*m.begin())*y;
					m.erase(m.begin());
				}
			}
			ans=(ans+cur-(p.first+p.second)*y)%mod;
		}
	}
	printf("%I64d",ans);
}