#include<cstdio>
#include<algorithm>
using namespace std;
int T;
int N;
int A[100];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		int mA=101;
		for(int i=0;i<N;i++)
		{
			scanf("%d",&A[i]);
			mA=min(mA,A[i]);
		}
		int cnt=0;
		for(int i=0;i<N;i++)cnt+=mA<A[i];
		printf("%d\n",cnt);
	}
}