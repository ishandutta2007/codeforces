//Author:mxh1999
//AC
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

#define maxn 100010
int n,m;
int num[maxn],sum[maxn];
int c[maxn],h,t,ans;

int main()
{
    scanf("%d",&n);
    t=0;h=1;
    for (int i=0;i<n;i++)
    {
        scanf("%d%d",&num[i],&sum[i]);
        if (num[i]==1)  c[++t]=i;
        ans+=num[i];
    }
    printf("%d\n",ans/2);
    while (h<=t)
    {
        if (num[c[h]]==1)
        {
            printf("%d %d\n",c[h],sum[c[h]]);
            num[sum[c[h]]]--,sum[sum[c[h]]]^=c[h];
            if (num[sum[c[h]]]==1)  c[++t]=sum[c[h]];
        }
        h++;
    }
    return 0;
}