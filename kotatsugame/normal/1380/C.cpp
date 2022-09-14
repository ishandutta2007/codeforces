#include<cstdio>
#include<algorithm>
using namespace std;
int T,N;
long long X;
int A[1<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%lld",&N,&X);
		for(int i=0;i<N;i++)scanf("%d",&A[i]);
		sort(A,A+N);
		int ans=0;
		for(int i=N-1;i>=0;)
		{
			int j=i;
			while(j>=0&&(long long)A[j]*(i-j+1)<X)j--;
			if(j>=0)ans++;
			i=j-1;
		}
		printf("%d\n",ans);
	}
}