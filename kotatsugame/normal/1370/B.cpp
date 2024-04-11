#include<cstdio>
#include<vector>
using namespace std;
int T,N;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		vector<int>X[2];
		for(int i=1;i<=2*N;i++)
		{
			int A;
			scanf("%d",&A);
			X[A%2].push_back(i);
		}
		vector<pair<int,int> >ans;
		for(int j=0;j<2;j++)
		{
			for(int i=0;i+2<=X[j].size();i+=2)ans.push_back(make_pair(X[j][i],X[j][i+1]));
		}
		for(int i=0;i<N-1;i++)printf("%d %d\n",ans[i].first,ans[i].second);
	}
}