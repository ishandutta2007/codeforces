#include<cstdio>
#include<vector>
using namespace std;
int T,N,K;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&K);
		vector<int>id;
		for(int i=1;i<=N;i++)
		{
			int A;
			scanf("%d",&A);
			if(A%2)id.push_back(i);
		}
		if(id.size()<K||(id.size()-K)%2==1)
		{
			puts("NO");
		}
		else
		{
			puts("YES");
			for(int i=0;i<K-1;i++)printf("%d ",id[i]);
			printf("%d\n",N);
		}
	}
}