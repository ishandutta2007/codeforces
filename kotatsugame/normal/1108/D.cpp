#include<cstdio>
using namespace std;
int N;
char S[2<<17];
main()
{
	scanf("%d%s",&N,S);
	int ans=0;
	for(int i=1;i<N;i++)
	{
		if(S[i-1]==S[i])
		{
			ans++;
			if(i+1<N&&S[i-1]!=S[i+1])
			{
				S[i]='R'+'G'+'B'-S[i-1]-S[i+1];
			}
			else
			{
				S[i]=S[i-1]=='R'?'G':'R';
			}
		}
	}
	printf("%d\n%s\n",ans,S);
}