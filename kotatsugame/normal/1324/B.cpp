#include<cstdio>
#include<algorithm>
using namespace std;
int T,N,A[5000];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)
		{
			scanf("%d",&A[i]);
		}
		bool flag=false;
		for(int i=0;i<N;i++)
		{
			for(int j=i+2;j<N;j++)
			{
				if(A[i]==A[j])
				{
					flag=true;
					break;
				}
			}
			if(flag)break;
		}
		puts(flag?"YES":"NO");
	}
}