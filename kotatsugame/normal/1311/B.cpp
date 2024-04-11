#include<cstdio>
using namespace std;
int T,N,M;
int A[100];
bool ok[100];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&M);
		for(int i=0;i<N;i++)
		{
			ok[i]=false;
			scanf("%d",&A[i]);
		}
		for(int i=0;i<M;i++)
		{
			int p;scanf("%d",&p);ok[p-1]=true;
		}
		bool out=false;
		for(int i=0;i<N-1;i++)
		{
			int mid=i;
			for(int j=i+1;j<N;j++)if(A[j]<A[mid])mid=j;
			for(int j=mid-1;j>=i;j--)
			{
				if(!ok[j])out=true;
				int t=A[j];
				A[j]=A[j+1];
				A[j+1]=t;
			}
		}
		puts(out?"NO":"YES");
	}
}