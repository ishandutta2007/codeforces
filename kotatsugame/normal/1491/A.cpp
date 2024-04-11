#include<cstdio>
using namespace std;
int N,Q;
int A[1<<17];
int cnt;
main()
{
	scanf("%d%d",&N,&Q);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&A[i]);
		if(A[i]==1)cnt++;
	}
	for(;Q--;)
	{
		int t;
		scanf("%d",&t);
		if(t==1)
		{
			int x;scanf("%d",&x);
			x--;
			A[x]=1-A[x];
			if(A[x]==1)cnt++;
			else cnt--;
		}
		else
		{
			int k;scanf("%d",&k);
			printf("%d\n",cnt<k?0:1);
		}
	}
}