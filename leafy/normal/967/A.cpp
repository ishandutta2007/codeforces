#include<iostream>
#include<cstdio>
using namespace std;
int n,s;
int t[105];
int main()
{
    scanf("%d%d",&n,&s);
    int h,m;
    for(int i=1;i<=n;i++)
        scanf("%d%d",&h,&m),t[i]=h*60+m;
    if(t[1]>=s+1) {puts("0 0");return 0;}
    int ti;
    for(int i=1;i<n;i++)
    {
        if(t[i+1]-t[i]>=2*s+2)
        {
            ti=t[i]+s+1;
            printf("%d %d",ti/60,ti%60);
            return 0;
        }
    }
    ti=t[n]+s+1;
    printf("%d %d",ti/60,ti%60);
    return 0;
}