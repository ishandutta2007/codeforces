#include<cstdio>
#include<cstring>
using namespace std;
int T,N;
char S[1<<17];
main()
{
	scanf("%d\n",&T);
	for(;T--;)
	{
		scanf("%s\n",S);
		N=strlen(S);
		int ans=0;
		for(int i=1;i<N;i++)
		{
			if(S[i-1]==S[i]||i>=2&&S[i-2]==S[i])
			{
				ans++;
				S[i]='?';
			}
		}
		printf("%d\n",ans);
	}
}