#include<cstdio>
#include<vector>
using namespace std;
int T,N;
int A[333];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)scanf("%d",&A[i]);
		int L=0,R=N;
		int f=0;
		int fst=1;
		while(L<R)
		{
			if(!fst)printf(" ");
			else fst=0;
			if(!f)printf("%d",A[L++]);
			else printf("%d",A[--R]);
			f=!f;
		}
		puts("");
	}
}