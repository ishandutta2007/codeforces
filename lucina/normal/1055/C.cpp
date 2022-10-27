#include<stdio.h>
#include<algorithm>
using namespace std;
int ta,la,ra,tb,lb,rb,x,a;
int main(){
    scanf("%d%d%d%d%d%d",&la,&ra,&ta,&lb,&rb,&tb);
    int d =__gcd(ta,tb);
    x=((la-lb)%d+d)%d;
    a=max(min(rb-lb+1-x,ra-la+1),min(ra-la+1-d+x,rb-lb+1));
    if(a>0)
        printf("%d\n",a);
    else
        printf("0");
}