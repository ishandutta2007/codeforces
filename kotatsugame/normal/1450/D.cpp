#include<cstdio>
using namespace std;
int T,N;
int A[3<<17];
int ex[3<<17],tm;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		tm++;
		bool dup=false;
		for(int i=0;i<N;i++)
		{
			scanf("%d",&A[i]);
			if(ex[A[i]]==tm)dup=true;
			ex[A[i]]=tm;
		}
		printf("%c",dup?'0':'1');
		int L=0,R=N-1,k=0;
		while(L<=R)
		{
			if(A[L]==k+1)
			{
				k++;
				L++;
			}
			else if(A[R]==k+1)
			{
				k++;
				R--;
			}
			else break;
		}
		int mn=N+1;
		for(int i=L;i<=R;i++)if(A[i]<mn)mn=A[i];
		for(int i=2;i<=N;i++)
		{
			int t=N-i+1;
			if(mn<t)printf("0");
			else if(t<=k)printf("1");
			else if(t==k+1&&mn==t)printf("1");
			else printf("0");
		}
		puts("");
	}
}