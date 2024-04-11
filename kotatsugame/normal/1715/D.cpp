#include<iostream>
#include<vector>
using namespace std;
int N,Q;
vector<int>G[1<<17];
int col[1<<17];
int ans[1<<17];
int U[2<<17],V[2<<17],X[2<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N>>Q;
	for(int i=0;i<Q;i++)
	{
		cin>>U[i]>>V[i]>>X[i];
		if(U[i]>V[i])swap(U[i],V[i]);
		U[i]--,V[i]--;
	}
	for(int k=0;k<30;k++)
	{
		for(int i=0;i<N;i++)
		{
			G[i].clear();
			col[i]=0;
		}
		for(int i=0;i<Q;i++)
		{
			if(X[i]>>k&1)
			{
				if(U[i]==V[i])col[U[i]]=1;
				else G[U[i]].push_back(V[i]);
			}
			else
			{
				col[U[i]]=col[V[i]]=-1;
			}
		}
		for(int i=0;i<N;i++)
		{
			if(col[i]==0)
			{
				bool fn=false;
				for(int v:G[i])if(col[v]==-1)fn=true;
				if(fn)col[i]=1;
				else col[i]=-1;
			}
			if(col[i]==1)ans[i]|=1<<k;
			else if(col[i]==-1)
			{
				for(int v:G[i])col[v]=1;
			}
		}
	}
	for(int i=0;i<N;i++)cout<<ans[i]<<(i+1==N?"\n":" ");
}