#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define BLOSZ 500
#define maxdep 20
const int maxn=200005;
const int maxlogsz=maxdep+2;
const int maxcnt=maxn/BLOSZ+10;
struct point
{
    ll x,y;
    inline point(ll x=0,ll y=0):x(x),y(y) {}
    inline point operator +(const point &p) const { return point(x+p.x,y+p.y); }
    inline point operator -(const point &p) const { return point(x-p.x,y-p.y); }
    inline bool operator <=(const point &p) const { return (x==p.x)?y<=p.y:x<p.x; }
    inline bool operator <(const point &p) const { return p.y/(long double)p.x<y/(long double)x; }
};
inline void push(point *sta,int &n,point p,ll _) { while(n>=2 && !((sta[n-1]-sta[n-2])<(p-sta[n-1]))) n--; if(n && p-sta[n-1]<point(1,-_)) n--; sta[n++]=p; }
inline void merge(const point *a,int n,const point *b,int m,point *out,int &tot,ll _)
{
    register int i,j,k; point p; tot=0;
    for(i=j=k=0;i<n || j<m;push(out,tot,p,_))
        if(i<n && (j>=m || a[i]<=b[j])) p=a[i],i++;
        else p=b[j],j++;
}
inline ll query(const point *p,int n,int &i,ll x)
{
    if(i>=0) while(i<n-1 && p[i+1].x*x+p[i+1].y>=p[i].x*x+p[i].y) i++;
    if(i>=n) i=n-1;
    while(i>0 && p[i].x*x+p[i].y<=p[i-1].x*x+p[i-1].y) i--;
    return p[i].x*x+p[i].y;
}
int n,cnt,id[maxn];
vector<int> ch[maxn]; 
int dfn[maxn],sz[maxn],clk,re[maxn];
ll a[maxn],B[maxn];
point temp[BLOSZ];
struct block
{
    int L,R,mxn[BLOSZ<<2],mnn[BLOSZ<<2],smn[BLOSZ<<2],mxi,mni;
    point mx[maxlogsz][BLOSZ],mn[maxlogsz][BLOSZ];
    ll tag,lazy[BLOSZ<<2];
    block():mxi(0),mni(0),tag(0) {}
    inline ll query()
    {
        return max(::query(mx[0],mxn[1],mxi,tag),::query(mn[0],mnn[1],mni,tag));
    }
    inline void bf(int dep,int rt,int l,int r)
    {
        register int i,j;
        register ll t,temp;
        mxn[rt]=mnn[rt]=0;
        for(i=1;i<=r-l+1;i++) ::push(mx[dep]+l,mxn[rt],point(B[re[l+i-1+L]],a[re[l+i-1+L]]),tag);
        for(i=1;i<=r-l+1;i++) ::push(mn[dep]+l,mnn[rt],point(-B[re[l+i-1+L]],-a[re[l+i-1+L]]),tag);
    }
    inline void push(int dep,int rt,int l,int r,ll z)
    {
        register int i;
        lazy[rt]+=z;
        for(i=0;i<mxn[rt];i++) mx[dep][i+l].y+=mx[dep][i+l].x*z;
        for(i=0;i<mnn[rt];i++) mn[dep][i+l].y+=mn[dep][i+l].x*z;
    }
    inline void pushup(int dep,int rt,int l,int r,int mid)
    {
        merge(mx[dep+1]+l,mxn[rt<<1],mx[dep+1]+mid+1,mxn[(rt<<1)|1],mx[dep]+l,mxn[rt],tag);
        merge(mn[dep+1]+l,mnn[rt<<1],mn[dep+1]+mid+1,mnn[(rt<<1)|1],mn[dep]+l,mnn[rt],tag);
    }
    inline void pushdown(int dep,int rt,int l,int r,int mid) { if(lazy[rt]) push(dep+1,rt<<1,l,mid,lazy[rt]),push(dep+1,(rt<<1)|1,mid+1,r,lazy[rt]),lazy[rt]=0; }
    void build(int dep,int rt,int l,int r)
    {
        lazy[rt]=0;
        if(l==r)
        {
            mxn[rt]=mnn[rt]=1;
            mx[dep][l].x=B[re[l+L]],mn[dep][l].x=-B[re[l+L]];
            mx[dep][l].y=a[re[l+L]],mn[dep][l].y=-a[re[l+L]];
            return;
        }
        if(dep>maxdep) return bf(dep,rt,l,r);
        int mid=(l+r)>>1;
        build(dep+1,rt<<1,l,mid),build(dep+1,(rt<<1)|1,mid+1,r);
        pushup(dep,rt,l,r,mid);
    }
    inline void build() { build(0,1,0,R-L); }
    void update(int dep,int rt,int l,int r,int x,int y,ll z)
    {
        if(x<=l && r<=y) return push(dep,rt,l,r,z);
        if(dep>maxdep) return bf(dep,rt,l,r);
        int mid=(l+r)>>1;
        pushdown(dep,rt,l,r,mid);
        if(x<=mid) update(dep+1,rt<<1,l,mid,x,y,z);
        if(mid<y) update(dep+1,(rt<<1)|1,mid+1,r,x,y,z);
        pushup(dep,rt,l,r,mid);
    }
    inline void update(int l,int r,ll z) { update(0,1,0,R-L,l-L,r-L,z); }
}b[maxcnt];
void dfs(int u,int fa)
{
    vector<int>::iterator it;
    re[dfn[u]=clk++]=u,sz[u]=1,a[u]+=a[fa],B[u]+=B[fa];
    for(it=ch[u].begin();it!=ch[u].end();++it)
        dfs(*it,u),sz[u]+=sz[*it];
    B[u]=abs(B[u]),a[u]*=B[u];
}
int main()
{
    int q;
    register int i,l,r;
    ll x,ans;
    scanf("%d%d",&n,&q);
    for(i=1;i<=n;i++) ch[i].clear();
    for(i=2;i<=n;i++) scanf("%d",&l),ch[l].push_back(i);
    for(i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(i=1;i<=n;i++) scanf("%lld",&B[i]);
    a[0]=B[0]=0,clk=1,dfs(1,0);
    for(cnt=(n-1)/BLOSZ+1,i=0;i<cnt;i++) b[i].L=i*BLOSZ+1,b[i].R=min(n,(i+1)*BLOSZ);
    for(i=1,id[0]=id[n+1]=-1;i<=n;i++) id[i]=(i-1)/BLOSZ;
    for(i=0;i<cnt;i++) b[i].build();
    while(q--)
        if(scanf("%d%d",&i,&l),r=dfn[l]+sz[l]-1,l=dfn[l],i==1)
            if(scanf("%lld",&x),id[l]==id[r])
            {
                for(i=l;i<=r;i++) a[re[i]]+=x*B[re[i]];
                b[id[l]].update(l,r,x);
            }
            else
            {
                for(i=id[l]+1;i<id[r];i++) b[i].tag+=x;
                for(i=l;id[i]==id[l];i++) a[re[i]]+=x*B[re[i]];
                for(i=r;id[i]==id[r];i--) a[re[i]]+=x*B[re[i]];
                b[id[l]].update(l,b[id[l]].R,x),b[id[r]].update(b[id[r]].L,r,x);
            }
        else if(id[l]==id[r])
        {
            for(i=l,ans=0;i<=r;i++) ans=max(ans,abs(a[re[i]]+b[id[i]].tag*B[re[i]]));
            printf("%lld\n",ans);
        }
        else
        {
            for(i=l,ans=0;id[i]==id[l];i++) ans=max(ans,abs(a[re[i]]+b[id[i]].tag*B[re[i]]));
            for(i=id[l]+1;i<id[r];i++) ans=max(ans,b[i].query());
            for(i=r;id[i]==id[r];i--) ans=max(ans,abs(a[re[i]]+b[id[i]].tag*B[re[i]]));
            printf("%lld\n",ans);
        }
    return 0;
}