#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int T,N,M,K;
struct lad{
	int to,i,j,h;
	bool operator<(const lad&rhs)const{return i<rhs.i;}
};
vector<lad>E[1<<17];
vector<pair<int,long long> >dp[1<<17],tmp;
long long X[1<<17];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N>>M>>K;
		for(int i=0;i<N;i++)
		{
			int x;cin>>x;
			X[i]=x;
			E[i].clear();
			dp[i].clear();
		}
		for(int i=0;i<K;i++)
		{
			int a,b,c,d,h;cin>>a>>b>>c>>d>>h;
			a--,c--;
			E[a].push_back(lad{c,b,d,h});
		}
		dp[0].push_back(make_pair(1,0));
		for(int i=0;i<N;i++)
		{
			sort(dp[i].begin(),dp[i].end());
			tmp.clear();
			for(pair<int,long long>p:dp[i])
			{
				while(!tmp.empty()&&tmp.back().second>=p.second+(p.first-tmp.back().first)*X[i])
					tmp.pop_back();
				if(tmp.empty()||tmp.back().second+(p.first-tmp.back().first)*X[i]>p.second)
					tmp.push_back(p);
			}
			dp[i]=tmp;
			sort(E[i].begin(),E[i].end());
			int id=0;
			for(lad L:E[i])
			{
				while(id<tmp.size()&&tmp[id].first<=L.i)id++;
				long long ret=1e18;
				if(id>0)
				{
					ret=min(ret,tmp[id-1].second+(L.i-tmp[id-1].first)*X[i]);
				}
				if(id<tmp.size())
				{
					ret=min(ret,tmp[id].second+(tmp[id].first-L.i)*X[i]);
				}
				if(ret<(long long)1e18)
				{
					dp[L.to].push_back(make_pair(L.j,ret-L.h));
				}
			}
		}
		if(dp[N-1].empty())cout<<"NO ESCAPE\n";
		else
		{
			pair<int,long long>p=dp[N-1].back();
			cout<<p.second+(M-p.first)*X[N-1]<<"\n";
		}
	}
}