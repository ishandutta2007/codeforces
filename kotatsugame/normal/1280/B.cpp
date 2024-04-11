#include<cstdio>
using namespace std;
int T;
int R,C;
char S[66][66];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&R,&C);
		for(int i=0;i<R;i++)scanf("%s",S[i]);
		int a=0,b=0,c=0,d=0,all=0;
		for(int i=0;i<R;i++)for(int j=0;j<C;j++)if(S[i][j]=='A')all++;
		for(int j=0;j<C;j++)
		{
			if(S[0][j]=='A')a++;
			if(S[R-1][j]=='A')b++;
		}
		for(int i=0;i<R;i++)
		{
			if(S[i][0]=='A')c++;
			if(S[i][C-1]=='A')d++;
		}
		bool fn=false;
		for(int i=0;i<R;i++)
		{
			bool now=true;
			for(int j=0;j<C;j++)if(S[i][j]!='A')now=false;
			if(now)fn=true;
		}
		for(int j=0;j<C;j++)
		{
			bool now=true;
			for(int i=0;i<R;i++)if(S[i][j]!='A')now=false;
			if(now)fn=true;
		}
		if(all==R*C)
		{
			puts("0");
		}
		else if(a==C||b==C||c==R||d==R)
		{
			puts("1");
		}
		else if(fn||S[0][0]=='A'||S[0][C-1]=='A'||S[R-1][0]=='A'||S[R-1][C-1]=='A')
		{
			puts("2");
		}
		else if(a||b||c||d)
		{
			puts("3");
		}
		else if(all)
		{
			puts("4");
		}
		else
		{
			puts("MORTAL");
		}
	}
}