#include<cstdio>
using namespace std;
int T,N;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)
		{
			int A;scanf("%d",&A);
			A=A>0?A:-A;
			if(i%2==1)A=-A;
			printf("%d%c",A,i+1==N?'\n':' ');
		}
	}
}