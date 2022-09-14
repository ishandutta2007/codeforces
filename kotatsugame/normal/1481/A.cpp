#include<cstdio>
using namespace std;
int T,X,Y;
char S[1<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d%s",&X,&Y,S);
		int u=0,l=0,d=0,r=0;
		for(int i=0;S[i];i++)
		{
			if(S[i]=='U')u++;
			else if(S[i]=='L')l++;
			else if(S[i]=='D')d++;
			else r++;
		}
		puts(-l<=X&&X<=r&&-d<=Y&&Y<=u?"YES":"NO");
	}
}