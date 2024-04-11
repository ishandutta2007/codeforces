#include<cstdio>
#include<algorithm>
using namespace std;
int A[3],B[3];
int N;
main()
{
	scanf("%d",&N);
	for(int i=0;i<3;i++)scanf("%d",&A[i]);
	for(int i=0;i<3;i++)scanf("%d",&B[i]);
	int MIN=0;
	for(int i=0;i<3;i++)
	{
		int t=A[i];
		for(int j=0;j<3;j++)if((i+1)%3!=j)t-=B[j];
		if(t>0)MIN+=t;
	}
	int MAX=0;
	for(int i=0;i<3;i++)MAX+=min(A[i],B[(i+1)%3]);
	printf("%d %d\n",MIN,MAX);
}