#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=200005;
struct mos
{
    int x,y;
    ll z;
    inline bool operator <(const mos &m) const { return x<m.x; }
}c[maxn];
pair<int,ll> a[maxn],b[maxn];
int n,m,p,bs[maxn<<1],tot;
ll tr[maxn<<3],lazy[maxn<<3],id[maxn<<1];
inline void push(int rt,ll z) { lazy[rt]+=z,tr[rt]+=z; }
inline void pushup(int rt) { tr[rt]=max(tr[rt<<1],tr[(rt<<1)|1]); }
inline void pushdown(int rt) { if(lazy[rt]) push(rt<<1,lazy[rt]),push((rt<<1)|1,lazy[rt]),lazy[rt]=0; }
void build(int rt,int l,int r)
{
    lazy[rt]=0;
    if(l==r) { tr[rt]=id[l]; return; }
    int mid=(l+r)>>1;
    build(rt<<1,l,mid),build((rt<<1)|1,mid+1,r);
    pushup(rt);
}
void update(int rt,int l,int r,int x,int y,ll z)
{
    if(x<=l && r<=y) { push(rt,z); return; }
    int mid=(l+r)>>1;
    pushdown(rt);
    if(x<=mid) update(rt<<1,l,mid,x,y,z);
    if(mid<y) update((rt<<1)|1,mid+1,r,x,y,z);
    pushup(rt);
}
// ll query(int rt,int l,int r,int x,int y)
// {
//     if(x<=l && r<=y) return tr[rt];
//     int mid=(l+r)>>1;
//     ll res=-0x3fffffffffffffffll
//     pushdown(rt);
//     if(x<=mid) res=max(res,query(rt<<1,l,mid,x,y));
//     if(mid<y) res=max(res,query((rt<<1)|1,mid+1,r,x,y));
//     return res;
// }
int main()
{
    int i,j;
    ll ans=-0x3fffffffffffffffll;
    scanf("%d%d%d",&n,&m,&p);
    tot=0;
    for(i=0;i<n;i++) scanf("%d%lld",&a[i].first,&a[i].second);
    for(i=0;i<m;i++) scanf("%d%lld",&b[i].first,&b[i].second),bs[tot++]=b[i].first;
    for(i=0;i<p;i++) scanf("%d%d%lld",&c[i].x,&c[i].y,&c[i].z),bs[tot++]=c[i].y;
    sort(bs,bs+tot),tot=unique(bs,bs+tot)-bs;
    sort(a,a+n);
    sort(c,c+p);
    for(i=0;i<tot;i++) id[i]=-0x3fffffffffffffffll;
    for(i=0;i<m;i++)
        b[i].first=lower_bound(bs,bs+tot,b[i].first)-bs,id[b[i].first]=max(id[b[i].first],-b[i].second);
    build(1,0,tot-1);
    for(i=0,j=0;i<n;i++)
    {
        while(j<p && c[j].x<a[i].first)
        {
            c[j].y=lower_bound(bs,bs+tot,c[j].y)-bs;
            if(c[j].y+1<tot) update(1,0,tot-1,c[j].y+1,tot-1,c[j].z);
            j++;
        }
        ans=max(ans,tr[1]-a[i].second);
    }
    printf("%lld\n",ans);
    return 0;
}