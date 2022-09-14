#include<cstdio>
#include<algorithm>
using namespace std;
const long long mod=1e9+7;
int T,N,K;
int A[1010];
int comb[1010][1010];
main()
{
	scanf("%d",&T);
	comb[0][0]=1;
	for(int i=1;i<1010;i++)
	{
		comb[i][0]=comb[i][i]=1;
		for(int j=1;j<i;j++)comb[i][j]=(comb[i-1][j-1]+comb[i-1][j])%mod;
	}
	for(;T--;)
	{
		scanf("%d%d",&N,&K);
		for(int i=0;i<N;i++)scanf("%d",&A[i]);
		sort(A,A+N);
		reverse(A,A+N);
		int ca=0,cb=0;
		for(int i=0;i<N;i++)if(A[i]==A[K-1])
		{
			if(i<K)ca++;
			cb++;
		}
		printf("%d\n",comb[cb][ca]);
	}
}