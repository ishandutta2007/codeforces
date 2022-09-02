#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
using namespace std;

int a,b,c,d;

int main()
{
//  freopen("input.txt","r",stdin);
    scanf("%d%d%d%d",&a,&b,&c,&d);
    if(2*b==a+c && 2*c==b+d){
        printf("%d",2*d-c);
    }
    else if(b*b==a*c && c*c==b*d){
        if((d*d)%c!=0)printf("42");
        else printf("%d",d*d/c);
    }
    else printf("42");
    return 0;
}