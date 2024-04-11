#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; // min,cnt
const int maxn=120005;
const int maxm=120005;
struct querys
{
    int l,r,id;
    inline bool operator <(const querys &q) const
    {
        return r<q.r;
    }
}q[maxm];
int n,m,a[maxn],sta[2][maxn],top[2],tag[maxn<<2],tagcnt[maxn<<2];
ll ans[maxm],s[maxn<<2],tags[maxn<<2];
pii tr[maxn<<2];
inline pii operator +(const pii &a,const pii &b)
{
    return make_pair(min(a.first,b.first),((a.first<=b.first)?a.second:0)+((b.first<=a.first)?b.second:0));
}
// max-min+l=r (max-min+l>=r)
inline void push(int rt,int x) { tag[rt]+=x,tr[rt].first+=x; }
inline void pushans(int rt,int a,ll b) { tagcnt[rt]+=a,tags[rt]+=b,s[rt]+=a+b; }
inline void pushup(int rt) { tr[rt]=tr[rt<<1]+tr[(rt<<1)|1]; }
inline void pushdown(int rt)
{
    if(tag[rt]) push(rt<<1,tag[rt]),push((rt<<1)|1,tag[rt]),tag[rt]=0;
    if(tagcnt[rt] || tags[rt])
    {
        pushans(rt<<1,(tr[rt<<1].first==tr[rt].first)?tagcnt[rt]:0,tags[rt]+tagcnt[rt]*(ll)((tr[(rt<<1)|1].first==tr[rt].first)?tr[(rt<<1)|1].second:0));
        pushans((rt<<1)|1,(tr[(rt<<1)|1].first==tr[rt].first)?tagcnt[rt]:0,tags[rt]);
        tagcnt[rt]=tags[rt]=0;
    }
}
void build(int rt,int l,int r)
{
    tag[rt]=tagcnt[rt]=tags[rt]=0;
    if(l==r) { tr[rt]=make_pair(l,1),s[rt]=0; return; }
    int mid=(l+r)>>1;
    build(rt<<1,l,mid),build((rt<<1)|1,mid+1,r);
}
void update(int rt,int l,int r,int x,int y,int z)
{
    if(x<=l && r<=y) { push(rt,z); return; }
    int mid=(l+r)>>1;
    pushdown(rt);
    if(x<=mid) update(rt<<1,l,mid,x,y,z);
    if(mid<y) update((rt<<1)|1,mid+1,r,x,y,z);
    pushup(rt);
}
int update(int rt,int l,int r,int x,int y,int z,int suf)
{
    if(y<l || x>r) return 0;
    if(x<=l && r<=y) { pushans(rt,(tr[rt].first==z)?1:0,suf); return (tr[rt].first==z)?tr[rt].second:0; }
    int mid=(l+r)>>1,temp;
    pushdown(rt);
    temp=update((rt<<1)|1,mid+1,r,x,y,z,suf);
    return temp+update(rt<<1,l,mid,x,y,z,suf+temp);
}
ll query(int rt,int l,int r,int x)
{
    if(l==r) return s[rt];
    int mid=(l+r)>>1;
    pushdown(rt);
    if(x<=mid) return query(rt<<1,l,mid,x);
    return query((rt<<1)|1,mid+1,r,x);
}
int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d",&a[i]);
    scanf("%d",&m);
    for(i=0;i<m;i++) scanf("%d%d",&q[i].l,&q[i].r),q[i].id=i;
    sort(q,q+m);
    top[0]=top[1]=0,sta[0][0]=sta[1][0]=0;
    build(1,1,n);
    for(j=0,i=1;i<=n;i++)
    {
        sta[0][top[0]+1]=sta[1][top[1]+1]=i;
        while(top[0] && a[sta[0][top[0]]]<a[i]) update(1,1,n,sta[0][top[0]-1]+1,sta[0][top[0]],a[i]-a[sta[0][top[0]]]),top[0]--;
        while(top[1] && a[sta[1][top[1]]]>a[i]) update(1,1,n,sta[1][top[1]-1]+1,sta[1][top[1]],a[sta[1][top[1]]]-a[i]),top[1]--;
        sta[0][++top[0]]=i,sta[1][++top[1]]=i;
        update(1,1,n,1,i,i,0);
        for(;j<m && q[j].r<=i;j++)
            ans[q[j].id]=query(1,1,n,q[j].l);
    }
    for(i=0;i<m;i++) printf("%lld\n",ans[i]);
    return 0;
}