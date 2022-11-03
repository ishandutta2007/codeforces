#include <bits/stdc++.h>
using namespace std;
const int maxn=1000005;
typedef long long ll;
int w,a[maxn];
ll ans[maxn],t[maxn];
int q[maxn],he,ta;
int main()
{
    int i,m,T,x;
    scanf("%d%d",&T,&w);
    for(i=0;i<=w;i++) ans[i]=0,t[i]=0;
    while(T--)
    {
        scanf("%d",&m);
        for(i=1;i<=m;i++) scanf("%d",&a[i]); a[0]=0;
        if(2*m<=w)
        {
            for(i=1,x=0;i<=m;i++)
                ans[i]+=x=max(x,a[i]);
            for(i=w,x=0;i>=w-m+1;i--)
                ans[i]+=x=max(x,a[i-w+m]);
            t[m+1]+=x,t[w-m+1]-=x;
        }
        else
        {
            he=0,ta=-1;
            for(i=1;i<=w;i++)
            {
                while(he<=ta && i-q[he]+m>w) he++;
                if(i<=m)
                {
                    while(he<=ta && a[q[ta]]<a[i]) ta--;
                    q[++ta]=i;
                }
                if(i>m || i<=w-m) ans[i]+=max(0,a[q[he]]);
                else ans[i]+=a[q[he]];
            }
        }
    }
    for(i=2;i<=w;i++) t[i]+=t[i-1];
    for(i=1;i<=w;i++) printf("%lld ",ans[i]+t[i]);
    printf("\n");
    return 0;
}