#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
using namespace std;

int main()
{
//  freopen("input.txt","r",stdin);
    bool a=0,b=0;
    int c,d;
    scanf("%d%d",&c,&d);
    if(c<0){a=1;c=-c;}
    if(d<0){b=1;d=-d;}
    int e=c+d;
    if(a&b){
        printf("%d 0 0 %d",-e,-e);
    }
    else if(a){
        printf("%d 0 0 %d",-e,e);
    }
    else if(a^b){
        printf("0 %d %d 0",-e,e);
    }
    else printf("0 %d %d 0",e,e);
    return 0;
}