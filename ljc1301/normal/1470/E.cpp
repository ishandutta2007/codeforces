#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=30005;
const int maxk=8;
int n,k,a[maxn],t[maxk],tot;
ll f[maxk][maxn][2]; // determine <i, change <=j
// 0: cnt, 1: presum of #(a'[i+1] < a[i+1])
inline bool cmp(int x,int y) { return a[x]<a[y]; }
int main()
{
    int T,q,i,j,l,r,mid,y;
    ll x;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&k,&q);
        for(i=0;i<n;i++) scanf("%d",&a[i]);
        for(i=0;i<=k;i++) f[i][n][0]=1,f[i][n][1]=0;
        for(j=0;j<=k;j++)
            for(i=n-1;i>=0;i--)
            {
                f[j][i][0]=f[j][i][1]=0;
                for(l=0;l<=j && i+l<n;l++)
                {
                    f[j][i][0]+=f[j-l][i+l+1][0];
                    if(a[i]>a[i+l])
                        f[j][i][1]+=f[j-l][i+l+1][0];
                }
            }
        for(j=0;j<=k;j++)
            for(i=1;i<=n;i++)
                f[j][i][1]+=f[j][i-1][1];
        while(q--)
        {
            scanf("%d%lld",&y,&x),j=k,y--;
            if(x>f[k][0][0]) { printf("-1\n"); continue; }
            for(i=0;i<=y;)
            {
                // find same prefix
                l=i-1,r=y;
                while(l<r)
                {
                    mid=(l+r+1)>>1;
                    if(x>f[j][mid][1]-(i?f[j][i-1][1]:0) && x<=f[j][mid][1]-(i?f[j][i-1][1]:0)+f[j][mid+1][0]) l=mid;
                    else r=mid-1;
                }
                x-=((l>=0)?f[j][l][1]:0)-(i?f[j][i-1][1]:0),i=l+1;
                // fprintf(stderr,"! %d %d %lld %lld %lld\n",l,j,x,(f[j][i+1][1]-f[j][i][1]),f[j][i+1][0]);
                if(i>y) { printf("%d\n",a[y]); break; }
                for(tot=0,l=0;l<=j && i+l<n;l++)
                    t[tot++]=i+l;
                sort(t,t+tot,cmp);
                for(l=0;l<tot;l++)
                    if(x<=f[j-t[l]+i][t[l]+1][0])
                    {
                        // printf("reverse %d %d\n",i,t[l]);
                        if(y<=t[l]) printf("%d\n",a[t[l]+i-y]);
                        j-=t[l]-i,i=t[l]+1; break;
                    }
                    else x-=f[j-t[l]+i][t[l]+1][0];
                assert(l<tot);
            }
        }
    }
    return 0;
}