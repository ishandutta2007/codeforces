#include<bits/stdc++.h>
#define MAXN 10005
#define MAXM 5000005
#define reg register
#define inl inline
#define inf 2147483647
#define int long long
using namespace std;
int n,k,p,a[MAXN],b[MAXN],ans;
bool fg[MAXN];
template <typename T> inl void Read(reg T &x)
{
    x=0;
    reg int fu=1;
    reg char ch=getchar();
    for(;!isdigit(ch);ch=getchar()) if(ch=='-') fu=-1;
    for(;isdigit(ch);ch=getchar()) x=(x<<3)+(x<<1)+(ch-48);
    x*=fu;
}
inl bool Check(reg int mid)
{
    memset(fg,0,sizeof(fg));
    for(reg int i=1;i<=n;i++)
    {
        if(a[i]<=p)
        {
            reg int cnt=-1;
            for(reg int j=1;j<=k;j++)
            {
                if(!fg[j] && abs(a[i]-b[j])+abs(b[j]-p)<=mid)
                {
                    cnt=j;
                    break;
                }
            }
            if(cnt==-1) return 0;
            fg[cnt]=1;
        }
        else break;
    }
    for(reg int i=n;i>=1;i--)
    {
        if(a[i]>p)
        {
            reg int cnt=-1;
            for(reg int j=k;j>=1;j--)
            {
                if(!fg[j] && abs(a[i]-b[j])+abs(b[j]-p)<=mid)
                {
                    cnt=j;
                    break;
                }
            }
            if(cnt==-1) return 0;
            fg[cnt]=1;
        }
        else break;
    }
    return 1;
}
signed main()
{
    Read(n);
    Read(k);
    Read(p);
    for(reg int i=1;i<=n;++i) Read(a[i]);
    for(reg int i=1;i<=k;++i) Read(b[i]);
    sort(a+1,a+n+1);
    sort(b+1,b+k+1);
    reg int l=0,r=2e9;
    while(l<=r)
    {
        reg int mid=l+r>>1;
        if(Check(mid))
        {
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    printf("%lld\n",ans);
    return 0;
}