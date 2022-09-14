#include<cstdio>
using namespace std;
int T,N;
int A[1<<17],B[1<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)scanf("%d",&A[i]);
		for(int i=0;i<N;i++)scanf("%d",&B[i]);
		bool ok=true;
		bool m=false,p=false;
		for(int i=0;i<N;i++)
		{
			if(A[i]<B[i])
			{
				if(!p)ok=false;
			}
			else if(A[i]>B[i])
			{
				if(!m)ok=false;
			}
			if(A[i]==1)p=true;
			else if(A[i]==-1)m=true;
		}
		puts(ok?"YES":"NO");
	}
}