#include<cstdio>
using namespace std;
int T,N;
char S[222];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d\n%s",&N,S);
		bool ok=false;
		for(int i=0;i<=4;i++)
		{
			bool now=true;
			for(int j=0;j<i;j++)if(S[j]!=(j%2?'0':'2'))now=false;
			for(int j=N-4+i;j<N;j++)if(S[j]!=((N-j)%2?'0':'2'))now=false;
			if(now)ok=true;
		}
		puts(ok?"YES":"NO");
	}
}