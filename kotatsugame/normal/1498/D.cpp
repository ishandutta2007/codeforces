#include<cstdio>
#include<algorithm>
using namespace std;
int N,M;
int A[1<<17];
int D[1<<17];
main()
{
	scanf("%d%d",&N,&M);
	for(int i=1;i<=M;i++)A[i]=-1;
	for(int i=0;i<N;i++)
	{
		int t,y;long long x;
		scanf("%d%lld%d",&t,&x,&y);
		for(int j=0;j<=M;j++)D[j]=A[j]==-1?y+1:0;
		const long long B=1e5;
		for(int j=0;j<=M;j++)if(D[j]<y)
		{
			long long nj;
			if(t==1)nj=j+(x+B-1)/B;
			else nj=(j*x+B-1)/B;
			if(nj<=M)D[nj]=min(D[nj],D[j]+1);
		}
		for(int j=0;j<=M;j++)if(D[j]<=y&&A[j]==-1)A[j]=i+1;
	}
	for(int i=1;i<=M;i++)printf("%d%c",A[i],i==M?10:32);
}