#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
int N,M,Q;
long long ans[2<<17];
long long sum[4<<17];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N>>M>>Q;
	vector<pair<int,bool> >AB(N+M);
	for(int i=0;i<N+M;i++)
	{
		int a;cin>>a;
		AB[i]=make_pair(a,i<N);
	}
	sort(AB.begin(),AB.end());
	for(int i=0;i<N+M;i++)sum[i+1]=sum[i]+AB[i].first;
	vector<pair<int,int> >E;E.reserve(N+M-1);
	for(int i=0;i<N+M-1;i++)
	{
		E.push_back(make_pair(AB[i+1].first-AB[i].first,i));
	}
	sort(E.begin(),E.end());
	vector<pair<int,int> >qs(Q);
	for(int i=0;i<Q;i++)
	{
		int K;cin>>K;
		qs[i]=make_pair(K,i);
	}
	sort(qs.begin(),qs.end());
	set<pair<pair<int,int>,int> >S;
	long long now=0;
	for(int i=0;i<N+M;i++)
	{
		S.insert(make_pair(make_pair(i,i+1),AB[i].second?1:0));
		if(AB[i].second)now+=AB[i].first;
	}
	int ei=0;
	for(pair<int,int>p:qs)
	{
		int K=p.first;
		while(ei<E.size()&&E[ei].first<=K)
		{
			auto it=S.lower_bound(make_pair(make_pair(E[ei].second+1,0),0));
			int rc=it->second;
			int rl=it->first.first,rr=it->first.second;
			it--;
			int lc=it->second;
			int ll=it->first.first,lr=it->first.second;
			it=S.erase(it);
			it=S.erase(it);
			now-=sum[rr]-sum[rr-rc];
			now-=sum[lr]-sum[lr-lc];
			S.insert(it,make_pair(make_pair(ll,rr),lc+rc));
			now+=sum[rr]-sum[rr-(lc+rc)];
			ei++;
		}
		ans[p.second]=now;
	}
	for(int i=0;i<Q;i++)cout<<ans[i]<<"\n";
}