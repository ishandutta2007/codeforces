#include<iostream>
#include<cstdio>
#include<set>
#include<vector>
using namespace std;
int n,k,ans,bo[444444],bif[444444];
vector<int> v[444444];
multiset<int> s;
multiset<pair<int,int> > ss;
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&bo[i]);
		v[bo[i]].push_back(i); 
	}
	for (int i=1;i<=n;i++)
	{
		v[i].push_back(1e9); 
	}
	for (int i=1;i<=n;i++)
	{
		if (s.find(bo[i])!=s.end())
		{
			ss.erase(ss.find(make_pair(v[bo[i]][bif[bo[i]]],bo[i])));
			ss.insert(make_pair(v[bo[i]][++bif[bo[i]]],bo[i]));
		}
		else
		{
			bif[bo[i]]++;
			if (s.size()<k)
			{
				ss.insert(make_pair(v[bo[i]][bif[bo[i]]],bo[i]));
				s.insert(bo[i]); 
				ans++;
			}
			else
			{
				set<pair<int,int> >::iterator p=ss.end();p--;
				s.erase(p->second);
				ss.erase(p);
				s.insert(bo[i]);
				ss.insert(make_pair(v[bo[i]][bif[bo[i]]],bo[i]));
				ans++;  
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}