#include<cstdio>
using namespace std;
int T,N;
int A[1<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		long long S=0;
		for(int i=0;i<N;i++)
		{
			scanf("%d",&A[i]);
			S^=(long long)A[i];
		}
		if(S==0)
		{
			puts("DRAW");
		}
		else
		{
			int i=32;
			while(!(S>>i&1))i--;
			int cnt=0;
			long long T=1LL<<i;
			for(int j=0;j<N;j++)
			{
				if((long long)A[j]&T)cnt++;
			}
			if(cnt%4==1)
			{
				puts("WIN");
			}
			else
			{
				puts((N-cnt)%2==0?"LOSE":"WIN");
			}
		}
	}
}