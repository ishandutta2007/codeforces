#include<cstdio>
#include<vector>
using namespace std;
int N,S;
int deg[1<<17];
main()
{
	scanf("%d%d",&N,&S);
	if(N==2)
	{
		printf("%d\n",S);
		return 0;
	}
	vector<pair<int,int> >E(N-1);
	for(int i=0;i<N-1;i++)
	{
		int u,v;scanf("%d%d",&u,&v);
		u--,v--;
		E[i]=make_pair(u,v);
		deg[u]++;
		deg[v]++;
	}
	int cnt=0;
	for(pair<int,int>e:E)
	{
		if(deg[e.first]==1||deg[e.second]==1)cnt++;
	}
	printf("%.16f\n",S*2.0/cnt);
}