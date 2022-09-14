#include<iostream>
#include<vector>
using namespace std;
int T,N;
int ans[1<<17];
vector<pair<int,int> >G[1<<17];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)G[i].clear(),ans[i]=0;
		bool out=false;
		for(int i=1;i<N;i++)
		{
			int u,v;cin>>u>>v;u--,v--;
			G[u].push_back(make_pair(v,i));
			G[v].push_back(make_pair(u,i));
			if(G[u].size()>2||G[v].size()>2)out=true;
		}
		if(out)cout<<"-1\n";
		else
		{
			int u=0;
			while(G[u].size()==2)u++;
			int tm=2;
			while(u!=-1)
			{
				int v=-1;
				for(pair<int,int>e:G[u])if(ans[e.second]==0)
				{
					ans[e.second]=tm;
					v=e.first;
					break;
				}
				u=v;
				tm=5-tm;
			}
			for(int i=1;i<N;i++)cout<<ans[i]<<(i+1==N?"\n":" ");
		}
	}
}