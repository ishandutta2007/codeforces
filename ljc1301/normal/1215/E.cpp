#include <bits/stdc++.h>
using namespace std;
#define lowbit(x) ((x)&-(x))
typedef long long ll;
const int maxa=20;
const int maxn=400005;
int n,a[maxn];
ll cnt[maxa][maxa],pre[maxa],s[maxa][(1<<maxa)|1],f[(1<<maxa)|1];
int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=0;i<maxa;i++) pre[i]=0;
    for(i=0;i<maxa;i++)
        for(j=0;j<(1<<maxa);j++)
            s[i][j]=0;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]),a[i]--;
        for(j=0;j<maxa;j++)
            s[a[i]][1<<j]+=pre[j];
        pre[a[i]]++;
    }
    for(i=0;i<maxa;i++)
        for(j=0;j<(1<<maxa);j++)
            if(lowbit(j)!=j)
                s[i][j]=s[i][j^lowbit(j)]+s[i][lowbit(j)];
    f[0]=0;
    for(i=1;i<(1<<maxa);i++)
        for(j=0,f[i]=0x7fffffffffffffffll;j<maxa;j++)
            if(i&(1<<j))
                f[i]=min(f[i],f[i^(1<<j)]+s[j][i^(1<<j)]);
    printf("%lld\n",f[(1<<maxa)-1]);
    return 0;
}