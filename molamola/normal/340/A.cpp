#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
using namespace std;

inline int gc(int x,int y){return y?gc(y,x%y):x;}

int main()
{
    int a,b,x,y;
    scanf("%d%d%d%d",&x,&y,&a,&b);
    int g=gc(x,y);
    int l=x*y/g;
    printf("%d",b/l-(a-1)/l);
    return 0;
}