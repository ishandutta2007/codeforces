#include<cstdio>
#include<algorithm>
using namespace std;
int N;
int A[2<<17];
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%d",&A[i]);
	sort(A,A+N);
	int ans=0;
	int l=0;
	for(int r=0;r<N;r++)
	{
		while(A[l]+5<A[r])l++;
		ans=max(ans,r-l+1);
	}
	printf("%d\n",ans);
}