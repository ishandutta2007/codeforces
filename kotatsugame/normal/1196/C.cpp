#include<cstdio>
#include<algorithm>
using namespace std;
int T,N;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		int LX=-1e5,RX=1e5,LY=-1e5,RY=1e5;
		for(int i=0;i<N;i++)
		{
			int x,y;
			int a,b,c,d;
			scanf("%d%d%d%d%d%d",&x,&y,&a,&b,&c,&d);
			if(a==0)LX=max(LX,x);
			if(b==0)RY=min(RY,y);
			if(c==0)RX=min(RX,x);
			if(d==0)LY=max(LY,y);
		}
		if(LX<=RX&&LY<=RY)
		{
			printf("1 %d %d\n",LX,LY);
		}
		else puts("0");
	}
}