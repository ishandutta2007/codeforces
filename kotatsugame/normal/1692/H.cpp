#include<iostream>
#include<vector>
#include<map>
using namespace std;
int T,N;
map<int,vector<int> >idx;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		idx.clear();
		for(int i=0;i<N;i++)
		{
			int x;cin>>x;
			idx[x].push_back(i);
		}
		int ans=0;
		int al,ar,aa;
		for(auto it=idx.begin();it!=idx.end();it++)
		{
			vector<int>now;
			now.swap(it->second);
			//now[i]<->now[j]
			//(j-i+1)*2-(now[j]-now[i]+1)
			//(2j-now[j])-(2i-now[i])+1
			int mn=1e9,mni;
			for(int i=0;i<now.size();i++)
			{
				int t=2*i-now[i];
				if(mn>t)
				{
					mn=t;
					mni=now[i];
				}
				if(t+1-mn>ans)
				{
					ans=t+1-mn;
					al=mni;
					ar=now[i];
					aa=it->first;
				}
			}
		}
		cout<<aa<<" "<<al+1<<" "<<ar+1<<"\n";
	}
}