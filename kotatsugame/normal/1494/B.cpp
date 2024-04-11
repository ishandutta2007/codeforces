#include<cstdio>
using namespace std;
int N,A,B,C,D;
main()
{
	int T;
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d%d%d%d",&N,&A,&B,&C,&D);
		bool fn=false;
		for(int k=0;k<1<<4;k++)
		{
			int a=A,b=B,c=C,d=D;
			if(k&1)a--,b--;
			if(k&2)b--,c--;
			if(k&4)c--,d--;
			if(k&8)d--,a--;
			if(0<=a&&a<=N-2&&0<=b&&b<=N-2&&
				0<=c&&c<=N-2&&0<=d&&d<=N-2)fn=true;
		}
		puts(fn?"YES":"NO");
	}
}