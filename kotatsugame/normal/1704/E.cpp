#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int mod=998244353;
int A[1000];
vector<int>G[1000];
int deg[1000];
vector<pair<long long,long long> >LR[1000];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		int N,M;
		cin>>N>>M;
		for(int i=0;i<N;i++)
		{
			G[i].clear();
			deg[i]=0;
			cin>>A[i];
			LR[i].clear();
			if(A[i]>0)LR[i].push_back(make_pair(0,A[i]));
		}
		for(int i=0;i<M;i++)
		{
			int u,v;cin>>u>>v;
			u--,v--;
			G[u].push_back(v);
			deg[v]++;
		}
		vector<int>ord;
		ord.reserve(N);
		{
			queue<int>Q;
			for(int i=0;i<N;i++)if(deg[i]==0)Q.push(i);
			while(!Q.empty())
			{
				int u=Q.front();
				Q.pop();
				ord.push_back(u);
				for(int v:G[u])if(!--deg[v])Q.push(v);
			}
		}
		long long ans=0;
		vector<pair<long long,long long> >tmp;
		for(int u:ord)
		{
			tmp.clear();
			sort(LR[u].begin(),LR[u].end());
			for(pair<long long,long long>p:LR[u])
			{
				if(!tmp.empty()&&tmp.back().second>=p.first)
				{
					tmp.back().second+=p.second-p.first;
				}
				else
				{
					tmp.push_back(p);
				}
			}
			if(G[u].empty())
			{
				if(!tmp.empty())ans=max(ans,tmp.back().second);
			}
			else
			{
				for(pair<long long,long long>p:tmp)
				{
					p.first++;
					p.second++;
					if(p.second>=mod)p.second=(p.second-mod)%mod+mod;
					for(int v:G[u])LR[v].push_back(p);
				}
			}
		}
		cout<<ans%mod<<"\n";
	}
}