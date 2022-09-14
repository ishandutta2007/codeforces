#include<cstdio>
using namespace std;
int T,N;
int L,R,S;
int P[501];
bool usd[501];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d%d%d",&N,&L,&R,&S);
		L--;
		int K=R-L;
		if(S<K*(K+1)/2||K*(K+1)/2+K*(N-K)<S)puts("-1");
		else
		{
			for(int i=1;i<=N;i++)usd[i]=false;
			for(int i=N;i;i--)
			{
				S-=i;
				K--;
				if(S<K*(K+1)/2)
				{
					S+=i;
					K++;
				}
				else
				{
					P[L+K]=i;
					usd[i]=true;
				}
			}
			int id=1;
			for(int i=0;i<N;i++)
			{
				if(L<=i&&i<R)printf("%d",P[i]);
				else
				{
					while(usd[id])id++;
					printf("%d",id++);
				}
				printf("%c",i+1==N?10:32);
			}
		}
	}
}