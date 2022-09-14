#include<cstdio>
#include<algorithm>
using namespace std;
int N;
long long K;
int V[34][1<<17],W[34][1<<17];
long long S[34][1<<17];
main()
{
	scanf("%d%lld",&N,&K);
	for(int i=0;i<N;i++)scanf("%d",&V[0][i]);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&W[0][i]);
		S[0][i]=W[0][i];
	}
	for(int k=1;k<34;k++)
	{
		for(int i=0;i<N;i++)
		{
			V[k][i]=V[k-1][V[k-1][i]];
			W[k][i]=min(W[k-1][i],W[k-1][V[k-1][i]]);
			S[k][i]=S[k-1][i]+S[k-1][V[k-1][i]];
		}
	}
	for(int i=0;i<N;i++)
	{
		long long s=0;
		int w=1e9;
		int u=i;
		for(int j=0;j<34;j++)if(K>>j&1)
		{
			w=min(w,W[j][u]);
			s+=S[j][u];
			u=V[j][u];
		}
		printf("%lld %d\n",s,w);
	}
}