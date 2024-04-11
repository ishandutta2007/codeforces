#include<cstdio>
using namespace std;
int T,N,M;
int A[1<<17];
int r[1<<17];
double p[1<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&M);
		for(int i=0;i<N;i++)scanf("%d",&A[i]);
		for(int i=0;i<M;i++)scanf("%d%lf",&r[i],&p[i]);
		int id=N-1;
		while(id>=0&&A[id]==id+1)id--;
		double ans=1;
		if(id>=0)
		{
			for(int i=0;i<M;i++)if(r[i]>id)ans*=1-p[i];
			ans=1-ans;
		}
		printf("%lf\n",ans);
	}
}