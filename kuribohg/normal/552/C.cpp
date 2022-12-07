#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int w,m;
int main()
{
    scanf("%d%d",&w,&m);
    if(w==2) {puts("YES");return 0;}
    while(m)
    {
        int x=m%w;
        if(x>=2&&x<=w-2) break;
        if(x>=2) m++;
        m/=w;
    }
    if(m) puts("NO");
    else puts("YES");
    return 0;
}