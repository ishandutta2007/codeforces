#include<iostream>
#include<vector>
using namespace std;
int N;
vector<pair<int,pair<int,int> > >G[2<<17];
long long A[2<<17],B[2<<17];
int pr[18][2<<17],depth[2<<17];
void dfs1(int u,int p,int d,long long as,long long bs)
{
	A[u]=as;B[u]=bs;
	pr[0][u]=p;
	depth[u]=d;
	for(pair<int,pair<int,int> >e:G[u])
	{
		dfs1(e.first,u,d+1,as+e.second.first,bs+e.second.second);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)G[i].clear();
		for(int i=1;i<N;i++)
		{
			int p,a,b;
			cin>>p>>a>>b;
			G[p-1].push_back(make_pair(i,make_pair(a,b)));
		}
		dfs1(0,-1,0,0LL,0LL);
		for(int k=1;k<18;k++)
		{
			for(int i=0;i<N;i++)
			{
				if(pr[k-1][i]==-1)pr[k][i]=-1;
				else pr[k][i]=pr[k-1][pr[k-1][i]];
			}
		}
		for(int u=1;u<N;u++)
		{
			int v=u;
			if(B[v]>A[u])
			{
				for(int k=18;k--;)if(pr[k][v]!=-1)
				{
					if(B[pr[k][v]]>A[u])v=pr[k][v];
				}
				v=pr[0][v];
			}
			cout<<depth[v]<<(u+1==N?"\n":" ");
		}
	}
}