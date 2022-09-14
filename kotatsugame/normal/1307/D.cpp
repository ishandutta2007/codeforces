#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int N,M,K;
int A[2<<17];
vector<int>G[2<<17];
int d[2<<17],dr[2<<17];
int L[2<<17],R[2<<17];
bool invA[2<<17];
main()
{
	scanf("%d%d%d",&N,&M,&K);
	for(int i=0;i<K;i++)
	{
		scanf("%d",&A[i]);
		A[i]--;
		invA[A[i]]=true;
	}
	bool flag=false;
	for(int i=0;i<M;i++)
	{
		int u,v;scanf("%d%d",&u,&v);u--,v--;
		G[u].push_back(v);
		G[v].push_back(u);
		if(invA[u]&&invA[v])flag=true;
	}
	for(int i=0;i<N;i++)d[i]=dr[i]=1e9;
	d[0]=0;
	{
		queue<int>P;
		P.push(0);
		while(!P.empty())
		{
			int u=P.front();P.pop();
			for(int v:G[u])
			{
				if(d[v]>d[u]+1)
				{
					d[v]=d[u]+1;
					P.push(v);
				}
			}
		}
	}
	dr[N-1]=0;
	{
		queue<int>P;
		P.push(N-1);
		while(!P.empty())
		{
			int u=P.front();P.pop();
			for(int v:G[u])
			{
				if(dr[v]>dr[u]+1)
				{
					dr[v]=dr[u]+1;
					P.push(v);
				}
			}
		}
	}
	if(flag)
	{
		printf("%d\n",d[N-1]);
		return 0;
	}
	vector<pair<int,int> >id(K);
	for(int i=0;i<K;i++)id[i]=make_pair(d[A[i]],A[i]);
	sort(id.begin(),id.end());
	int ans=0;
	int pre=-1;
	for(int i=0;i<K;i++)
	{
		if(pre>=0)
		{
			int D=pre+1+dr[id[i].second];
			ans=max(ans,min(D,d[N-1]));
		}
		pre=id[i].first;
	}
	printf("%d\n",ans);
}