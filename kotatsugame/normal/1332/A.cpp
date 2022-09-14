#include<cstdio>
using namespace std;
int T;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		int a,b,c,d,x,y,x1,y1,x2,y2;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		scanf("%d%d%d%d%d%d",&x,&y,&x1,&y1,&x2,&y2);
		bool ok=true;
		if(x-a+b<x1||x-a+b>x2)ok=false;
		if(-a+b==0&&(a!=0||b!=0)&&x1==x&&x==x2)ok=false;
		if(y-c+d<y1||y-c+d>y2)ok=false;
		if(-c+d==0&&(c!=0||d!=0)&&y1==y&&y==y2)ok=false;
		puts(ok?"YES":"NO");
	}
}