#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2005;
int n,m;
int a[N],b[N],sa[N],sb[N],ta[N],tb[N];
pair<int,int> p[N];
ll x;
int main()
{
    memset(ta,0x3f,sizeof(ta));memset(tb,0x3f,sizeof(tb));
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),sa[i]=sa[i-1]+a[i];
    for(int i=1;i<=m;i++) scanf("%d",&b[i]),sb[i]=sb[i-1]+b[i];
    for(int i=1;i<=m;i++)
        for(int j=0;j<i;j++)
            tb[i-j]=min(tb[i-j],sb[i]-sb[j]);
    for(int i=1;i<=n;i++)
        for(int j=0;j<i;j++)     
            ta[i-j]=min(ta[i-j],sa[i]-sa[j]);
    scanf("%I64d",&x);int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if((ll)ta[i]*tb[j]<=x)
                ans=max(ans,i*j);
    printf("%d",ans);
    return 0;
}