#include<cstdio>
#include<queue>
#include<stack>
using namespace std;
int T,N;
int Q[2<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)scanf("%d",&Q[i]);
		{
			queue<int>P;
			int pre=0;
			for(int i=0;i<N;i++)
			{
				int x;
				if(pre<Q[i])
				{
					for(int j=pre+1;j<Q[i];j++)P.push(j);
					x=Q[i];
					pre=Q[i];
				}
				else
				{
					x=P.front();
					P.pop();
				}
				printf("%d%c",x,i+1==N?10:32);
			}
		}
		{
			stack<int>P;
			int pre=0;
			for(int i=0;i<N;i++)
			{
				int x;
				if(pre<Q[i])
				{
					for(int j=pre+1;j<Q[i];j++)P.push(j);
					x=Q[i];
					pre=Q[i];
				}
				else
				{
					x=P.top();
					P.pop();
				}
				printf("%d%c",x,i+1==N?10:32);
			}
		}
	}
}