#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 305
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int t;
int n,m;
int a[N][N];
int b[N][N];
int main()
{
    t=read();
    while(t--)
    {
        n=read(),m=read();
        for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            a[i][j]=read();
        }
        for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            b[i][j]=4;
        }
        for(int i=1;i<=m;i++)
        b[1][i]--,b[n][i]--;

        for(int i=1;i<=n;i++)
        b[i][1]--,b[i][m]--;

        bool over=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(a[i][j]>b[i][j])
                {
                    over=1;
                    break ;
                }
            }
            if(over) break ;
        }
        if(over)
        {
            puts("NO");
            continue ;
        }
        else{
            puts("YES");
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++)
                printf("%d ",b[i][j]);
                puts("");
            }
        }
    }
}