#include<cstdio>
#include<algorithm>
using namespace std;
int T,N;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		bool ok=false;
		int j=1;
		for(int i=2;i*i<=N;i++)
		{
			if(N%i==0)j=max(j,N/i);
		}
		printf("%d %d\n",j,N-j);
	}
}