#include<cstdio>
#include<vector>
using namespace std;
int T,N;
int P[4<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)scanf("%d",&P[i]);
		vector<int>cnt(1,1);
		for(int i=1;i<N;i++)
		{
			if(P[i-1]>P[i])
			{
				cnt.push_back(1);
			}
			else cnt.back()++;
		}
		int sum=N;
		while(sum*2>N)
		{
			sum-=cnt.back();
			cnt.pop_back();
		}
		if(cnt.empty())
		{
			puts("0 0 0");
			continue;
		}
		int g=cnt[0];
		int s=0,b=0;
		for(int i=1;i<cnt.size();i++)
		{
			if(g>=s)s+=cnt[i];
			else b+=cnt[i];
		}
		if(g<b)printf("%d %d %d\n",g,s,b);
		else puts("0 0 0");
	}
}