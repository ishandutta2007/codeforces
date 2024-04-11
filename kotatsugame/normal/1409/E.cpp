#include<cstdio>
#include<algorithm>
using namespace std;
int T,N,K;
int X[2<<17];
int R[2<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&K);
		for(int i=0;i<N;i++)scanf("%d",&X[i]);
		for(int i=0;i<N;i++)scanf("%*d");
		sort(X,X+N);
		R[N]=0;
		{
			int r=N-1;
			for(int i=N;i--;)
			{
				while(X[r]-K>X[i])r--;
				R[i]=max(R[i+1],r-i+1);
			}
		}
		int ans=0;
		int l=0;
		for(int i=0;i<N;i++)
		{
			while(X[i]-K>X[l])l++;
			ans=max(ans,i-l+1+R[i+1]);
		}
		printf("%d\n",ans);
	}
}