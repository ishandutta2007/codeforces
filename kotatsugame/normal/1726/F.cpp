#include<iostream>
#include<vector>
#include<map>
using namespace std;
int N,T;
int G[2<<17],C[2<<17],D[2<<17];
map<int,pair<int,long long> >now;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N>>T;
	for(int i=0;i<N;i++)cin>>G[i]>>C[i];
	for(int i=0;i<N-1;i++)cin>>D[i];
	{
		int df=0;
		for(int i=1;i<N;i++)
		{
			df=(df+D[i-1])%T;
			C[i]=(C[i]+df)%T;
		}
	}
	now[0]=make_pair(T,0);
	vector<pair<int,int> >wdw;
	for(int i=0;i<N;i++)
	{
		wdw.clear();
		int st=(T-C[i])%T;
		if(G[i]<C[i])
		{
			wdw.push_back(make_pair(0,T-C[i]));
			wdw.push_back(make_pair(T-C[i]+G[i],T));
		}
		else wdw.push_back(make_pair(G[i]-C[i],T-C[i]));
		long long stneed;
		{
			auto it=now.upper_bound(st);
			if(it==now.begin())
			{
				it=now.end();
				it--;
				int l=it->first,r=it->second.first;
				long long w=it->second.second;
				w+=st+T-r+1;
				stneed=w;
			}
			else
			{
				it--;
				int l=it->first,r=it->second.first;
				long long w=it->second.second;
				if(r<=st)w+=st-r+1;
				stneed=w;
			}
		}
		for(pair<int,int>p:wdw)
		{
			int l=p.first,r=p.second;
			auto it=now.upper_bound(l);
			if(it!=now.begin())it--;
			while(it!=now.end())
			{
				int nl=it->first,nr=it->second.first;
				if(r<=nl)break;
				if(nr<=l)
				{
					it++;
					continue;
				}
				long long w=it->second.second;
				it=now.erase(it);
				if(nl<l)
				{
					it=now.insert(it,make_pair(nl,make_pair(l,w)));
					it++;
				}
				if(r<nr)
				{
					it=now.insert(it,make_pair(r,make_pair(nr,w)));
					it++;
				}
			}
			//cout<<"["<<l<<", "<<r<<"), ";
		}
		//cout<<endl;
		if(now.empty())now[st]=make_pair(st+1,stneed);
		else
		{
			auto it=now.upper_bound(st);
			if(it==now.begin())
			{
				now[st]=make_pair(st+1,stneed);
			}
			else
			{
				it--;
				if(it->second.first<=st)
				{
					it++;
					now.insert(it,make_pair(st,make_pair(st+1,stneed)));
				}
				else if(it->second.second>stneed)
				{
					int l=it->first,r=it->second.first;
					long long w=it->second.second;
					it=now.erase(it);
					if(l<st)
					{
						it=now.insert(it,make_pair(l,make_pair(st,w)));
						it++;
					}
					it=now.insert(it,make_pair(st,make_pair(st+1,stneed)));
					it++;
					if(st<r)
					{
						it=now.insert(it,make_pair(st,make_pair(r,w)));
						it++;
					}
				}
			}
		}
		//for(pair<int,pair<int,long long> >p:now)cout<<"["<<p.first<<", "<<p.second.first<<") = "<<p.second.second<<endl;cout<<endl;
	}
	long long ans=9e18;
	for(pair<int,pair<int,long long> >p:now)ans=min(ans,p.second.second);
	for(int i=0;i<N-1;i++)ans+=D[i];
	cout<<ans<<"\n";
}