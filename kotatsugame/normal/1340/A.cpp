#include<cstdio>
#include<algorithm>
using namespace std;
int T,N;
int A[1<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)scanf("%d",&A[i]);
		bool ok=true;
		for(int i=0;i<N;)
		{
			int j=i;
			while(j<N&&A[j]>=A[i])
			{
				j++;
			}
			reverse(A+i,A+j);
			i=j;
		}
		for(int i=0;i<N;i++)if(A[i]!=N-i)ok=false;
		puts(ok?"Yes":"No");
	}
}