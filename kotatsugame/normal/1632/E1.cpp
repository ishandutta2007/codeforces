#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int T,N;
vector<int>G[3000];
vector<int>dist(int st)
{
	vector<int>ret(N,1e9);
	ret[st]=0;
	queue<int>P;P.push(st);
	while(!P.empty())
	{
		int u=P.front();P.pop();
		for(int v:G[u])if(ret[v]>ret[u]+1)
		{
			ret[v]=ret[u]+1;
			P.push(v);
		}
	}
	return ret;
}
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)G[i].clear();
		for(int i=1;i<N;i++)
		{
			int u,v;cin>>u>>v;u--,v--;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		vector<pair<int,int> >rt(N);
		{
			vector<int>d=dist(0);
			for(int i=0;i<N;i++)rt[i]=make_pair(d[i],i);
		}
		sort(rt.begin(),rt.end());
		vector<int>ans(N+1,1e9);
		int l=-1,r=-1,dirm=-1;
		vector<int>ld,rd;
		for(int d=N;d>=1;d--)
		{
			while(!rt.empty()&&rt.back().first>d)
			{
				int u=rt.back().second;
				rt.pop_back();
				if(dirm<0)
				{
					dirm=0;
					l=r=u;
					ld=rd=dist(u);
				}
				else
				{
					if(ld[r]<ld[u])
					{
						dirm=ld[u];
						r=u;
						rd=dist(u);
					}
					else if(rd[l]<rd[u])
					{
						dirm=rd[u];
						ld=dist(u);
					}
				}
			}
			if(dirm<0)ans[N]=d;
			else
			{
				int need=d-(dirm+1)/2;
				if(need>0)ans[need]=d;
			}
		}
		for(int i=N;--i;)ans[i]=min(ans[i],ans[i+1]);
		for(int i=1;i<=N;i++)cout<<ans[i]<<(i==N?"\n":" ");
	}
}