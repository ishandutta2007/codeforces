#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
map<long long,vector<int> >mp;
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
		if(op=='+'||op=='-')
		{
			long long x;cin>>x;
			mp[x].push_back(i);
		}
		else
		{
			long long k;cin>>k;
			qs.push_back(make_pair(k,i));
		}
	}
	sort(qs.begin(),qs.end());
	set<int>qi;
	for(int i=0;i<qs.size();)
	{
		long long k=qs[i].first;
		int j=i;
		while(j<qs.size()&&qs[j].first==k)
		{
			qi.insert(qs[j].second);
			j++;
		}
		i=j;
		for(long long t=k;!qi.empty();t+=k)
		{
			if(mp.find(t)==mp.end())
			{
				for(int id:qi)ans[id]=t;
				qi.clear();
			}
			else
			{
				int l=0;
				bool in=false;
				for(int r:mp[t])
				{
					if(!in)
					{
						auto it=qi.lower_bound(l);
						while(it!=qi.end()&&*it<r)
						{
							int id=*it;
							ans[id]=t;
							it=qi.erase(it);
						}
						if(it==qi.end())break;
					}
					in=!in;
					l=r;
				}
				if(!in)
				{
					auto it=qi.lower_bound(l);
					while(it!=qi.end())
					{
						int id=*it;
						ans[id]=t;
						it=qi.erase(it);
					}
				}
			}
		}
	}
	for(int i=0;i<Q;i++)if(ans[i]>0)cout<<ans[i]<<"\n";
}