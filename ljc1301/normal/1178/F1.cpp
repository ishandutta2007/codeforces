#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int kcz=998244353;
const int maxn=505;
#define lowbit(x) ((x)&-(x))
int n,m,c[maxn],f[maxn][maxn];
inline ll dp(int l,int r)
{
    if(l==r+1) return 1;
    if(l>r) return 0;
    if(~f[l][r]) return f[l][r];
    if(l==r) return f[l][r]=1;
    ll a=0,b=0;
    int pos=l,i;
    for(i=l+1;i<=r;i++)
        if(c[i]<c[pos])
            pos=i;
    for(i=l;i<=pos;i++)
        a=(a+dp(l,i-1)*dp(i,pos-1))%kcz;
    for(i=r;i>=pos;i--)
        b=(b+dp(i+1,r)*dp(pos+1,i))%kcz;
    return f[l][r]=a*b%kcz;
}
int main()
{
    int i;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++) scanf("%d",&c[i]);
    memset(f,-1,sizeof(f));
    printf("%lld\n",dp(1,m));
    return 0;
}