#include<cstdio>
using namespace std;
int T,N;
int A[30303];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)
		{
			scanf("%d",&A[i]);
		}
		int id=0;
		while(id+1<N&&A[id]>=A[id+1])id++;
		if(id+1==N)
		{
			puts("YES");
			continue;
		}
		int T=A[id];
		A[id]=0;
		bool ok=true;
		for(int i=id+1;i<N;i++)
		{
			if(A[i-1]>A[i])ok=false;
			else
			{
				int U=A[i]-A[i-1];
				if(T>U)T=U;
				A[i]-=T;
			}
		}
		puts(ok?"YES":"NO");
	}
}