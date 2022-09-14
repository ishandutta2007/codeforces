#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N,Q,A[2<<17];
int id[2<<17],X[2<<17];
int L[2<<17];
int cummax[2<<17];
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&A[i]);
	}
	scanf("%d",&Q);
	for(int i=0;i++<Q;)
	{
		int p;scanf("%d",&p);
		if(p==1)
		{
			scanf("%d%d",&id[i],&X[i]);
			id[i]--;
			L[id[i]]=i;
		}
		else
		{
			scanf("%d",&X[i]);
			id[i]=-1;
		}
	}
	for(int i=Q;i>=0;i--)
	{
		if(id[i]<0)cummax[i]=max(cummax[i+1],X[i]);
		else cummax[i]=cummax[i+1];
	}
	for(int i=0;i<N;i++)
	{
		printf("%d",L[i]==0?max(cummax[0],A[i]):max(cummax[L[i]],X[L[i]]));
		putchar(i==N-1?'\n':' ');
	}
}