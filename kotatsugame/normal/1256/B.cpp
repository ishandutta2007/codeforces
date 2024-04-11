#include<cstdio>
using namespace std;
int T,N,A[100];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)scanf("%d",&A[i]);
		for(int i=0;i<N;)
		{
			int j=i;
			for(int k=i+1;k<N;k++)if(A[k]<A[j])j=k;
			if(i==j)
			{
				i++;
				continue;
			}
			for(int k=j-1;k>=i;k--)
			{
				int t=A[k+1];
				A[k+1]=A[k];
				A[k]=t;
			}
			i=j;
		}
		for(int i=0;i<N;i++)printf("%d%c",A[i],i+1==N?10:32);
	}
}