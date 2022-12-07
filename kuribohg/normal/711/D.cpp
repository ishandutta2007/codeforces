#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MAXN=300010;
const int MOD=1000000007;
int n,p[MAXN],vis[MAXN],tot,t,ans=1;
bool used[MAXN];
LL qpow(LL x,LL n,LL MOD)
{
    LL con=1,p=x;
    while(n)
    {
        if(n&1) con=(con*p)%MOD;
        p=(p*p)%MOD;
        n>>=1;
    }
    return con;
}
int main()
{
    scanf("%d",&n);
    t=n;
    for(int i=1;i<=n;i++) scanf("%d",&p[i]);
    for(int i=1;i<=n;i++)
        if(!used[i])
        {
            int o=i,pre;
            while(!vis[o]) vis[o]=++tot,pre=o,o=p[o];
            if(pre==o) continue;
            if(!used[o])
            {
                ans=(LL)ans*(qpow(2,vis[pre]-vis[o]+1,MOD)+MOD-2)%MOD;
                t-=vis[pre]-vis[o]+1;
            }
            o=i;
            while(!used[o]) used[o]=true,o=p[o];
        }
    ans=(LL)ans*qpow(2,t,MOD)%MOD;
    printf("%d\n",ans);
    return 0;
}