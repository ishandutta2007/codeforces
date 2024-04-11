#include<cstdio>
#include<vector>
using namespace std;
int N;
int A[2<<17];
vector<int>ids[2<<17];
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%d",&A[i]),ids[A[i]].push_back(i);
	int mx=0;
	for(int i=0;i<2<<17;i++)if(ids[mx].size()<ids[i].size())mx=i;
	printf("%d\n",N-ids[mx].size());
	int fst=ids[mx][0];
	for(int i=fst-1;i>=0;i--)if(A[i]!=mx)
	{
		printf("%d %d %d\n",A[i]>mx?2:1,i+1,i+2);
	}
	for(int i=fst+1;i<N;i++)if(A[i]!=mx)
	{
		printf("%d %d %d\n",A[i]>mx?2:1,i+1,i);
	}
}