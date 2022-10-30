#include <stdio.h>
#include <algorithm>
using namespace std;

int A,B,sx,sy,ex,ey;

int divi(int a,int b)
{
    if (a < 0){
        return -((abs(a)-1)/b+1);
    }else return a/b;
}

int main()
{
    scanf("%d%d%d%d%d%d",&A,&B,&sx,&sy,&ex,&ey);
    int sa=divi(sx+sy,A+A);
    int sb=divi(sy-sx,B+B);
    int ea=divi(ex+ey,A+A);
    int eb=divi(ey-ex,B+B);
    printf("%d",max(abs(sa-ea),abs(sb-eb)));
}