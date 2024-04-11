#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N;
int A[3<<17];
vector<unsigned int>x[30];
vector<int>val[30];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)cin>>A[i];
		for(int k=0;k<30;k++)x[k].clear(),x[k].reserve(N);
		for(int i=0;i<N;i++)
		{
			unsigned int up=0;
			for(int k=30;k--;)
			{
				unsigned int now=up;
				now|=(i>>k&1)<<1;
				now|=(A[i]>>k&1)<<0;
				x[k].push_back(now);
				if((A[i]>>k&1)!=(i>>k&1))up|=1u<<k+2;
			}
		}
		for(int k=0;k<30;k++)
		{
			sort(x[k].begin(),x[k].end());
			x[k].erase(unique(x[k].begin(),x[k].end()),x[k].end());
			val[k].assign(x[k].size(),0);
		}
		int ans=0;
		for(int i=0;i<N;i++)
		{
			int mx=0;
			unsigned int up=0;
			for(int k=30;k--;)
			{
				unsigned int now=up;
				now|=(i>>k&1)<<1;
				now|=(A[i]>>k&1)<<0;
				int id=lower_bound(x[k].begin(),x[k].end(),now)-x[k].begin();
				mx=max(mx,val[k][id]);
				if((A[i]>>k&1)!=(i>>k&1))up|=1u<<k+2;
			}
			mx++;
			ans=max(ans,mx);
			up=0;
			for(int k=30;k--;)
			{
				unsigned int now=up;
				now|=(A[i]>>k&1)<<1;
				now|=((i>>k&1)^1)<<0;
				int id=lower_bound(x[k].begin(),x[k].end(),now)-x[k].begin();
				if(id<x[k].size()&&x[k][id]==now)val[k][id]=max(val[k][id],mx);
				if((A[i]>>k&1)!=(i>>k&1))up|=1u<<k+2;
			}
		}
		cout<<ans<<"\n";
	}
}