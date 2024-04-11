#include<cstdio>
using namespace std;
int T,N;
int A[8000];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)scanf("%d",&A[i]);
		int ans=0;
		for(int i=0;i<N;i++)
		{
			int now=0;
			int l=0;
			for(int r=0;r<N;r++)
			{
				now+=A[r];
				while(r-l+1>=3&&now>A[i])now-=A[l++];
				if(r-l+1>=2&&now==A[i])
				{
					ans++;
					break;
				}
			}
		}
		printf("%d\n",ans);
	}
}