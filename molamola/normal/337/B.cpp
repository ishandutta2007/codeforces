#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
using namespace std;

inline int gc(int x,int y){return y?gc(y,x%y):x;}

void output(int x,int y)
{
    int g=gc(x,y);
    x/=g;
    y/=g;
    printf("%d/%d",y,x);
}

int main()
{
//  freopen("input.txt","r",stdin);
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    if(a*d>b*c)output(a*d,a*d-b*c);
    else if(a*d<b*c)output(b*c,b*c-a*d);
    else printf("0/1");
    return 0;
}