#include<cstdio>
using namespace std;
int N;
int cnt[1<<17];
main()
{
	scanf("%d",&N);
	for(int i=1;i<N;i++)
	{
		int u,v;scanf("%d%d",&u,&v);
		cnt[u]++;
		cnt[v]++;
	}
	bool flag=false;
	for(int i=1;i<=N;i++)flag|=cnt[i]==2;
	puts(flag?"NO":"YES");
}