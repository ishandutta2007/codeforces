#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define il inline
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (x).size()
#define ALL(x) (x).begin(), (x).end()
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
inline ll read1()
{
	ll x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
#define N 201000
int n,m,q;
int head[N],nex[N<<1],to[N<<1];
int deep[N],top[N],fa[N],son[N],pos[N],num[N],size[N];
int tot,t1,t2,cnt,sum;
int bj[N<<2],a[N],b[N],l[N],en[N],w[N];
int f[N][21];
int ans[N];
struct node
{
    int pos,bel,type,l,r;
    friend bool operator < (const node &r1,const node &r2)
    {
        if(r1.pos==r2.pos)return r1.type ? 0:1;
        return r1.pos>r2.pos;
    }
}p[N<<2];
struct diw_tree
{
    int tr[N];
    void insert(int x,int y)
    {
        for(int i=x;i<=n;i+=i&(-i))
        tr[i]+=y;
    }
    int query(int x)
    {
        int ret=0;
        for(int i=x;i>=1;i-=i&(-i))
        ret+=tr[i];
        return ret;
    }
}tr;
void add(int x,int y)
{
    tot++;
    nex[tot]=head[x];head[x]=tot;
    to[tot]=y;
}
void dfs1(int x,int y)
{
    deep[x]=deep[y]+1;
    fa[x]=y;size[x]=1;
    for(int i=head[x];i;i=nex[i])
    if(to[i]!=y)
    {
        dfs1(to[i],x);
        size[x]+=size[to[i]];
        if(size[to[i]]>size[son[x]])
        son[x]=to[i];
    }
}
void dfs2(int x,int y,int tp)
{
    top[x]=tp;
    pos[x]=en[x]=++cnt;num[cnt]=x;
    if(son[x])dfs2(son[x],x,tp),en[x]=en[son[x]];
    for(int i=head[x];i;i=nex[i])
    if(to[i]!=y&&to[i]!=son[x])
    dfs2(to[i],x,to[i]),en[x]=en[to[i]];
}
int jud(int x,int y)
{
    if(!x||!y)return x+y;
    return deep[x]<deep[y] ? x:y;
}
int jud1(int x,int y)
{return deep[x]>deep[y] ? x:y;}
void update(int l,int r,int now,int lq,int rq,int v)
{
    if(lq<=l&&r<=rq)
    {
        bj[now]=jud(bj[now],v);
        return;
    }
    int mid=(l+r)>>1;
    if(mid>=lq)update(l,mid,now<<1,lq,rq,v);
    if(mid<rq)update(mid+1,r,now<<1|1,lq,rq,v);
}
void update(int x,int y,int tar)
{
    while(top[x]!=top[y])
    {
        if(deep[top[x]]<deep[top[y]])swap(x,y);
        update(1,n,1,pos[top[x]],pos[x],tar);
        x=fa[top[x]];
    }
    if(deep[x]<deep[y])swap(x,y);
    update(1,n,1,pos[y],pos[x],tar);
}
void pushdown(int x)
{
    if(bj[x])
    {
        bj[x<<1]=jud(bj[x],bj[x<<1]);
        bj[x<<1|1]=jud(bj[x],bj[x<<1|1]);
        bj[x]=0;
    }
}
void down(int l,int r,int now)
{
    if(l==r)
    {
        f[num[l]][0]=bj[now];
        return;
    }
    int mid=(l+r)>>1;
    pushdown(now);
    down(l,mid,now<<1);
    down(mid+1,r,now<<1|1);
}
int lca(int x,int y)
{
    while(top[x]!=top[y])
    {
        if(deep[top[x]]<deep[top[y]])swap(x,y);
        x=fa[top[x]];
    }
    if(deep[x]<deep[y])swap(x,y);
    return y;
}
pair<int,int> query(int x,int y)
{
    if(x==y)return make_pair(x,0);
    int ret=0;
    for(int i=20;i>=0;i--)
    if(deep[f[x][i]]>deep[y])
    x=f[x][i],ret+=(1<<i);
    if(f[x][0])return make_pair(x,ret);
    return make_pair(x,n);
}
int main()
{
	n = read();
    for(int i=2;i<=n;i++)
    {
        t1 = read();
        add(t1,i);
        add(i,t1);
    }
    dfs1(1,0);
    dfs2(1,0,1);
    m = read();
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&a[i],&b[i]);
        l[i]=lca(a[i],b[i]);
        if(deep[a[i]]>deep[b[i]])swap(a[i],b[i]);
        if(l[i]==a[i])update(a[i],b[i],a[i]);
        else
        {
            update(a[i],l[i],l[i]);
            update(b[i],l[i],l[i]);
            p[++sum].pos=max(pos[a[i]],pos[b[i]]);
            p[sum].bel=min(pos[a[i]],pos[b[i]]);
            p[sum].type=0;
        }
    }
    down(1,n,1);
    f[1][0]=0;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=20;j++)
    f[i][j]=f[f[i][j-1]][j-1];
    q = read();
    for(int i=1;i<=q;i++)
    {
        scanf("%d%d",&t1,&t2);
        if(t1==t2)
        {ans[i]=0;continue;}
        int t=lca(t1,t2);
        pair<int,int> q1=query(t1,t),q2=query(t2,t);
        ans[i]=q1.second+q2.second+1;
        if(ans[i]>n)
        {ans[i]=-1;continue;}
        if(t==t1||t==t2)
        {ans[i]--;continue;}
        if(pos[q1.first]>pos[q2.first])swap(q1,q2);
        p[++sum].pos=en[q2.first]+1;
        p[sum].type=-1;p[sum].bel=i;
        p[sum].l=pos[q1.first];p[sum].r=en[q1.first];
        p[++sum].pos=pos[q2.first];
        p[sum].type=1;p[sum].bel=i;
        p[sum].l=pos[q1.first];p[sum].r=en[q1.first];
    }
    sort(p+1,p+1+sum);
    for(int i=1;i<=sum;i++)
    {
        if(!p[i].type)
        tr.insert(p[i].bel,1);
        else
        w[p[i].bel]+=p[i].type*(tr.query(p[i].r)-tr.query(p[i].l-1));
    }
    rep(i, 1, q)
    {
        if(w[i])ans[i]--;
        if(ans[i] == -1) puts("-1");
        else printf("%d\n",ans[i] + 1);
    }
    return 0;
}