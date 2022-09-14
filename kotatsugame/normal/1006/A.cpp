#include<cstdio>
using namespace std;
int N;
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		int A;
		scanf("%d",&A);
		printf("%d%c",A%2==1?A:A-1,i+1==N?10:32);
	}
}