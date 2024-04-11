#include<cstdio>
#include<algorithm>
using namespace std;
int N;
int L[3<<17],R[3<<17];
int mLL[3<<17],mLR[3<<17],mRL[3<<17],mRR[3<<17];
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%d%d",&L[i],&R[i]);
	mRL[0]=1e9;
	for(int i=0;i<N;i++)
	{
		mLL[i+1]=max(mLL[i],L[i]);
		mRL[i+1]=min(mRL[i],R[i]);
	}
	mRR[N]=1e9;
	for(int i=N;i--;)
	{
		mLR[i]=max(mLR[i+1],L[i]);
		mRR[i]=min(mRR[i+1],R[i]);
	}
	int ans=0;
	for(int i=0;i<N;i++)
	{
		ans=max(ans,min(mRL[i],mRR[i+1])-max(mLL[i],mLR[i+1]));
	}
	printf("%d\n",ans);
}