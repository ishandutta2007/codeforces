#include<cstdio>
using namespace std;
int T,N;
int A[2<<17];
int L[2<<17],R[2<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)scanf("%d",&A[i]);
		L[0]=0;
		for(int i=1;i<=N;i++)
		{
			if(L[i-1]==-1)L[i]=-1;
			else
			{
				if(L[i-1]>A[i-1])L[i]=-1;
				else L[i]=A[i-1]-L[i-1];
			}
		}
		R[N]=0;
		for(int i=N;i--;)
		{
			if(R[i+1]==-1)R[i]=-1;
			else
			{
				if(R[i+1]>A[i])R[i]=-1;
				else R[i]=A[i]-R[i+1];
			}
		}
		if(L[N]==0)
		{
			puts("YES");
			continue;
		}
		bool fn=false;
		for(int i=0;i<N-1;i++)
		{
			if(L[i]==-1||R[i+2]==-1)continue;
			int l=A[i+1]-L[i];
			int r=A[i]-R[i+2];
			if(l>=0&&r>=0&&l==r)
			{
				fn=true;
				break;
			}
		}
		puts(fn?"YES":"NO");
	}
}