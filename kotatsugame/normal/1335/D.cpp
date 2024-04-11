#include<cstdio>
using namespace std;
int T;
char S[10];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		for(int i=0;i<9;i++)
		{
			scanf("%s",S);
			for(int j=0;j<9;j++)
			{
				if(S[j]=='9')S[j]='1';
			}
			puts(S);
		}
	}
}