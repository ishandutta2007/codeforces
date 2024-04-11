#include<cstdio>
#include<map>
using namespace std;
int N,Q;
int A[2<<17];
long long S;
map<pair<int,int>,int>M;
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&A[i]);
		S+=A[i];
	}
	scanf("%d",&Q);
	for(;Q--;)
	{
		int s,t,u;scanf("%d%d%d",&s,&t,&u);
		s--;
		map<pair<int,int>,int>::iterator it=M.find(make_pair(s,t));
		if(it!=M.end())
		{
			int v=it->second;
			A[v]++;
			if(A[v]>0)S++;
			M.erase(it);
		}
		if(u>0)
		{
			u--;
			if(A[u]>0)S--;
			A[u]--;
			M[make_pair(s,t)]=u;
		}
		printf("%lld\n",S);
	}
}