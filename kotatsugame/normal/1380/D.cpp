#include<cstdio>
#include<algorithm>
using namespace std;
int N,M,X,K,Y;
int A[2<<17],B[2<<17];
main()
{
	scanf("%d%d%d%d%d",&N,&M,&X,&K,&Y);
	for(int i=0;i<N;i++)scanf("%d",&A[i]);
	for(int i=0;i<M;i++)scanf("%d",&B[i]);
	long long ans=0;
	int pre=0;
	bool out=false;
	long long LIM=1e18;
	for(int i=0;i<M;i++)
	{
		int now=pre;
		int mA=0;
		while(now<N&&A[now]!=B[i])
		{
			if(mA<A[now])mA=A[now];
			now++;
		}
		if(now==N)
		{
			out=true;
			break;
		}
		int diff=now-pre;
		long long S=LIM;
		if(diff>=K)
		{
			S=diff%K*(long long)Y+diff/K*(long long)X;
			S=min(S,(long long)X+(diff-K)*(long long)Y);
		}
		if(mA<B[i]||i>0&&mA<B[i-1])
		{
			S=min(S,diff*(long long)Y);
		}
		if(S==LIM)
		{
			out=true;
			break;
		}
		ans+=S;
		pre=now+1;
	}
	int diff=N-pre;
	long long S=LIM;
	int mA=0;
	for(int i=pre;i<N;i++)if(mA<A[i])mA=A[i];
	if(diff>=K)
	{
		S=diff%K*(long long)Y+diff/K*(long long)X;
		S=min(S,(long long)X+(diff-K)*(long long)Y);
	}
	if(mA<B[M-1])
	{
		S=min(S,diff*(long long)Y);
	}
	if(S==LIM)
	{
		out=true;
	}
	ans+=S;
	if(out)printf("-1\n");
	else printf("%lld\n",ans);
}