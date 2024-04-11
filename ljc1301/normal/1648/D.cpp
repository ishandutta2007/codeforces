#include <bits/stdc++.h>
using namespace std;
// sr+sr-sl+sl -> sl+sr
// r, l
// [l,r]->connect l-1~r
// l: 0~n-1, r:0~n-1
typedef long long ll;
const ll ninf=0xc000000000000000ll;
const int maxn=500005;
const int maxm=500005;
struct node
{
    int l,r; ll w;
    inline bool operator <(const node &p) const { return l<p.l; }
}p[maxm];
ll ans,a[maxn],s[maxn],t[maxn],tr[maxn<<2][2],tagm[maxn<<2],tag[maxn<<2];
int n,m;
void build(int rt,int l,int r)
{
    tagm[rt]=tag[rt]=ninf,tr[rt][1]=ninf;
    if(l==r) { tr[rt][0]=s[l]; return; }
    int mid=(l+r)>>1;
    build(rt<<1,l,mid),build((rt<<1)|1,mid+1,r),tr[rt][0]=max(tr[rt<<1][0],tr[(rt<<1)|1][0]);
}
inline void pushup(int rt) { tr[rt][1]=max(ninf,max(tr[rt<<1][1],tr[(rt<<1)|1][1])); }
inline void pushmax(int rt,ll z) { tagm[rt]=max(tagm[rt],z),tr[rt][1]=max(tr[rt][1],z); }
inline void push(int rt,/*int l,int r,*/ll z)
{
    // if(l==r) return;
    tag[rt]=max(tag[rt],z);
}
inline void pushdown(int rt/*,int l,int r,int mid*/)
{
    if(tagm[rt]>ninf) pushmax(rt<<1,tagm[rt]),pushmax((rt<<1)|1,tagm[rt]),tagm[rt]=ninf;
    if(tag[rt]>ninf)
    {
        push(rt<<1,/*l,mid,*/tag[rt]),push((rt<<1)|1,/*mid+1,r,*/tag[rt]);
        pushmax((rt<<1)|1,max(ninf,max(tr[rt<<1][0],tr[rt<<1][1])+tag[rt]));
        tag[rt]=ninf;
    }
}
ll update(int rt,int l,int r,int x,int y,ll z,ll t)
{
    if(x<=l && r<=y) { pushmax(rt,t),push(rt,/*l,r,*/z); return max(tr[rt][0],tr[rt][1]); }
    int mid=(l+r)>>1; ll res=ninf;
    pushdown(rt/*,l,r,mid*/);
    if(x<=mid) res=update(rt<<1,l,mid,x,y,z,t);
    if(mid<y) res=max(res,update((rt<<1)|1,mid+1,r,x,y,z,max(t,res+z)));
    pushup(rt);
    return res;
}
void query(int rt,int l,int r)
{
    if(l==r) { /*printf("%lld ",tr[rt][1]),*/t[l]+=tr[rt][1]; return; }
    int mid=(l+r)>>1;
    pushdown(rt/*,l,r,mid*/),query(rt<<1,l,mid),query((rt<<1)|1,mid+1,r);
}
int main()
{
    int i;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++) scanf("%lld",&a[i]),s[i]=(i?s[i-1]:0)+a[i];
    for(i=1,a[0]=0;i<=n;i++) scanf("%lld",&a[i]),a[i]+=a[i-1],s[i-1]-=a[i-1],t[i]=a[i];
    for(i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(a[n+1]=0,i=n;i;i--) t[i]+=(a[i]+=a[i+1]);
    // for(i=0;i<n;i++) printf("%lld ",s[i]); printf("\n");
    // for(i=1;i<=n;i++) printf("%lld ",t[i]); printf("\n");
    s[n]=t[0]=ninf,build(1,0,n);
    for(i=0;i<m;i++) scanf("%d%d%lld",&p[i].l,&p[i].r,&p[i].w);
    sort(p,p+m);
    for(i=0;i<m;i++) update(1,0,n,p[i].l-1,p[i].r,-p[i].w,ninf);
    query(1,0,n);
    for(ans=ninf,i=1;i<=n;i++) ans=max(ans,t[i]);
    printf("%lld\n",ans);
    return 0;
}