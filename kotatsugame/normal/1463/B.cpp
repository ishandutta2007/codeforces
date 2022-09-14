#include<cstdio>
#include<algorithm>
using namespace std;
int T;
int A[50];
long long S;
int B[50];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		int N;
		scanf("%d",&N);
		S=0;
		for(int i=0;i<N;i++)
		{
			scanf("%d",&A[i]);
			S+=A[i];
		}
		for(int x=0;x<2;x++)
		{
			long long now=0;
			for(int i=0;i<N;i++)
			{
				if(i%2==x)B[i]=1;
				else B[i]=A[i];
				now+=abs(A[i]-B[i]);
			}
			if(2*now<=S)
			{
				for(int i=0;i<N;i++)printf("%d%c",B[i],i+1==N?'\n':' ');
				break;
			}
		}
	}
}