#include<cstdio>
#include<algorithm>
using namespace std;
int T,N;
int A[100],L[100];
int B[100];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		int unl=0;
		for(int i=0;i<N;i++)
		{
			scanf("%d",&A[i]);
		}
		for(int i=0;i<N;i++)
		{
			scanf("%d",&L[i]);
			if(!L[i])
			{
				B[unl++]=A[i];
			}
		}
		sort(B,B+unl);
		reverse(B,B+unl);
		unl=0;
		for(int i=0;i<N;i++)
		{
			if(L[i])printf("%d",A[i]);
			else printf("%d",B[unl++]);
			printf("%c",i+1==N?'\n':' ');
		}
	}
}