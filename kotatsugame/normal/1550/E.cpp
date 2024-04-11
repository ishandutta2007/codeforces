#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int N,K;
string S;
bool check(int L)
{
	vector<queue<int> >id(K);
	{
		vector<int>cnt(K);
		int nz=0;
		int now=0;
		for(int i=0;i<N;i++)
		{
			if(i>=L)
			{
				if(S[i-L]!='?')nz-=!--cnt[S[i-L]-'a'];
			}
			if(S[i]!='?')nz+=!cnt[S[i]-'a']++;
			if(i>=L-1)
			{
				if(nz==0)for(int j=0;j<K;j++)id[j].push(i-L+1);
				else if(nz==1)
				{
					for(int j=0;j<K;j++)if(cnt[j]>0)
					{
						id[j].push(i-L+1);
						break;
					}
				}
			}
		}
	}
	vector<int>dist(1<<K,N+1);
	dist[0]=0;
	priority_queue<pair<int,int> >P;
	P.push(make_pair(0,0));
	while(!P.empty())
	{
		int u=P.top().second;
		int c=-P.top().first;
		P.pop();
		if(dist[u]<c)continue;
		for(int j=0;j<K;j++)if(!(u>>j&1))
		{
			while(!id[j].empty()&&id[j].front()<c)id[j].pop();
			if(!id[j].empty())
			{
				int np=id[j].front()+L;
				if(dist[u|1<<j]>np)
				{
					dist[u|1<<j]=np;
					P.push(make_pair(-np,u|1<<j));
				}
			}
		}
	}
	return dist[(1<<K)-1]<=N;
}
main()
{
	cin>>N>>K>>S;
	int L=0,R=N+1;
	while(R-L>1)
	{
		int mid=(L+R)/2;
		if(check(mid))L=mid;
		else R=mid;
	}
	cout<<L<<endl;
}