#include<cstdio>
#include<algorithm>
using namespace std;
int T;
int N,X,Y;
int A[55];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d%d",&N,&X,&Y);
		int diff=Y-X;
		int ans=1e9;
		for(int i=1;i<=diff;i++)if(diff%i==0)
		{
			int bit=diff/i+1;
			if(bit>N)continue;
			int left=(X-1)/i;
			if(bit+left>N)
			{
				if(ans>Y)
				{
					ans=Y;
					left=N-bit;
					for(int j=left;j--;)A[j]=X-i*(left-j);
					for(int j=0;j<bit;j++)A[left+j]=X+j*i;
				}
				continue;
			}
			int right=N-bit-left;
			if(ans>Y+right*i)
			{
				ans=Y+right*i;
				for(int j=left;j--;)A[j]=X-i*(left-j);
				for(int j=0;left+j<N;j++)A[left+j]=X+j*i;
			}
		}
		for(int i=0;i<N;i++)printf("%d%c",A[i],i+1==N?10:32);
	}
}