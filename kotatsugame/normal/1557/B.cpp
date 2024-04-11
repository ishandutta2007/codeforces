#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int T;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		int N,K;
		scanf("%d%d",&N,&K);
		vector<pair<int,int> >A(N);
		for(int i=0;i<N;i++)
		{
			scanf("%d",&A[i].first);
			A[i].second=i;
		}
		sort(A.begin(),A.end());
		K--;
		for(int i=0;i<N-1;i++)if(A[i].second+1!=A[i+1].second)K--;
		puts(K<0?"No":"Yes");
	}
}