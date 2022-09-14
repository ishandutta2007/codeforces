#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N;
int A[500][500];
int C[1<<17],K;
vector<pair<int,int> >E;
int calc(vector<int>ids)
{
	int u=ids[0];
	C[u]=A[u][u];
	if(ids.size()==1)return u;
	vector<pair<int,int> >X;X.reserve(ids.size()-1);
	for(int i=1;i<ids.size();i++)
	{
		X.push_back(make_pair(A[u][ids[i]],ids[i]));
	}
	sort(X.begin(),X.end());
	for(int i=0;i<X.size();)
	{
		int j=i;
		vector<int>nxt;
		while(j<X.size()&&X[i].first==X[j].first)
		{
			nxt.push_back(X[j++].second);
		}
		int r=calc(nxt);
		if(C[r]==X[i].first)
		{
			E.push_back(make_pair(u,r));
			u=r;
		}
		else
		{
			E.push_back(make_pair(u,K));
			E.push_back(make_pair(r,K));
			u=K;
			C[K++]=X[i].first;
		}
		i=j;
	}
	return u;
}
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)for(int j=0;j<N;j++)scanf("%d",&A[i][j]);
	vector<int>fst(N);
	for(int i=0;i<N;i++)fst[i]=i;
	K=N;
	int r=calc(fst);
	printf("%d\n",K);
	for(int i=0;i<K;i++)printf("%d%c",C[i],i+1==K?10:32);
	printf("%d\n",r+1);
	for(pair<int,int>e:E)printf("%d %d\n",e.first+1,e.second+1);
}