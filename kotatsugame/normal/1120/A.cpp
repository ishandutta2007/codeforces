#include<cstdio>
#include<queue>
using namespace std;
int N,K,M,S;
int A[5<<17],Bc[5<<17],Qc[5<<17];
queue<int>Q;
main()
{
	scanf("%d%d%d%d",&M,&K,&N,&S);
	for(int i=0;i<M;i++)scanf("%d",&A[i]);
	int needb=0;
	for(int i=0;i<S;i++)
	{
		int B;scanf("%d",&B);
		needb+=!Bc[B];
		Bc[B]++;
	}
	int okc=0;
	bool fn=false;
	int L,R,del;
	for(int i=M;i--;)
	{
		if(Bc[A[i]]!=0)
		{
			Q.push(i);
			Qc[A[i]]++;
			if(Qc[A[i]]==Bc[A[i]])okc++;
		}
		if(okc==needb)
		{
			while(!Q.empty()&&Qc[A[Q.front()]]>Bc[A[Q.front()]])
			{
				Qc[A[Q.front()]]--;
				Q.pop();
			}
			R=Q.front();
			L=i/K*K;
			int diff=R-L+1;
			if(diff>=K)
			{
				del=diff-K;
			}
			else
			{
				del=0;
			}
			if(M-del>=N*K&&L+K<=M)
			{
				fn=true;
				break;
			}
		}
	}
	if(!fn)
	{
		puts("-1");
		return 0;
	}
	printf("%d\n",del);
	if(del==0)puts("");
	else
	{
		for(int i=L;i<=R;i++)if(del>0)
		{
			if(Bc[A[i]]>0)Bc[A[i]]--;
			else
			{
				del--;
				printf("%d%c",i+1,del?32:10);
			}
		}
	}
}