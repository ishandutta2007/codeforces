#include<cstdio>
#include<algorithm>
using namespace std;
int T,N;
int A[2<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)scanf("%d",&A[i]);
		sort(A,A+N);
		reverse(A,A+N);
		long long score=0;
		for(int i=0;i<N;i++)
		{
			if(i%2==0)
			{
				if(A[i]%2==0)score+=A[i];
			}
			else
			{
				if(A[i]%2==1)score-=A[i];
			}
		}
		puts(score>0?"Alice":score<0?"Bob":"Tie");
	}
}