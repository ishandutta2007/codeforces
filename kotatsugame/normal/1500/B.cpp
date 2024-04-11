#include<cstdio>
#include<algorithm>
using namespace std;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int N,M;
long long K;
int A[5<<17],B[5<<17];
int invB[1<<20];
int diff[5<<17];
main()
{
	scanf("%d%d%lld",&N,&M,&K);
	for(int i=0;i<N;i++)scanf("%d",&A[i]);
	for(int i=0;i<M;i++)scanf("%d",&B[i]);
	if(N<M)
	{
		for(int i=0;i<M;i++)swap(A[i],B[i]);
		swap(N,M);
	}
	for(int i=0;i<N;i++)diff[i]=M;
	for(int i=0;i<M;i++)invB[B[i]]=i+1;
	for(int i=0;i<N;i++)
	{
		if(invB[A[i]]==0)continue;
		int id=invB[A[i]]-1;
		diff[(i-id+N)%N]--;
	}
	int g=gcd(N,M);
	long long ONE=0;
	for(int i=0;i<N;i+=g)ONE+=diff[i];
	K--;
	long long ans=K/ONE*((long long)N*M/g);
	K%=ONE;
	int ai=0,bi=0;
	while(K>0)
	{
		if(K>=diff[ai])
		{
			K-=diff[ai];
			ai=(ai+M)%N;
			ans+=M;
		}
		else
		{
			break;
		}
	}
	while(K>=0)
	{
		ans++;
		if(A[ai]!=B[bi])
		{
			K--;
			if(K==-1)
			{
				printf("%lld\n",ans);
				return 0;
			}
		}
		ai=(ai+1)%N;
		bi=(bi+1)%M;
	}
}