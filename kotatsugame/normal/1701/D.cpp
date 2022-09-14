#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int T,N;
int ans[5<<17];
vector<pair<int,int> >G[5<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=1;i<=N;i++)G[i].clear();
		for(int i=1;i<=N;i++)
		{
			int B;cin>>B;
			int l=i/(B+1)+1;
			int r=B==0?N:i/B;
			G[l].push_back(make_pair(-r,i));
		}
		priority_queue<pair<int,int> >Q;
		for(int i=1;i<=N;i++)
		{
			for(pair<int,int>p:G[i])
			{
				Q.push(p);
			}
			pair<int,int>now=Q.top();Q.pop();
			ans[now.second-1]=i;
		}
		for(int i=0;i<N;i++)cout<<ans[i]<<" \n"[i+1==N];
	}
}