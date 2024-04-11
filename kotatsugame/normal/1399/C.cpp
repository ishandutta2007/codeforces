#include<cstdio>
#include<algorithm>
using namespace std;
int T,N;
int A[50];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)scanf("%d",&A[i]);
		sort(A,A+N);
		int ans=0;
		for(int i=0;i<N;i++)for(int j=i+1;j<N;j++)
		{
			int S=A[i]+A[j];
			int r=N-1;
			int now=0;
			for(int k=0;k<N;k++)
			{
				while(k<r&&A[k]+A[r]>S)r--;
				if(k>=r)break;
				if(A[k]+A[r]==S)r--,now++;
			}
			if(ans<now)ans=now;
		}
		printf("%d\n",ans);
	}
}