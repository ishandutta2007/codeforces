#include<cstdio>
using namespace std;
int T,N;
char S[2][2<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%s%s",&N,S[0],S[1]);
		int id=0;
		bool out=false;
		for(int i=0;i<N;i++)
		{
			if(S[id][i]<='2');
			else
			{
				if(S[1-id][i]<='2')out=true;
				id=1-id;
			}
		}
		puts(out||id==0?"NO":"YES");
	}
}