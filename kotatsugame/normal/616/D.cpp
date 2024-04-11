#include<cstdio>
using namespace std;
int cnt[1<<20];
int A[5<<17];
main()
{
	int N,K;
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++)scanf("%d",&A[i]);
	int now=0;
	int l=0;
	int al=-1,ar=-2;
	for(int r=0;r<N;r++)
	{
		if(!cnt[A[r]]++)now++;
		while(now>K)
		{
			if(!--cnt[A[l++]])now--;
		}
		if(ar-al<r-l)al=l,ar=r;
	}
	printf("%d %d\n",al+1,ar+1);
}