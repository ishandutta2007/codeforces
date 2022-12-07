#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
int n,m,l,r;
LL d,a[310],b[310],t[310],f[2][300000],q[300000],ans=-1000000000000000000LL;
int main()
{
    scanf("%d%d%I64d",&n,&m,&d);
    for(int i=1;i<=m;i++) scanf("%I64d%I64d%I64d",&a[i],&b[i],&t[i]);
    t[0]=1;
    for(int i=1;i<=m;i++)
    {
        int now=i&1,pre=now^1;
        LL preR=0,L,R;
        l=1,r=0;
        for(int j=1;j<=n;j++)
        {
            L=max(1LL,(LL)j-(t[i]-t[i-1])*d);
            R=min((LL)n,(LL)j+(t[i]-t[i-1])*d);
            for(int k=preR+1;k<=R;k++)
            {
                while(r>=l&&f[pre][k]>=f[pre][q[r]]) r--;
                q[++r]=k;
            }
            while(l<r&&q[l]<L) l++;
            f[now][j]=f[pre][q[l]]+b[i]-abs(a[i]-j);
            preR=R;
        }
    }
    for(int i=1;i<=n;i++)
        ans=max(ans,f[m&1][i]);
    printf("%I64d\n",ans);
    return 0;
}