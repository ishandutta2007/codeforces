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
int p[N][N];
int t[N],a[N],b[N];
int n,m;
int main()
{
    n=read(),m=read();
    for(int i=0;i<m;i++)
    {
        t[i]=read(),a[i]=read(),b[i]=read();
        if(t[i]==1)
        {
           for(int j=a[i];j<b[i];j++)p[j][j+1]=1;
        }
    }
    int book=0;
    for(int i=0;i<m;i++)
    {
        if(!t[i])
        {
            int flag2=0;
            for(int j=a[i];j<b[i];j++)
            {
                if(p[j][j+1]==0)
                {
                    flag2=1;
                }
            }
            if(!flag2)
            {
                book=1;
                break;
            }
        }
    }
    if(!book)
    {
        printf("YES\n");
        int tr=N;
        for(int i=1;i<=n;i++)
        {
            if(p[i-1][i]==0)tr--;
            printf("%d ",tr);
        }
        puts("");
    }
    else printf("NO\n");
}