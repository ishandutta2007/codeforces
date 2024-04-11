#include<cstdio>
using namespace std;
int T,N;
int A[10101];
int ans[10101];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)scanf("%d",&A[i]);
		bool ok=false;
		if(A[0]!=1)
		{
			int id=1;
			while(id<N&&A[id]!=1)id++;
			if(id==N)
			{
				ok=true;
				for(int i=0;i<N;i++)ans[i]=i;
				ans[N]=N;
			}
			else
			{
				ok=true;
				for(int i=0;i<id;i++)ans[i]=i;
				ans[id]=N;
				for(int i=id;i<N;i++)ans[i+1]=i;
			}
		}
		else
		{
			ok=true;
			ans[0]=N;
			for(int i=0;i<N;i++)ans[i+1]=i;
		}
		if(ok)
		{
			for(int i=0;i<=N;i++)printf("%d%c",ans[i]+1,i==N?10:32);
		}
		else puts("-1");
	}
}