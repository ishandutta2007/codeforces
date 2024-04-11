#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=200005;
const ll inf=0x3fffffffffffffffll;
struct segment
{
    int l,r;
    inline bool operator <(const segment &s) const
    {
        return (r!=s.r)?r<s.r:(l>s.l);
    }
}s[maxn];
int n,m,a[maxn],temp[maxn],p[maxn];
ll f[maxn];
int main()
{
    int T,i,j,t;
    ll min1,min2;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++) scanf("%d",&a[i]);
        sort(a,a+n);
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&s[i].l,&s[i].r);
            t=lower_bound(a,a+n,s[i].l)-a;
            if(t<n && a[t]<=s[i].r) i--,m--;
        }
        if(!m) { printf("0\n"); continue; }
        sort(s,s+m);
        t=m,temp[0]=0,m=1;
        for(i=1;i<t;i++)
            if(s[i].l>s[temp[m-1]].l)
                temp[m++]=i;
        for(i=0;i<m;i++) s[i]=s[temp[i]];
        for(i=m;i>=1;i--) s[i]=s[i-1];
        for(i=n;i>=1;i--) a[i]=a[i-1];
        // for(i=1;i<=n;i++) printf("%d ",a[i]); printf("\n");
        // for(i=1;i<=m;i++) printf("[%d, %d] ",s[i].l,s[i].r); printf("\n");
        p[0]=1;
        for(i=1,j=1;j<=m && i<=n;j++)
            // if(s[j].l>a[i])
            //     p[i++]=j;
            while(i<=n && s[j].l>a[i])
                p[i++]=j;
        for(;i<=n+1;i++) p[i]=m+1;
        // for(i=1;i<=n;printf("%d ",a[i]),i++)
        //     for(j=p[i-1];j<p[i];j++)
        //         printf("[%d, %d] ",s[j].l,s[j].r);
        // for(j=p[n];j<=m;j++) printf("[%d, %d] ",s[j].l,s[j].r);
        // printf("\n");
        for(i=1,f[0]=0;i<=m;i++) f[i]=inf;
        for(i=1;i<=n;i++)
        {
            min1=min2=f[p[i]-1];
            // f+(-x)+() f+2(-x)
            for(j=p[i-1]-1;j<p[i]-1;j++)
            {
                min1=min(min1,f[j]+a[i]-s[j+1].r);
                min2=min(min2,f[j]+(a[i]-(ll)s[j+1].r)*2ll);
            }
            for(j=p[i];j<p[i+1];j++)
                f[j]=min(min1+2ll*(s[j].l-(ll)a[i]),min2+s[j].l-(ll)a[i]);
            f[p[i]-1]=min1;
            // for(j=p[i]-1;j<p[i+1];j++) printf("%lld ",f[j]); printf("\n");
        }
        printf("%lld\n",f[m]);
    }
    return 0;
}