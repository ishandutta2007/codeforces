#include<bits/stdc++.h>
using namespace std;

int n,m;

int main()
{
    scanf("%d%d",&n,&m);
    if(n==2 && m==0){printf("NO\n");return 0;}
    if(n%4==2 && m==0)
    {
        printf("YES\n");
        for(int i=100004;i<=100004+n-7;i++)printf("%d ",i);
        printf("1 2 4 8 16 31\n");
        return 0;
    }
    int t=n/4;
    n%=4;
    if(n==0)n=4,t--;
    printf("YES\n");
    for(int i=100004;i<=100004+t*4-1;i++)printf("%d ",i);
    if(n==1)printf("%d\n",m);
    if(n==2)printf("0 %d\n",m);
    if(n==3)
    {
        if(m==0)printf("1 2 3\n");
        if(m==1)printf("0 2 3\n");
        if(m==2)printf("0 1 3\n");
        if(m==3)printf("0 1 2\n");
        if(m>3)printf("2 3 %d\n",m^1);
    }
    if(n==4)
    {
        if(m==0)printf("1 2 3 0\n");
        if(m==1)printf("0 3 4 6\n");
        if(m==3)printf("0 1 4 6\n");
        if(m==2)printf("1 2 4 5\n");
        if(m>3)printf("0 2 3 %d\n",m^1);
    }
    return 0;
}