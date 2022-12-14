#include<iostream>
#include<vector>
#include<set>
using namespace std;
long long n,m,k,x,y,z,ans;
vector<pair<long long,long long> > g[111111];
set<long long> s;
int main()
{
	ans=1e18;
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++)
	{
		cin>>x>>y>>z;
		g[x].push_back(make_pair(y,z));
		g[y].push_back(make_pair(x,z));  
	}
	for (int i=1;i<=k;i++)
	{
		cin>>x;
		s.insert(x);
	}
	for (set<long long>::iterator it=s.begin();it!=s.end();it++)
	{
		long long i=*it;
		for (int j=0;j<g[i].size();j++)
		{
			if (s.find(g[i][j].first)==s.end()) ans=min(ans,g[i][j].second);
		}
	}
	if (ans==1e18) cout<<-1<<endl;
	else cout<<ans<<endl;
	return 0;
}