#include<cstdio>
#include<algorithm>
using namespace std;
int N,M;
int A[2<<17];
main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)scanf("%d",&A[i]);
	sort(A,A+N);
	for(int i=0;i<M;i++)
	{
		int B;scanf("%d",&B);
		printf("%d%c",(int)(upper_bound(A,A+N,B)-A),i+1==M?10:32);
	}
}