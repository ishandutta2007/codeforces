#include<cstdio>
#include<cstring>
using namespace std;
int T,N;
char S[1<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%s",S);
		N=strlen(S);
		bool ok=true;
		for(int i=0;i<N;i++)
		{
			if(S[i]=='?')
			{
				int t=0;
				if(i>0)t|=1<<S[i-1]-'a';
				if(i+1<N&&S[i+1]!='?')t|=1<<S[i+1]-'a';
				if(t&1)
				{
					if(t&2)S[i]='c';
					else S[i]='b';
				}
				else S[i]='a';
			}
			else if(i+1<N&&S[i]==S[i+1])
			{
				ok=false;
			}
		}
		puts(ok?S:"-1");
	}
}