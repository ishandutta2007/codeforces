#include<cstdio>
using namespace std;
int T,N;
bool used[1<<17];
int A[1<<17],B[1<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)
		{
			used[i+1]=false;
			scanf("%d",&A[i]);
			B[i]=0;
		}
		int pre=0;
		for(int i=0;i<N;i++)
		{
			if(pre<A[i])
			{
				B[i]=A[i];
				pre=A[i];
				used[B[i]]=true;
			}
		}
		int id=1;
		for(int i=0;i<N;i++)if(B[i]==0)
		{
			while(used[id])id++;
			used[id]=true;
			B[i]=id;
		}
		bool ok=true;
		int mx=0;
		for(int i=0;i<N;i++)
		{
			if(mx<B[i])mx=B[i];
			if(A[i]!=mx)ok=false;
		}
		if(ok)
		{
			for(int i=0;i<N;i++)printf("%d%c",B[i],i+1==N?'\n':' ');
		}
		else puts("-1");
	}
}