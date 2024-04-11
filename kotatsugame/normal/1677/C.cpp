#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int T,N,A[1<<17];
vector<int>G[1<<17];
bool vis[1<<17];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)G[i].clear(),vis[i]=false;
		for(int i=0;i<N;i++)cin>>A[i];
		for(int i=0;i<N;i++)
		{
			int B;cin>>B;
			G[A[i]-1].push_back(B-1);
			G[B-1].push_back(A[i]-1);
		}
		int n=0,m=0,p=0;
		for(int i=0;i<N;i++)if(!vis[i])
		{
			int u=i;
			int cnt=0;
			while(true)
			{
				vis[u]=true;
				int v=-1;
				cnt++;
				for(int w:G[u])if(!vis[w])
				{
					v=w;
					break;
				}
				if(v==-1)break;
				u=v;
			}
			n+=cnt/2;
			p+=cnt/2;
			m+=cnt%2;
		}
		long long ans=0;
		for(int i=0;i<N;i++)
		{
			if(n>0)
			{
				n--;
				ans-=i*2;
			}
			else if(m>0)m--;
			else
			{
				p--;
				ans+=i*2;
			}
		}
		cout<<ans<<"\n";
	}
}