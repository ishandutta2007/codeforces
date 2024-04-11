#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int T,N;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	vector<pair<int,int> >now,nxt;
	for(;T--;)
	{
		cin>>N;
		now.resize(N);
		for(int i=0;i<N;i++)
		{
			cin>>now[i].first;
			now[i].second=1;
		}
		for(int _=1;_<N;_++)
		{
			nxt.clear();
			int zc=0;
			for(int i=0;i<now.size();i++)
			{
				int c=now[i].second;
				zc+=c-1;
				if(i+1<now.size())
				{
					int t=now[i+1].first-now[i].first;
					if(t==0)zc++;
					else nxt.push_back(make_pair(t,1));
				}
			}
			sort(nxt.begin(),nxt.end());
			now.clear();
			if(zc>0)now.push_back(make_pair(0,zc));
			for(pair<int,int>p:nxt)
			{
				if(now.back().first==p.first)now.back().second+=p.second;
				else now.push_back(p);
			}
		}
		cout<<now[0].first<<"\n";
	}
}