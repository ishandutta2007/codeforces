#include<cstdio>
using namespace std;
int T,N;
int A[100][100];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		int u=(N-1)/2;
		bool fst=true;
		for(int i=0;i<N-1;i++)
		{
			for(int j=0;j<N-1-i;j++)
			{
				A[i][i+j+1]=j<u?1:j==u&&N%2==0?0:-1;
				if(fst)fst=false;
				else putchar(' ');
				printf("%d",A[i][i+j+1]);
			}
		}
		puts("");
	}
}