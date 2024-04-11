#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 1005
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,a,b;
bool flag;
int f[N][N];
int main()
{
    n=read(),a=read(),b=read();
    if(a!=1&&b!=1)
    {
        puts("NO");
        return 0;
    }
    if(a==1&&b==1)
    {
        if(n<=3)
        {
            if(n==1)
            {
                puts("YES");
                puts("0");
                return 0;
            }
            puts("NO");
            return 0;
        }
        for(int i=1;i<n;i++)f[i][i+1]=f[i+1][i]=1;
        puts("YES");
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            printf("%d",f[i][j]);
            puts("");
        }
        return 0;
    }
    if(a==1)swap(a,b),flag=1;

    for(int i=1;i<=n;i++)
    for(int j=1;j<i;j++)
    {
        if(j<=a-1||i<=a-1)f[i][j]=f[j][i]=0;
        else f[i][j]=f[j][i]=1;
    }
    if(flag)
    {
        for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        if(i!=j)f[i][j]^=1;
    }
    puts("YES");
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        printf("%d",f[i][j]);
        puts("");
    }
}