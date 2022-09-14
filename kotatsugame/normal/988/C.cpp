#include<cstdio>
#include<vector>
#include<map>
#include<set>
using namespace std;
int K;
map<int,vector<pair<int,int> > >mp;
main()
{
	scanf("%d",&K);
	for(int i=1;i<=K;i++)
	{
		int N;
		scanf("%d",&N);
		int sum=0;
		vector<int>A(N);
		for(int j=0;j<N;j++)
		{
			scanf("%d",&A[j]);
			sum+=A[j];
		}
		set<int>S;
		for(int j=0;j<N;j++)
		{
			int now=sum-A[j];
			if(S.find(now)==S.end())
			{
				S.insert(now);
				mp[now].push_back(make_pair(i,j+1));
			}
		}
	}
	for(const pair<int,vector<pair<int,int> > >&p:mp)
	{
		if(p.second.size()>=2)
		{
			puts("YES");
			printf("%d %d\n",p.second[0].first,p.second[0].second);
			printf("%d %d\n",p.second[1].first,p.second[1].second);
			return 0;
		}
	}
	puts("NO");
}