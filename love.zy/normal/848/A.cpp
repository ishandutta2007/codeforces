#include<bits/stdc++.h>
using namespace std;

int n;

int cal(int x)
{
    for(int s=1;;s++)
        if(((s-1)*s)>>1>n)return s-1;
}

int main()
{
    scanf("%d",&n);
    if(n==0){printf("a\n");return 0;}
    for(int i=1;n>0;i++)
    {
        int t=cal(n);
        for(int j=1;j<=t;j++)printf("%c",96+i);
        n-=(t*(t-1))>>1;
    }
    return 0;
}