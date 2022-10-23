#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int H,W,p,q;
string S[3<<17];
long long dist[3<<17];
vector<pair<int,int> >G[3<<17];
int conv(int x,int y){return x*W+y;}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>H>>W>>p>>q;
	for(int i=0;i<H;i++)cin>>S[i];
	for(int i=0;i<H*W;i++)dist[i]=1e18;
	priority_queue<pair<long long,int> >Q;
	for(int i=0;i<H;i++)for(int j=0;j<W;j++)
	{
		if(S[i][j]=='.')
		{
			dist[conv(i,j)]=0;
			Q.push(make_pair(0,conv(i,j)));
		}
		else if(S[i][j]=='L')
		{
			if(i-1>=0)G[conv(i-1,j)].push_back(make_pair(conv(i,j+1),p));
			if(j-1>=0)G[conv(i,j-1)].push_back(make_pair(conv(i,j+1),q));
			if(i+1<H)G[conv(i+1,j)].push_back(make_pair(conv(i,j+1),p));
		}
		else if(S[i][j]=='R')
		{
			if(i-1>=0)G[conv(i-1,j)].push_back(make_pair(conv(i,j-1),p));
			if(j+1<W)G[conv(i,j+1)].push_back(make_pair(conv(i,j-1),q));
			if(i+1<H)G[conv(i+1,j)].push_back(make_pair(conv(i,j-1),p));
		}
		else if(S[i][j]=='U')
		{
			if(j-1>=0)G[conv(i,j-1)].push_back(make_pair(conv(i+1,j),p));
			if(i-1>=0)G[conv(i-1,j)].push_back(make_pair(conv(i+1,j),q));
			if(j+1<W)G[conv(i,j+1)].push_back(make_pair(conv(i+1,j),p));
		}
		else if(S[i][j]=='D')
		{
			if(j-1>=0)G[conv(i,j-1)].push_back(make_pair(conv(i-1,j),p));
			if(i+1<H)G[conv(i+1,j)].push_back(make_pair(conv(i-1,j),q));
			if(j+1<W)G[conv(i,j+1)].push_back(make_pair(conv(i-1,j),p));
		}
	}
	while(!Q.empty())
	{
		long long c=-Q.top().first;
		int u=Q.top().second;
		Q.pop();
		if(dist[u]<c)continue;
		for(pair<int,int>e:G[u])if(dist[e.first]>c+e.second)
		{
			dist[e.first]=c+e.second;
			Q.push(make_pair(-dist[e.first],e.first));
		}
	}
	long long ans=1e18;
	for(int i=0;i<H;i++)for(int j=0;j<W;j++)
	{
		if(i+1<H)ans=min(ans,dist[conv(i,j)]+dist[conv(i+1,j)]);
		if(j+1<W)ans=min(ans,dist[conv(i,j)]+dist[conv(i,j+1)]);
	}
	if(ans==(long long)1e18)ans=-1;
	cout<<ans<<endl;
}