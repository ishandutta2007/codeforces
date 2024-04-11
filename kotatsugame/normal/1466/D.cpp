#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int T,N;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		vector<int>W(N);
		long long sum=0;
		for(int i=0;i<N;i++)
		{
			scanf("%d",&W[i]);
			sum+=W[i];
		}
		vector<int>cnt(N,0);
		for(int i=0;i<N-1;i++)
		{
			int a,b;scanf("%d%d",&a,&b);
			cnt[a-1]++;
			cnt[b-1]++;
		}
		vector<int>ret;ret.reserve(N-2);
		for(int i=0;i<N;i++)for(int j=1;j<cnt[i];j++)ret.push_back(W[i]);
		sort(ret.begin(),ret.end());
		reverse(ret.begin(),ret.end());
		printf("%lld",sum);
		for(int w:ret)
		{
			sum+=w;
			printf(" %lld",sum);
		}
		puts("");
	}
}