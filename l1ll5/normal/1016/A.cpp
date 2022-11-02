#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 300000
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
#define int ll
int n,m;
int a[N];
main()
{
    n=read(),m=read();
    for(int i=1;i<=n;i++)a[i]=read();


    ll rem=m;
    for(int i=1;i<=n;i++)
    {
        int pag=0;
        if(a[i]<rem)rem-=a[i];
        else
        {
            pag=(a[i]-rem)/m+1  ;
            rem=pag*m-(a[i]-rem);
        }
        cout<<pag<<' ';
    }
}