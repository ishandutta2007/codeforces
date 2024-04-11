#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
int M;
vector<int>A[1<<17];
vector<int>ans[1<<17];
set<pair<int,pair<int,int> > >G[1<<17];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>M;
	int SN=0;
	for(int i=0;i<M;i++)
	{
		int N;cin>>N;
		SN+=N;
		A[i].assign(N,0);
		ans[i].assign(N,0);
		for(int j=0;j<N;j++)
		{
			cin>>A[i][j];
		}
	}
	vector<pair<int,pair<int,int> > >vals;
	vals.reserve(SN);
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<A[i].size();j++)vals.push_back(make_pair(A[i][j],make_pair(i,j)));
	}
	sort(vals.begin(),vals.end());
	for(int i=0;i<vals.size();)
	{
		int j=i;
		while(j<vals.size()&&vals[i].first==vals[j].first)j++;
		while(i+2<=j)
		{
			int u=vals[i].second.first,v=vals[i+1].second.first;
			int ui=vals[i].second.second,vi=vals[i+1].second.second;
			G[u].insert(make_pair(v,make_pair(ui,vi)));
			G[v].insert(make_pair(u,make_pair(vi,ui)));
			i+=2;
		}
		if(i<j)
		{
			cout<<"NO\n";
			return 0;
		}
	}
	for(int i=0;i<M;i++)while(!G[i].empty())
	{
		int u=i;
		while(!G[u].empty())
		{
			pair<int,pair<int,int> >e=*G[u].begin();
			int v=e.first;
			int ui=e.second.first,vi=e.second.second;
			G[u].erase(G[u].begin());
			G[v].erase(make_pair(u,make_pair(vi,ui)));
			ans[u][ui]=1;
			ans[v][vi]=2;
			u=v;
		}
	}
	cout<<"YES\n";
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<ans[i].size();j++)
		{
			cout<<(ans[i][j]==1?'L':'R');
		}
		cout<<"\n";
	}
}