#include<cstdio>
#include<algorithm>
using namespace std;
int T,N,B[2<<17];
int A[2<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		long long sum=0;
		for(int i=0;i<N+2;i++)
		{
			scanf("%d",&B[i]);
			sum+=B[i];
		}
		sort(B,B+N+2);
		bool fn=false;
		for(int i=0;i<N+2;i++)
		{
			long long nsum=sum-B[i];
			int mx=i==N+1?B[N]:B[N+1];
			if(mx*2==nsum)
			{
				fn=true;
				int sz=0;
				for(int j=0;j<N+2;j++)if(i!=j)A[sz++]=B[j];
				break;
			}
		}
		if(fn)
		{
			for(int i=0;i<N;i++)printf("%d%c",A[i],i+1==N?10:32);
		}
		else puts("-1");
	}
}