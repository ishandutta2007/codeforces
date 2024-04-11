#include<cstdio>
#include<string>
using namespace std;
int T,N,M;
char S[10][15];
string ok[11][1<<10];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&M);
		for(int i=0;i<N;i++)scanf("%s",S[i]);
		ok[0][0]="";
		for(int i=0;i<M;i++)
		{
			for(int j=0;j<1<<N;j++)ok[i+1][j]="";
			for(char c='a';c<='z';c++)
			{
				int now=0;
				for(int j=0;j<N;j++)if(S[j][i]!=c)now|=1<<j;
				for(int k=0;k<1<<N;k++)if(!(k&now)&&ok[i][k].size()==i)
				{
					ok[i+1][k|now]=ok[i][k]+c;
				}
			}
		}
		string ans="";
		for(int i=0;i<1<<N;i++)if(ok[M][i].size()==M)ans=ok[M][i];
		if(ans.empty())puts("-1");
		else puts(ans.c_str());
	}
}