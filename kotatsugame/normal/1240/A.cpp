#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int Q,N,P[2<<17];
int X,Y,A,B;
int C[2<<17];
long long K;
main()
{
	scanf("%d",&Q);
	for(;Q--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)scanf("%d",P+i);
		sort(P,P+N);
		reverse(P,P+N);
		scanf("%d%d%d%d%lld",&X,&A,&Y,&B,&K);
		for(int i=1;i<=N;i++)
		{
			C[i-1]=0;
			if(i%A==0)C[i-1]+=X;
			if(i%B==0)C[i-1]+=Y;
		}
		int L=-1,R=N+1;
		while(R-L>1)
		{
			int M=L+R>>1;
			vector<int>c(C,C+M);
			sort(c.rbegin(),c.rend());
			long long now=0;
			for(int i=0;i<M;i++)now+=(long long)P[i]/100*c[i];
			if(now>=K)R=M;
			else L=M;
		}
		printf("%d\n",R>N?-1:R);
	}
}