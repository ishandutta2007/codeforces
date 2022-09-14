#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N,A[2<<17],B[2<<17];
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%d",&A[i]);
	for(int i=0;i<N;i++)scanf("%d",&B[i]);
	vector<int>X(N);
	long long ans=0;
	for(int i=0;i<N;i++)
	{
		X[i]=A[i]-B[i];
		if(A[i]>B[i])ans--;
	}
	sort(X.begin(),X.end());
	int ix=N-1;
	for(int i=0;i<N;i++)
	{
		while(ix>=0&&X[i]+X[ix]>0)ix--;
		ans+=N-1-ix;
	}
	printf("%lld\n",ans/2);
}