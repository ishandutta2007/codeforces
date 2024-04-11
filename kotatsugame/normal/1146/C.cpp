#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int T;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		int N;scanf("%d",&N);
		vector<int>now;
		for(int i=2;i<=N;i++)now.push_back(i);
		int pre;
		printf("%d %d %d",1,N-1,1);
		for(int i=0;i<now.size();i++)printf(" %d",now[i]);
		puts("");
		fflush(stdout);
		scanf("%d",&pre);
		while(now.size()>1)
		{
			int t=now.size()/2;
			printf("%d %d %d",1,t,1);
			for(int i=0;i<t;i++)printf(" %d",now[i]);
			puts("");
			fflush(stdout);
			int p;
			scanf("%d",&p);
			vector<int>tmp;
			if(p==pre)
			{
				for(int i=0;i<t;i++)tmp.push_back(now[i]);
			}
			else
			{
				for(int i=t;i<now.size();i++)tmp.push_back(now[i]);
			}
			now=tmp;
		}
		int ans;
		printf("%d %d %d",1,N-1,now[0]);
		for(int i=1;i<=N;i++)if(i!=now[0])printf(" %d",i);
		puts("");
		fflush(stdout);
		scanf("%d",&ans);
		printf("-1 %d\n",ans);
		fflush(stdout);
	}
}