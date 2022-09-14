#include<cstdio>
using namespace std;
int T,N;
char S[3<<17];
int L[3<<17],R[3<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%s",&N,S);
		for(int i=0;i<=N;i++)L[i]=R[i]=0;
		if(S[0]=='L')L[1]=1;
		for(int i=2;i<=N;i++)
		{
			if(S[i-2]=='R'&&S[i-1]=='L')L[i]=L[i-2]+2;
			else if(S[i-1]=='L')L[i]=1;
			else L[i]=0;
		}
		if(S[N-1]=='R')R[N-1]=1;
		for(int i=N-2;i>=0;i--)
		{
			if(S[i]=='R'&&S[i+1]=='L')R[i]=R[i+2]+2;
			else if(S[i]=='R')R[i]=1;
			else R[i]=0;
		}
		for(int i=0;i<=N;i++)printf("%d%c",L[i]+R[i]+1,i==N?10:32);
	}
}