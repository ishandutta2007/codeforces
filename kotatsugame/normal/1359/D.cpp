#include<cstdio>
#include<algorithm>
using namespace std;
int N;
int A[1<<17],S[1<<17];
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&A[i]);
		S[i+1]=S[i]+A[i];
	}
	int ans=0;
	for(int k=30;k>=-30;k--)
	{
		int Lmin=0;
		for(int i=0;i<N;i++)
		{
			if(A[i]>k)
			{
				Lmin=S[i+1];
			}
			else
			{
				ans=max(ans,S[i+1]-Lmin-k);
				Lmin=min(Lmin,S[i+1]);
			}
		}
	}
	printf("%d\n",ans);
}