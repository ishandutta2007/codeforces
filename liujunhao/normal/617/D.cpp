#include<cstdio>
#include<algorithm>
#include<cstdlib>
using namespace std;
int x1,y1,x2,y2,x3,y3;
int main()
{
	scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
	if(x1==x2&&x1==x3||y1==y2&&y1==y3){
		puts("1");
		return 0;
	}
	if((x1==x2&&(y1==y3||y2==y3))||(x2==x3&&(y1==y3||y2==y1))||(x1==x3&&(y2==y3||y2==y1))||(y1==y2&&(x1==x3||x2==x3))||(y1==y3&&(x1==x2||x2==x3))||(y2==y3&&(x1==x2||x1==x3))){
		puts("2");
		return 0;
	}
	if(x1>x2)
		swap(x1,x2),swap(y1,y2);
	if(x1>x3)
		swap(x1,x3),swap(y1,y3);
	if(x2>x3)
		swap(x2,x3),swap(y2,y3);
	if(y1==y2||y2==y3){
		puts("2");
		return 0;
	}
	if(y1>y2)
		swap(x1,x2),swap(y1,y2);
	if(y1>y3)
		swap(x1,x3),swap(y1,y3);
	if(y2>y3)
		swap(x2,x3),swap(y2,y3);
	if(x1==x2||x2==x3){
		puts("2");
		return 0;
	}
	puts("3");
}