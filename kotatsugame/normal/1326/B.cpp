#include<cstdio>
using namespace std;
int N;
int B[2<<17];
int A[2<<17];
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%d",&B[i]);
	int x=0;
	for(int i=0;i<N;i++)
	{
		A[i]=x+B[i];
		if(x<A[i])x=A[i];
	}
	for(int i=0;i<N;i++)printf("%d%c",A[i],i+1==N?'\n':' ');
}