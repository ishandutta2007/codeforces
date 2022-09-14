#include<cstdio>
using namespace std;
int N;
int A[2<<17];
int X[2<<17],Y[2<<17];
int pY[2<<17];
int ans[2<<17];
main()
{
	scanf("%d",&N);
	for(int i=1;i<=N;i++)scanf("%d",&A[i]);
	A[++N]=3e5;
	for(int i=2;i<=N;i++)
	{
		X[i]=Y[i]=-1;
		if(X[i-1]!=-1)
		{
			if(A[i-1]<A[i])
			{
				X[i]=X[i-1];
			}
			if(X[i-1]==0||A[X[i-1]]>A[i])
			{
				Y[i]=i-1;
			}
		}
		if(Y[i-1]!=-1)
		{
			if(A[i-1]>A[i])
			{
				if(Y[i]==-1)Y[i]=Y[i-1];
				else if(Y[i]!=0&&(Y[i-1]==0||A[Y[i]]>A[Y[i-1]]))Y[i]=Y[i-1];
			}
			if(Y[i-1]==0||A[Y[i-1]]<A[i])
			{
				if(X[i]==-1)X[i]=i-1;
				else if(X[i]!=0&&A[X[i]]<A[i-1])X[i]=i-1;
			}
		}
	}
	if(X[N]==-1)
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	int u=N;
	while(u>0)
	{
		u=X[u];
		int t=Y[u];
		while(u>t)ans[u--]=1;
	}
	N--;
	for(int i=1;i<=N;i++)printf("%d%c",ans[i],i==N?10:32);
}