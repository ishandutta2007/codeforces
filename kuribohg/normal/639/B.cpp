#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,h,d,x;
int main()
{
    scanf("%d%d%d",&n,&d,&h);
    if(d>h+h) puts("-1");
    else
    {
        if(n>=3&&d==1) {puts("-1");return 0;}
        x=2;
        for(int i=1;i<=h;i++)
            printf("%d %d\n",x-1,x),x++;
        for(int i=1;i<=d-h;i++)
            printf("%d %d\n",i==1?1:x-1,x),x++;
        for(int i=x;i<=n;i++)
            printf("%d %d\n",h==d?2:1,i);
    }
    return 0; 
}