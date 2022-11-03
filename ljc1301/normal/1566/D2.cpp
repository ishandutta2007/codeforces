#include <bits/stdc++.h>
using namespace std;
const int maxk=100000;
const int maxm=305;
int n,m,k,a[maxk],b[maxk],cnt,sz[maxk];
int tr[maxm][maxm];
queue<pair<int,int> > que[maxk];
#define lowbit(x) ((x)&-(x))
inline void update(int i,int x)
{
    for(;x<=m;x+=lowbit(x))
        tr[i][x]++;
}
inline int query(int i,int x)
{
    int res=0;
    for(;x;x-=lowbit(x))
        res+=tr[i][x];
    return res;
}
int main()
{
    int T,i,j,l,r,t;
    long long ans;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m),k=n*m;
        for(i=0;i<k;i++) scanf("%d",&a[i]),b[i]=a[i];
        sort(b,b+k),cnt=unique(b,b+k)-b;
        for(i=0;i<cnt;i++) { sz[i]=0; while(!que[i].empty()) que[i].pop(); }
        for(i=0;i<k;i++) a[i]=lower_bound(b,b+cnt,a[i])-b,sz[a[i]]++;
        for(l=0,i=0;i<k;l=r+1,i++)
        {
            r=l+sz[i]-1;
            for(j=l/m;j<=r/m;j++)
                for(t=min(j*m+m-1,r);t>=max(j*m,l);t--)
                    que[i].push(make_pair(t/m,t%m));
        }
        for(i=0;i<n;i++)
            for(j=1;j<=m;j++)
                tr[i][j]=0;
        ans=0;
        for(i=0;i<k;i++)
        {
            j=que[a[i]].front().first,t=que[a[i]].front().second+1;
            que[a[i]].pop();
            ans+=query(j,t),update(j,t);
        }
        printf("%lld\n",ans);
    }
    return 0;
}