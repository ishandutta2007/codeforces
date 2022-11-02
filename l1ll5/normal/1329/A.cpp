#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 100005
#define int long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m;
int l[N];
int ans[N];
main()
{
    n=read(),m=read();
    int sum=0;
    for(int i=1;i<=m;i++) l[i]=read(),sum+=l[i];

    if(sum<n)
    {
        puts("-1");
        return 0;
    }

    ans[m]=1;

    sum-=l[m];

    int L=l[m];

    for(int i=m-1;i>=1;i--)
    {
        int tL=max(L-l[i]+2,1ll)+l[i]-1;
        if(sum-l[i]<n-tL)
        {
            tL=n-sum+l[i];
            ans[i]=tL-l[i]+1;
            L=tL;
            for(int j=i-1;j>=1;j--)
            {
                ans[j]=L+1;
                L+=l[i];
            }
            for(int j=1;j<=m;j++)
            {
                printf("%lld ",ans[j]);
            }
            return 0;
        }
        else
        {
            ans[i]=tL-l[i]+1;
            L=tL;
            sum-=l[i];
            if(L>n)
            {
                puts("-1");
                return 0;
            }
        }
    }
    for(int j=1;j<=m;j++)
    {
        printf("%lld ",ans[j]);
    }
}