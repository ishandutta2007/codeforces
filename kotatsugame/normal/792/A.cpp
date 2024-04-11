#include<cstdio>
#include<algorithm>
using namespace std;
int N;
int A[2<<17];
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%d",&A[i]);
	sort(A,A+N);
	int mn=A[1]-A[0];
	int c=1;
	for(int i=1;i+1<N;i++)
	{
		int d=A[i+1]-A[i];
		if(mn>d)mn=d,c=1;
		else if(mn==d)c++;
	}
	printf("%d %d\n",mn,c);
}