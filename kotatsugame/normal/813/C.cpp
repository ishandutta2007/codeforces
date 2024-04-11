#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N,x;
vector<int>G[2<<17];
vector<int>f(int s)
{
	vector<int>d(N,1e9);
	d[s]=0;
	queue<int>P;
	P.push(s);
	while(!P.empty())
	{
		int u=P.front();P.pop();
		for(int v:G[u])if(d[v]>d[u]+1)
		{
			d[v]=d[u]+1;
			P.push(v);
		}
	}
	return d;
}
main()
{
	cin>>N>>x;x--;
	for(int i=1;i<N;i++)
	{
		int a,b;cin>>a>>b;
		a--,b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	vector<int>A=f(0),B=f(x);
	int ans=0;
	for(int i=0;i<N;i++)
	{
		if(A[i]>B[i]&&ans<A[i])ans=A[i];
	}
	cout<<ans*2<<endl;
}