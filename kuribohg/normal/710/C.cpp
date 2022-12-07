#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
using namespace std;
int n,a[50][50],x,y;
int main()
{
    scanf("%d",&n);
    y=-1;
    int c=(n+1)/2;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(j<=abs(c-i)) x+=2,a[i][j]=x;
            else if(j>n-abs(c-i)) x+=2,a[i][j]=x;
            else y+=2,a[i][j]=y;
        }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            printf("%d ",a[i][j]);
        puts("");
    }
    return 0;
}