#include<cstdio>
using namespace std;
int N;
long long A[1<<17];
long long B[1<<17];
int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%lld",&A[i]);
	if(N==1)
	{
		printf("1 1\n%lld\n1 1\n0\n1 1\n0\n",-A[0]);
		return 0;
	}
	for(int st=0;st<2;st++)
	{
		printf("%d %d\n",st+1,st+N-1);
		for(int j=0;j<N-1;j++)
		{
			int i=st+j;
			long long T=A[i]%N;
			if(T<0)T+=N;
			printf("%lld%c",T*(N-1),j==N-2?'\n':' ');
			A[i]+=T*(N-1);
		}
	}
	printf("%d %d\n",1,N);
	for(int i=0;i<N;i++)
	{
		printf("%lld%c",-A[i],i==N-1?'\n':' ');
	}
}