#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
// divide-and-conquer on segment tree
const int maxn=500005;
const int maxm=500005;
const int maxq=500005;
const int maxlog=21;
const int maxk=55;
const int maxnode=maxq<<2;
struct node
{
    int fa,sz; bool c;
    inline node(int fa,int sz,bool c):fa(fa),sz(sz),c(c) { }
};
int n,m,k,q,u[maxn],v[maxn],e[maxq],c[maxq],col[maxn];
// stack<node> p[maxn];
int fa[maxk][maxn],sz[maxk][maxn];
bool z[maxk][maxn];
vector<int> tr[maxnode];
stack<pii> sta[maxlog];
void build(int rt,int l,int r)
{
    tr[rt].clear();
    if(l==r) return;
    int mid=(l+r)>>1;
    build(rt<<1,l,mid),build((rt<<1)|1,mid+1,r);
}
void query(int rt,int l,int r,int x,int y)
{
    if(x<=l && r<=y) { tr[rt].push_back(x-1); return; }
    int mid=(l+r)>>1;
    if(x<=mid) query(rt<<1,l,mid,x,y);
    if(mid<y) query((rt<<1)|1,mid+1,r,x,y);
}
void solve(int rt,int l,int r,int dep)
{
    vector<int>::iterator it;
    int x,y,c_; bool t;
    while(!sta[dep].empty()) sta[dep].pop();
    for(it=tr[rt].begin();it!=tr[rt].end();++it)
    {
        t=1,c_=c[*it];
        if(c_==-1) continue;
        // for(x=u[*it];p[x].top().fa!=x;x=p[x].top().fa) t^=p[x].top().c;
        // for(y=v[*it];p[y].top().fa!=y;y=p[y].top().fa) t^=p[y].top().c;
        for(x=u[e[*it]];fa[c_][x]!=x;x=fa[c_][x]) t^=z[c_][x];
        for(y=v[e[*it]];fa[c_][y]!=y;y=fa[c_][y]) t^=z[c_][y];
        if(x==y) { assert(!t); continue; }
        // if(p[x].top().sz<p[y].top().sz) swap(x,y);
        if(sz[c_][x]<sz[c_][y]) swap(x,y);
        // p[x].push(node(x,p[x].top().sz+p[y].top().sz,0)),p[y].push(node(x,0,t));
        // sta[dep].push(x),sta[dep].push(y);
        fa[c_][y]=x,z[c_][y]=t,sz[c_][x]+=sz[c_][y];
        sta[dep].push(make_pair(y,c_));
    }
    if(l<r)
    {
        int mid=(l+r)>>1;
        solve(rt<<1,l,mid,dep+1),solve((rt<<1)|1,mid+1,r,dep+1);
    }
    else
    {
        t=0,c_=c[l];
        // for(x=u[l];p[x].top().fa!=x;x=p[x].top().fa) t^=p[x].top().c;
        // for(y=v[l];p[y].top().fa!=y;y=p[y].top().fa) t^=p[y].top().c;
        for(x=u[e[l]];fa[c_][x]!=x;x=fa[c_][x]) t^=z[c_][x];
        for(y=v[e[l]];fa[c_][y]!=y;y=fa[c_][y]) t^=z[c_][y];
        if(x!=y || t) printf("YES\n"),col[e[l]]=c[l];
        else printf("NO\n"),c[l]=col[e[l]];
    }
    while(!sta[dep].empty()) // p[sta[dep].top()].pop(),sta[dep].pop();
    {
        x=fa[c_=sta[dep].top().second][y=sta[dep].top().first];
        sz[c_][x]-=sz[c_][y],fa[c_][y]=y;
        sta[dep].pop();
    }
}
int main()
{
    int i,j;
    scanf("%d%d%d%d",&n,&m,&k,&q);
    for(i=1;i<=m;i++) scanf("%d%d",&u[i],&v[i]);
    for(i=0;i<q;i++) scanf("%d%d",&e[i],&c[i]),c[i]--;
    build(1,0,q-1);
    for(i=1;i<=m;i++) col[i]=q;
    for(i=q-1;i>=0;i--)
    {
        if(i+1<col[e[i]])
            query(1,0,q-1,i+1,col[e[i]]-1);
        col[e[i]]=i;
    }
    for(i=1;i<=m;i++) col[i]=-1;
    // for(i=1;i<=n;i++)
    // {
    //     while(!p[i].empty()) p[i].pop();
    //     p[i].push(node(i,1,0));
    // }
    for(i=0;i<k;i++)
        for(j=1;j<=n;j++)
            fa[i][j]=j,sz[i][j]=1,z[i][j]=0;
    solve(1,0,q-1,0);
    return 0;
}