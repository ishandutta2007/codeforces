#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
int T;
LL n,fac[12];
pair<LL,int> x[1<<12];
int bitcount(LL x)
{
    int ans=0;
    for(int i=50;i>=0;i--)
        if(x&(1LL<<i)) ans++;
    return ans;
}
int main()
{
    scanf("%d",&T);
    fac[0]=6;
    for(int i=1;i<12;i++) fac[i]=fac[i-1]*(i+3);
    for(int i=0;i<(1<<12);i++)
    {
        for(int k=0;k<12;k++)
            if(i&(1<<k)) x[i].first+=fac[k],x[i].second++;
    }
    while(T--)
    {
        scanf("%I64d",&n);
        int ans=1000000;
        for(int i=0;i<(1<<12);i++)
            if(n>=x[i].first)
            {
                int o=x[i].second+bitcount(n-x[i].first);
                ans=min(ans,o);
            }
        printf("%d\n",ans);
    }
    return 0;
}