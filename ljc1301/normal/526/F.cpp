#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; // min,cnt
const int maxn=300005;
int n,a[maxn],sta[2][maxn],top[2],tag[maxn<<2];
pii tr[maxn<<2];
inline pii operator +(const pii &a,const pii &b)
{
    return make_pair(min(a.first,b.first),((a.first<=b.first)?a.second:0)+((b.first<=a.first)?b.second:0));
}
inline void push(int rt,int x) { tag[rt]+=x,tr[rt].first+=x; }
inline void pushup(int rt) { tr[rt]=tr[rt<<1]+tr[(rt<<1)|1]; }
inline void pushdown(int rt) { if(tag[rt]) push(rt<<1,tag[rt]),push((rt<<1)|1,tag[rt]),tag[rt]=0; }
// max-min+l=r (max-min+l>=r)
void build(int rt,int l,int r)
{
    if(l==r) { tr[rt]=make_pair(l,1); return; }
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
pii query(int rt,int l,int r,int x,int y)
{
    if(x<=l && r<=y) return tr[rt];
    int mid=(l+r)>>1;
    pii res=make_pair(n+1,0);
    pushdown(rt);
    if(x<=mid) res=res+query(rt<<1,l,mid,x,y);
    if(mid<y) res=res+query((rt<<1)|1,mid+1,r,x,y);
    return res;
}
int main()
{
    int i,x;
    pii temp;
    ll ans=0;
    scanf("%d",&n);
    build(1,1,n);
    for(i=1;i<=n;i++) scanf("%d",&x),scanf("%d",&a[x]);
    top[0]=top[1]=0,sta[0][0]=sta[1][0]=0;
    for(i=1;i<=n;i++)
    {
        sta[0][top[0]+1]=sta[1][top[1]+1]=i;
        while(top[0] && a[sta[0][top[0]]]<a[i]) update(1,1,n,sta[0][top[0]-1]+1,sta[0][top[0]],a[i]-a[sta[0][top[0]]]),top[0]--;
        while(top[1] && a[sta[1][top[1]]]>a[i]) update(1,1,n,sta[1][top[1]-1]+1,sta[1][top[1]],a[sta[1][top[1]]]-a[i]),top[1]--;
        sta[0][++top[0]]=i,sta[1][++top[1]]=i;
        ans+=query(1,1,n,1,i).second;
    }
    printf("%lld\n",ans);
    return 0;
}