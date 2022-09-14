#include<iostream>
#include<vector>
using namespace std;
int T,N;
int P[201],inv[201];
bool vis[201];
int to[201];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=1;i<=N;i++)
		{
			cin>>P[i];
			inv[P[i]]=i;
			vis[i]=false;
		}
		for(int i=1;i<=N;i++)if(!vis[i])
		{
			vector<int>v;
			int u=i;
			while(!vis[u])
			{
				v.push_back(u);
				vis[u]=true;
				int w=inv[u];
				to[u]=w;
				u=w;
			}
			if(i>1)
			{
				int x=i-1,y=to[i-1];
				to[x]=inv[i];
				to[i]=y;
			}
		}
		int u=1;
		for(int i=0;i<N;i++)
		{
			cout<<u<<(i+1==N?"\n":" ");
			u=to[u];
		}
	}
}