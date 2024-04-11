#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
map<long long,int>mp;
long long ans[2<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int Q;cin>>Q;
	vector<pair<long long,int> >qs;
	for(int i=0;i<Q;i++)
	{
		char op;cin>>op;
		if(op=='+')
		{
			long long x;cin>>x;
			mp[x]=i;
		}
		else
		{
			long long k;cin>>k;
			qs.push_back(make_pair(k,i));
		}
	}
	sort(qs.begin(),qs.end());
	for(int i=0;i<qs.size();)
	{
		long long k=qs[i].first;
		for(long long t=k;i<qs.size()&&qs[i].first==k;t+=k)
		{
			if(mp.find(t)==mp.end())
			{
				while(i<qs.size()&&qs[i].first==k)
				{
					ans[qs[i].second]=t;
					i++;
				}
			}
			else
			{
				int mx=mp[t];
				while(i<qs.size()&&qs[i].first==k&&qs[i].second<mx)
				{
					ans[qs[i].second]=t;
					i++;
				}
			}
		}
	}
	for(int i=0;i<Q;i++)if(ans[i]>0)cout<<ans[i]<<"\n";
}