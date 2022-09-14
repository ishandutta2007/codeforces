#include<cstdio>
#include<algorithm>
using namespace std;
int T,N,K;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&K);
		int H;scanf("%d",&H);
		int L=H,R=H;
		bool ok=true;
		for(int i=1;i<N;i++)
		{
			scanf("%d",&H);
			int nL=L-(K-1),nR=R+(K-1);
			if(nL<H)nL=H;
			if(nR>H+(K-1))nR=H+(K-1);
			if(nL>nR)ok=false;
			L=nL;
			R=nR;
		}
		puts(ok&&L==H?"YES":"NO");
	}
}