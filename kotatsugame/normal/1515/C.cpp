#include<cstdio>
#include<queue>
using namespace std;
int T,N,M,X;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d%d",&N,&M,&X);
		priority_queue<pair<int,int> >P;
		for(int i=0;i<M;i++)P.push(make_pair(0,i+1));
		puts("YES");
		for(int i=0;i<N;i++)
		{
			int H;
			scanf("%d",&H);
			pair<int,int>p=P.top();P.pop();
			p.first-=H;
			printf("%d%c",p.second,i+1==N?10:32);
			P.push(p);
		}
	}
}