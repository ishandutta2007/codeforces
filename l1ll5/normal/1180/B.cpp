#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 100010
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n;
int ans;
int a[N];
int mx,mxid;
int main()
{
    n=read();
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=1;i<=n;i++)
    {
        if(a[i]>=0)a[i]=-a[i]-1;
    }
    int neg=0;
    for(int i=1;i<=n;i++)
    if(a[i]<0)neg++;
    if(neg&1)
    {
        int mn=9999999,mnid=0;
        for(int i=1;i<=n;i++)
        if(a[i]<mn)
        {
            mn=a[i];mnid=i;
        }
        a[mnid]=-a[mnid]-1;
    }
    for(int i=1;i<=n;i++)
    printf("%d ",a[i]);
}
/*
-20 -1 5
19 -1 -6
*/