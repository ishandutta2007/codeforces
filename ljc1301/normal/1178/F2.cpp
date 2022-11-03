#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int kcz=998244353;
const int maxn=505;
const int maxm=1000005;
#define lowbit(x) ((x)&-(x))
int n,m,c[maxm],f[maxn<<2][maxn<<2],l[maxn],r[maxn];
inline ll dp(int L,int R)
{
    if(L==R+1) return 1;
    if(L>R) return 0;
    if(~f[L][R]) return f[L][R];
    if(L==R) return f[L][R]=(l[c[L]]==L && r[c[R]]==R);
    ll a=0,b=0;
    int pos=L,i,j;
    for(i=L+1;i<=R;i++)
        if(c[i]<c[pos])
            pos=i;
    if(l[c[pos]]<L || r[c[pos]]>R) return f[L][R]=0;
    for(i=L;i<=l[c[pos]];i++)
        if(i==l[c[pos]] || l[c[i]]==i)
            a=(a+dp(L,i-1)*dp(i,l[c[pos]]-1))%kcz;
    for(i=R;i>=r[c[pos]];i--)
        if(i==r[c[pos]] || r[c[i]]==i)
            b=(b+dp(i+1,R)*dp(r[c[pos]]+1,i))%kcz;
    f[L][R]=a*b%kcz;
    for(i=pos;i!=r[c[pos]];)
    {
        j=i,i++;
        while(c[i]!=c[pos]) i++;
        f[L][R]=f[L][R]*dp(j+1,i-1)%kcz;
    }
    return f[L][R];
}
int main()
{
    int i,j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++) l[i]=m+1,r[i]=0;
    for(i=1;i<=m;i++) scanf("%d",&c[i]);
    m=unique(c+1,c+1+m)-c-1;
//    for(i=1;i<=m;i++) printf("%d ",c[i]);
//    printf("\n");
    for(i=1;i<=m;i++) l[c[i]]=min(l[c[i]],i),r[c[i]]=max(r[c[i]],i);
    for(i=1;i<=n;i++)
        for(j=1;j<i;j++)
            if(!(r[i]<l[j] || (l[j]<l[i] && r[i]<r[j]) || r[j]<l[i]))
            {
                printf("0\n");
                return 0;
            }
    memset(f,-1,sizeof(f));
    printf("%lld\n",dp(1,m));
    return 0;
}