#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N,K;
vector<int>A[2<<17];
main()
{
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++)
	{
		int a;scanf("%d",&a);
		int cnt=0;
		while(true)
		{
			A[a].push_back(cnt);
			if(a==0)break;
			a/=2;
			cnt++;
		}
	}
	int ans=1e9;
	for(int i=0;i<2<<17;i++)if(A[i].size()>=K)
	{
		sort(A[i].begin(),A[i].end());
		int now=0;
		for(int j=0;j<K;j++)now+=A[i][j];
		if(ans>now)ans=now;
	}
	printf("%d\n",ans);
}