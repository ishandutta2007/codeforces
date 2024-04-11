#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N,D,K;
main()
{
	scanf("%d%d%d",&N,&D,&K);
	if(K==1)
	{
		if(N==2&&D==1)
		{
			printf("YES\n1 2\n");
		}
		else
		{
			puts("NO");
		}
		return 0;
	}
	if(D+1>N)
	{
		puts("NO");
		return 0;
	}
	vector<pair<int,int> >E;
	vector<pair<int,pair<int,int> > >vs;
	for(int i=1;i<=D;i++)E.push_back(make_pair(i,i+1));
	for(int i=2;i<=D;i++)vs.push_back(make_pair(i,make_pair(min(i-1,D+1-i),K-2)));
	for(int i=D+2;i<=N;i++)
	{
		while(!vs.empty()&&vs.back().second.second==0)vs.pop_back();
		if(vs.empty())
		{
			puts("NO");
			return 0;
		}
		int u=vs.back().first;
		E.push_back(make_pair(u,i));
		vs.back().second.second--;
		int d=vs.back().second.first;
		if(d>1)
		{
			vs.push_back(make_pair(i,make_pair(d-1,K-1)));
		}
	}
	puts("YES");
	for(pair<int,int>e:E)printf("%d %d\n",e.first,e.second);
}