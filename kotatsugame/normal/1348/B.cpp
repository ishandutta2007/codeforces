#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int T,N,K;
int A[100];
bool ex[101];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&K);
		for(int i=1;i<=N;i++)ex[i]=false;
		for(int i=0;i<N;i++)
		{
			scanf("%d",&A[i]);
			ex[A[i]]=true;
		}
		vector<int>T;
		for(int i=1;i<=N;i++)if(ex[i])T.push_back(i);
		for(int i=1;i<=N;i++)if(!ex[i]&&T.size()<K)T.push_back(i);
		if(K<T.size())puts("-1");
		else
		{
			printf("%d\n",N*K);
			for(int i=0;i<N;i++)
			{
				for(int j=0;j<K;j++)
				{
					printf("%d%c",T[j],i+1==N&&j+1==K?'\n':' ');
				}
			}
		}
	}
}