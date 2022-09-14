#include<iostream>
#include<vector>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		int N;
		cin>>N;
		vector<pair<vector<int>,vector<int> > >now,nxt;
		{
			vector<int>A(N),B(N);
			for(int i=0;i<N;i++)cin>>A[i];
			for(int i=0;i<N;i++)cin>>B[i];
			now.push_back(make_pair(A,B));
		}
		int ans=0;
		for(int k=30;k--;)
		{
			bool ok=true;
			for(int i=0;i<now.size();i++)
			{
				int a0=0,a1=0,b0=0,b1=0;
				for(int a:now[i].first)
				{
					if(a>>k&1)a1++;
					else a0++;
				}
				for(int b:now[i].second)
				{
					if(b>>k&1)b1++;
					else b0++;
				}
				if(a0==b1&&a1==b0);
				else
				{
					ok=false;
					break;
				}
			}
			if(!ok)continue;
			ans|=1<<k;
			nxt.clear();
			for(int i=0;i<now.size();i++)
			{
				vector<int>a0,a1,b0,b1;
				for(int a:now[i].first)
				{
					if(a>>k&1)a1.push_back(a);
					else a0.push_back(a);
				}
				for(int b:now[i].second)
				{
					if(b>>k&1)b1.push_back(b);
					else b0.push_back(b);
				}
				if(!a0.empty())
				{
					nxt.emplace_back();
					nxt.back().first.swap(a0);
					nxt.back().second.swap(b1);
				}
				if(!a1.empty())
				{
					nxt.emplace_back();
					nxt.back().first.swap(a1);
					nxt.back().second.swap(b0);
				}
			}
			now.swap(nxt);
		}
		cout<<ans<<"\n";
	}
}