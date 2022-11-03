#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int kcz=998244353;
const int maxa=100005;
int n,m[2],cur,v[2][maxa]; // increasing >=v ans=f cnt=g
ll ans,f[2][maxa]/*,g[2][maxa]*/;
int main()
{
    int T,a,i,l,r,lb,rb,k;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        ans=0,cur=0,m[cur]=1,f[cur][0]=/*g[cur][0]=*/0,v[cur][0]=0;
        // while(n--)
        for(k=1;k<=n;k++)
        {
            cur^=1,m[cur]=0,scanf("%d",&a);
            // i=upper_bound(v[cur^1],v[cur^1]+m[cur^1],a)-v[cur^1];
            // /*if(i) */i--,(ans+=f[cur^1][i])%=kcz;
            for(r=a,i=0;r>=1;r=l-1)
            {
                // lb=a/r,rb=(a+r-1)/r;
                // if(lb==rb) l=r;
                // else l=(a-1+lb-1)/lb; // cnt*lb+1>=a
                rb=(a+r-1)/r;
                l=(a+rb-1)/rb,lb=(a%rb)?rb-1:rb;
                // printf("%d %d %d %d\n",lb,rb,l,r);
                assert(l<=r);
                assert((l-1)*lb+rb<=a && (l-1)*rb+lb>=a);
                v[cur][m[cur]]=rb;
                while(i+1<m[cur^1] && v[cur^1][i+1]<=lb) i++;
                // g[cur][m[cur]]=(g[cur^1][i]+1)%kcz;
                f[cur][m[cur]]=(f[cur^1][i]+/*g[cur][i]*/k*(l-1ll))%kcz;
                // printf("%d %lld %lld\n",v[cur][m[cur]],g[cur][m[cur]],f[cur][m[cur]]);
                m[cur]++;
            }
            (ans+=f[cur][m[cur]-1])%=kcz;
        }
        printf("%lld\n",ans%kcz);
    }
    return 0;
}