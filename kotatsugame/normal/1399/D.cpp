#include<cstdio>
#include<queue>
using namespace std;
int T,N;
char S[2<<17];
int ans[2<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%s",&N,S);
		queue<int>P[2];
		int sz=0;
		for(int i=0;i<N;i++)
		{
			int u=S[i]-'0';
			if(P[1-u].empty())
			{
				ans[i]=++sz;
			}
			else
			{
				int t=P[1-u].front();P[1-u].pop();
				ans[i]=t;
			}
			P[u].push(ans[i]);
		}
		printf("%d\n",sz);
		for(int i=0;i<N;i++)printf("%d%c",ans[i],i+1==N?10:32);
	}
}