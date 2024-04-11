#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=100005;
int n;
ll ans,a[maxn];
int main()
{
    int i,j,T,cnt;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++) scanf("%lld",&a[i]);
        // cnto=cnt1=cnt2=0;
        // for(i=2;i<n;i++) cnto+=a[i]&1,cnt2+=(a[i]>=2),cnt1+=(a[i]>=1);
        // if(cnt==1 && !tag) { printf("-1\n"); continue; }
        // for(ans=0,i=2;i<n;i++) ans+=(a[i]+1)>>1;
        // printf("%lld\n",ans);
        ans=0;
        for(i=2;i<n;i++)
            if(a[i]&1)
                break;
        if(i<n)
        {
            for(j=2;j<n;j++)
                if(j!=i && a[j]>=2)
                    break;
            if(j<n)
                for(i=2;i<n;i++)
                    ans+=(a[i]+1)>>1;
            else
            {
                for(j=2;j<n;j++)
                    if(j!=i && a[i]>=2 && a[j]>=1)
                        break;
                if(j<n)
                    for(i=2;i<n;i++)
                        ans+=(a[i]+1)>>1;
                else if(n==3 || a[i]<=3) ans=-1;
                else ans=(a[i]+3)>>1;
            }
        }
        else
            for(i=2;i<n;i++) ans+=a[i]>>1;
        printf("%lld\n",ans);
    }
    return 0;
}