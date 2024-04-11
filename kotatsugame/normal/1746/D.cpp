#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
int N;
vector<int>G[2<<17];
map<int,long long>mp[2<<17];
int S[2<<17];
long long dfs(int u,int K)
{
	if(G[u].empty())return(long long)S[u]*K;
	if(mp[u].find(K)!=mp[u].end())return mp[u][K];
	int c=G[u].size();
	vector<long long>diff(c);
	long long ans=(long long)S[u]*K;
	for(int i=0;i<G[u].size();i++)
	{
		long long x=dfs(G[u][i],K/c);
		long long y=dfs(G[u][i],(K+c-1)/c);
		ans+=x;
		diff[i]=y-x;
	}
	sort(diff.begin(),diff.end());
	int r=K%c;
	for(int i=0;i<r;i++)ans+=diff[c-i-1];
	return mp[u][K]=ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		int K;
		cin>>N>>K;
		for(int i=0;i<N;i++)
		{
			G[i].clear();
			mp[i].clear();
		}
		for(int i=1;i<N;i++)
		{
			int p;cin>>p;
			G[p-1].push_back(i);
		}
		for(int i=0;i<N;i++)cin>>S[i];
		cout<<dfs(0,K)<<"\n";
	}
}