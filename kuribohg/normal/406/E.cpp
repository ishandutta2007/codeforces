#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
typedef long long LL;
const int MAXN=300010;
int now;
LL n,m;
LL a[MAXN],con;
LL ans;
map<LL,int> M;
int main()
{
    scanf("%I64d%I64d",&n,&m);
    for(int i=1,x,y;i<=m;i++) scanf("%d%d",&x,&y),a[i]=(LL)(x+1)*(LL)n+(LL)y;
    sort(a+1,a+m+1);
    for(int i=m+1;i<=m+m;i++) a[i]=a[i-m]+n+n,M[a[i]]++,M[a[i-m]]++;
    ans=(LL)m*(LL)(m-1)*(LL)(m-2)/6LL;
    for(int i=1;i<=m;i++)
    {
        now=max(now,i);
        while(a[now+1]-a[i]<n) now++;
        if(now-1>i) con=max(con,a[now]-a[i]);
        ans-=(LL)(now-i)*(LL)(now-i-1)/2LL;
    }
    if(ans>0) {printf("%I64d\n",ans);return 0;}
    now=0,ans=0;
    for(int i=1;i<=m;i++)
    {
        now=max(now,i);
        while(a[now+1]-a[i]<n) now++;
        if(a[now]-a[i]!=con) continue;
        if(now-1<=i) continue;
        if(a[now]==a[i]) ans+=(LL)(now-i)*(LL)(now-1-i)/2LL;
        else ans+=(LL)M[a[now]]*(LL)(now-i-M[a[now]]),ans+=(LL)M[a[now]]*(LL)(M[a[now]]-1)/2LL;
    }
    printf("%I64d\n",ans);
    return 0;
}