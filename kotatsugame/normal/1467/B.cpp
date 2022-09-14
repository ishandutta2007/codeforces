#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int T,N;
int A[3<<17];
bool check(int id){return 0<id&&id<N-1&&(A[id-1]<A[id]&&A[id]>A[id+1]||A[id-1]>A[id]&&A[id]<A[id+1]);}
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)scanf("%d",&A[i]);
		int cnt=0;
		for(int i=1;i<N-1;i++)
		{
			if(check(i))cnt++;
		}
		int mx=0;
		for(int i=0;i<N;i++)
		{
			int now=0;
			for(int j=i-1;j<i+3;j++)
			{
				if(check(j))now--;
			}
			int tmp=A[i];
			if(i>0)
			{
				A[i]=A[i-1];
				int ret=now;
				for(int j=i-1;j<i+3;j++)
				{
					if(check(j))ret++;
				}
				mx=min(mx,ret);
			}
			if(i+1<N)
			{
				A[i]=A[i+1];
				int ret=now;
				for(int j=i-1;j<i+3;j++)
				{
					if(check(j))ret++;
				}
				mx=min(mx,ret);
			}
			A[i]=tmp;
		}
		printf("%d\n",cnt+mx);
	}
}