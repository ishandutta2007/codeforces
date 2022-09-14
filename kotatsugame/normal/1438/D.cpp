#include<cstdio>
using namespace std;
int N;
int A[1<<17];
main()
{
	scanf("%d",&N);
	int S=0;
	for(int i=0;i<N;i++)
	{
		scanf("%d",&A[i]);
		S^=A[i];
	}
	if(N%2==0&&S!=0)
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	printf("%d\n",(N-1)/2*2-1);
	for(int i=1;i+1<N;i+=2)printf("%d %d %d\n",1,i+1,i+2);
	for(int i=1;i+3<N;i+=2)printf("%d %d %d\n",1,i+1,i+2);
}