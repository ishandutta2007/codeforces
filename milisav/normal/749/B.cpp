#include <iostream>
#include <cstdio>
using namespace std;
int x1,y1,x2,y2,x3,y3;
int x4,y4;
int main()
{
	scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3);
	printf("3\n");
	printf("%d %d\n",x3+x2-x1,y3+y2-y1);
	printf("%d %d\n",x3+x1-x2,y3+y1-y2);
	printf("%d %d\n",x1+x2-x3,y1+y2-y3);
	return 0;
}