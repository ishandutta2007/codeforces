#include<iostream>
#include<queue>
#include<map>
using namespace std;
pair<int,int>ex(long long N)
{
	int ret=0,len=0;
	while(N>0)
	{
		int t=N%10;
		if(t>1)ret|=1<<t-2;
		N/=10;
		len++;
	}
	return make_pair(len,ret);
}
int N;
long long X;
map<long long,int>dist;
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N>>X;
	queue<long long>Q;
	Q.push(X);
	dist[X]=0;
	while(!Q.empty())
	{
		long long u=Q.front();Q.pop();
		pair<int,int>now=ex(u);
		int d=dist[u];
		if(now.first==N)
		{
			cout<<d<<endl;
			return 0;
		}
		for(int t=0;t<8;t++)if(now.second>>t&1)
		{
			long long v=u*(t+2);
			if(dist.find(v)==dist.end())
			{
				dist[v]=d+1;
				Q.push(v);
			}
		}
	}
	cout<<"-1\n";
}