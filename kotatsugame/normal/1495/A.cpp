#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int T,N;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		int N;
		scanf("%d",&N);
		vector<long long>X,Y;
		X.reserve(N);Y.reserve(N);
		for(int i=0;i<2*N;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			if(x==0)Y.push_back((long long)y*y);
			else X.push_back((long long)x*x);
		}
		sort(X.begin(),X.end());
		sort(Y.begin(),Y.end());
		double ans=0;
		for(int i=0;i<N;i++)ans+=sqrt(X[i]+Y[i]);
		printf("%.16f\n",ans);
	}
}