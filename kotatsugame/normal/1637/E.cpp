#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int T,N,M;
vector<pair<int,pair<int,int> > >del[3<<17];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N>>M;
		map<int,int>cnt;
		for(int i=0;i<N;i++)
		{
			int A;cin>>A;
			cnt[A]++;
		}
		map<int,vector<int> >invcnt;
		for(auto it=cnt.rbegin();it!=cnt.rend();it++)
		{
			invcnt[it->second].push_back(it->first);
		}
		for(int i=1;i<=N;i++)del[i].clear();
		for(int i=0;i<M;i++)
		{
			int x,y;cin>>x>>y;
			int cx=cnt[x],cy=cnt[y];
			if(cx>cy||cx==cy&&x<y)swap(x,y),swap(cx,cy);
			del[cx].push_back(make_pair(cy,make_pair(-x,-y)));
		}
		long long ans=0;
		for(auto it=invcnt.begin();it!=invcnt.end();it++)
		{
			int cx=it->first;
			sort(del[cx].begin(),del[cx].end());
			int di=0;
			for(int i=0;i<it->second.size();i++)
			{
				int x=it->second[i];
				while(di<del[cx].size()&&del[cx][di].first==cx&&-del[cx][di].second.first>x)di++;
				int j=i+1;
				while(j<it->second.size()&&di<del[cx].size())
				{
					if(cx==del[cx][di].first
						&&x==-del[cx][di].second.first
						&&it->second[j]==-del[cx][di].second.second)j++,di++;
					else break;
				}
				if(j<it->second.size())ans=max(ans,(long long)(cx+cx)*(x+it->second[j]));
				if(j==i+1)break;
			}
			auto jt=it;
			jt++;
			for(;jt!=invcnt.end();jt++)
			{
				int cy=jt->first;
				while(di<del[cx].size()&&del[cx][di].first<cy)di++;
				for(int x:it->second)
				{
					while(di<del[cx].size()&&del[cx][di].first==cy&&-del[cx][di].second.first>x)di++;
					int id=0;
					while(id<jt->second.size()&&di<del[cx].size())
					{
						if(cy==del[cx][di].first
							&&x==-del[cx][di].second.first
							&&jt->second[id]==-del[cx][di].second.second)id++,di++;
						else break;
					}
					if(id<jt->second.size())ans=max(ans,(long long)(cx+cy)*(x+jt->second[id]));
					if(id==0)break;
				}
			}
		}
		cout<<ans<<"\n";
	}
}