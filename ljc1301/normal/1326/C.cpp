#include <bits/stdc++.h>
using namespace std;
const int kcz=998244353;
const int maxn=200005;
int n,k,a[maxn],pos[maxn],t[maxn];
int main()
{
    int i;
    long long ans;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++) scanf("%d",&a[i]),pos[a[i]]=i;
    ans=0;
    for(i=0;i<k;i++) ans+=n-i;
    printf("%lld ",ans);
    for(i=0;i<k;i++) t[i]=pos[n-i];
    sort(t,t+k);
    ans=1;
    for(i=1;i<k;i++)
        ans=ans*(t[i]-t[i-1])%kcz;
    printf("%lld\n",ans);
    return 0;
}