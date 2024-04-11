#include<bits/stdc++.h>
using namespace std;

#define maxn 100010
int v1,v2,t,d;
int n;
int a[maxn];
int ans;

int main()
{
    scanf("%d%d",&v1,&v2);
    scanf("%d%d",&t,&d);
    a[t]=v2;
    for (int i=t-1;i>1;i--) a[i]=a[i+1]+d;
    int hzh=v1;
    ans=hzh;
    for (int i=2;i<=t;i++)
    {
        int mxh=hzh;
        hzh+=d;
        if (hzh>a[i])   hzh=a[i];
        ans+=hzh;
    }
    printf("%d\n",ans);
    return 0;
}