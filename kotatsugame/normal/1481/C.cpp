#include<cstdio>
#include<vector>
using namespace std;
int T,N,M;
int A[1<<17],B[1<<17],C[1<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&M);
		for(int i=0;i<N;i++)scanf("%d",&A[i]);
		for(int i=0;i<N;i++)scanf("%d",&B[i]);
		for(int i=0;i<M;i++)scanf("%d",&C[i]);
		vector<vector<int> >need(N);
		vector<int>ok(N,-1);
		vector<int>ans(M);
		for(int i=0;i<N;i++)
		{
			if(A[i]==B[i])ok[A[i]-1]=i;
			else need[B[i]-1].push_back(i);
		}
		int used=-1;
		bool out=false;
		for(int i=M;i--;)
		{
			if(need[C[i]-1].empty())
			{
				if(used!=-1)ans[i]=used;
				else if(ok[C[i]-1]!=-1)ans[i]=used=ok[C[i]-1];
				else out=true;
			}
			else
			{
				int u=need[C[i]-1].back();
				need[C[i]-1].pop_back();
				ans[i]=u;
				used=u;
			}
		}
		for(int i=0;i<N;i++)if(!need[i].empty())out=true;
		if(out)puts("NO");
		else
		{
			puts("YES");
			for(int i=0;i<M;i++)printf("%d%c",ans[i]+1,i+1==M?10:32);
		}
	}
}