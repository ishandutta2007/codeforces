#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int N,A[101];
main()
{
	scanf("%d",&N);
	vector<pair<int,int> >B(N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&A[i]);
		B[i]=make_pair(-A[i],i);
	}
	sort(B.begin(),B.end());
	int M;
	scanf("%d",&M);
	for(;M--;)
	{
		int k,p;scanf("%d%d",&k,&p);
		vector<pair<int,int> >id(k);
		for(int i=0;i<k;i++)id[i]=make_pair(B[i].second,-B[i].first);
		sort(id.begin(),id.end());
		printf("%d\n",id[p-1].second);
	}
}