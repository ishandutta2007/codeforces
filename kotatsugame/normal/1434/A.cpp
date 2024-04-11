#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int N;
int A[6],B[1<<17];
int cnt[1<<17];
main()
{
	for(int i=0;i<6;i++)scanf("%d",&A[i]);
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%d",&B[i]);
	vector<pair<int,int> >X(6*N);
	for(int i=0;i<N;i++)for(int j=0;j<6;j++)
	{
		X[i*6+j]=make_pair(B[i]-A[j],i);
	}
	sort(X.begin(),X.end());
	int L=0,R=0,check=0;
	while(check<N)
	{
		if(cnt[X[R++].second]++==0)check++;
	}
	int ans=X[R-1].first-X[L].first;
	while(L<6*N)
	{
		if(--cnt[X[L++].second]==0)
		{
			check--;
			while(R<6*N)
			{
				if(cnt[X[R++].second]++==0)
				{
					check++;
					break;
				}
			}
		}
		if(check<N)break;
		ans=min(ans,X[R-1].first-X[L].first);
	}
	printf("%d\n",ans);
}