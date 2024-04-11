#include<cstdio>
using namespace std;
int N,K;
int A[2<<17];
main()
{
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++)scanf("%d",&A[i]);
	int L=0,R=1e9;
	while(R-L>1)
	{
		int M=L+R>>1;
		bool ok=false;
		for(int tm=0;tm<2;tm++)
		{
			int wt=tm;
			int cnt=0;
			for(int i=0;i<N;i++)
			{
				if(wt==1)
				{
					wt=0;
					cnt++;
				}
				else if(A[i]<=M)
				{
					wt=1;
					cnt++;
				}
			}
			if(cnt>=K)ok=true;
		}
		if(ok)R=M;
		else L=M;
	}
	printf("%d\n",R);
}