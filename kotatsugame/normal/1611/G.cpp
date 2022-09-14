#include<iostream>
#include<vector>
using namespace std;
int T,N,M;
vector<string>S;
vector<pair<int,int> >now,nxt;
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N>>M;
		S.resize(N);
		for(int i=0;i<N;i++)cin>>S[i];
		int ans=0;
		for(int z=0;z<2;z++)
		{
			now.clear();
			for(int t=z;;t+=2)
			{
				for(pair<int,int>&p:now)p.first+=2;
				nxt.clear();
				int id=0;
				int L=max(0,t-M+1);
				int R=min(t,N-1);
				if(L>R)break;
				for(int i=L;i<=R;i++)
				{
					int j=t-i;
					if(S[i][j]=='1')
					{
						if(id<now.size()&&now[id].second<=i-j)
						{
							while(id+1<now.size()&&now[id+1].second<=i-j)nxt.push_back(now[id++]);
							id++;
							nxt.push_back(make_pair(i+j,i-j));
						}
						else if(!nxt.empty())nxt.back().second=i-j;
						else
						{
							ans++;
							nxt.push_back(make_pair(i+j,i-j));
						}
					}
				}
				while(id<now.size())
				{
					pair<int,int>p=now[id++];
					if((p.first+p.second)/2<N)nxt.push_back(p);
				}
				now.swap(nxt);
			}
		}
		cout<<ans<<"\n";
	}
}