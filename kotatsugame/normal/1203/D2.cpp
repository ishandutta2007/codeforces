#include<cstdio>
#include<cstring>
using namespace std;
char S[2<<17],T[2<<17];
int R[2<<17];
int N,M;
main()
{
	scanf("%s%s",S,T);
	N=strlen(S);
	M=strlen(T);
	int r=M;
	R[r]=N;
	for(int i=N;i--;)
	{
		if(r>0&&S[i]==T[r-1])r--;
		if(R[r]<i)R[r]=i;
	}
	int ans=R[0];
	int l=0;
	for(int i=0;i<N;i++)
	{
		if(l<M&&S[i]==T[l])l++;
		if(i<R[l])
		{
			int t=R[l]-i-1;
			if(ans<t)ans=t;
		}
	}
	printf("%d\n",ans);
}