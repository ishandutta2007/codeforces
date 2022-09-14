#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int N,M,Q;
int P[2<<17],invP[2<<17];
int A[2<<17];
vector<int>G[2<<17];
int nxt[18][2<<17];
int R[2<<17];
main()
{
	scanf("%d%d%d",&N,&M,&Q);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&P[i]);
		P[i]--;
		invP[P[i]]=i;
	}
	for(int i=0;i<M;i++)
	{
		scanf("%d",&A[i]);
		A[i]--;
		G[A[i]].push_back(i);
	}
	for(int i=0;i<=M;i++)nxt[0][i]=i+1;
	for(int k=1;k<18;k++)
	{
		for(int i=0;i<=M;i++)
		{
			int p=P[(invP[A[i]]+(1<<k-1))%N];
			auto it=lower_bound(G[p].begin(),G[p].end(),nxt[k-1][i]);
			if(it==G[p].end())nxt[k][i]=M+1;
			else nxt[k][i]=nxt[k-1][*it];
		}
	}
	R[M]=M+1;
	for(int i=M;i--;)
	{
		R[i]=R[i+1];
		int L=i;
		int id=invP[A[i]];
		for(int k=0;k<18;k++)if(N>>k&1)
		{
			int p=P[id];
			auto it=lower_bound(G[p].begin(),G[p].end(),L);
			if(it==G[p].end())L=M+1;
			else L=nxt[k][*it];
			id=(id+(1<<k))%N;
			if(L>M)break;
		}
		if(R[i]>L)R[i]=L;
	}
	for(;Q--;)
	{
		int l,r;scanf("%d%d",&l,&r);l--;
		printf(R[l]<=r?"1":"0");
	}
	puts("");
}