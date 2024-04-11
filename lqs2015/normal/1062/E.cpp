#include<bits/stdc++.h>
using namespace std;
int n,q,x,beg[111111],en[111111],ct,dep[111111],an[111111][22],l,r,lyz,lyzz;
int lca(int x,int y);
struct segtree
{
    pair<int,int> mn,mx;
    int lc;
}tree[444444];
void pushup(int node)
{
    tree[node].mn=min(tree[node<<1].mn,tree[(node<<1)|1].mn);
    tree[node].mx=max(tree[node<<1].mx,tree[(node<<1)|1].mx);
    tree[node].lc=lca(tree[node<<1].lc,tree[(node<<1)|1].lc);
}
void build(int l,int r,int node)
{
    if(l==r)
    {
        tree[node].mn=make_pair(beg[l],l);
        tree[node].mx=make_pair(beg[l],l);
        tree[node].lc=l;
        return;
    }
    int mid=(l+r)>>1;
    build(l,mid,node<<1);
    build(mid+1,r,(node<<1)|1);
    pushup(node);
}
vector<int> g[111111];
void dfs(int i,int fa)
{
    an[i][0]=fa;dep[i]=dep[fa]+1;
    beg[i]=++ct;
    for (int j=1;j<=18;j++) an[i][j]=an[an[i][j-1]][j-1];
    for (int j=0;j<g[i].size();j++)
    {
        int to=g[i][j];
        if (to==fa) continue;
        dfs(to,i);
    }
    en[i]=ct;
}
int lca(int x,int y)
{
    if (!x || !y) return x^y;
    if (dep[x]<dep[y]) swap(x,y);
    for (int i=18;i>=0;i--)
    {
        if (dep[an[x][i]]>=dep[y]) x=an[x][i];
    }
    for (int i=18;i>=0;i--)
    {
        if (an[x][i]!=an[y][i])
        {
            x=an[x][i];
            y=an[y][i];
        }
    }
    if (x!=y) return an[x][0];
    return x;
}
pair<int,int> querymx(int beg,int en,int l,int r,int node)
{
    if (l>en || r<beg) return make_pair(0,0);
    if (l>=beg && r<=en) return tree[node].mx;
    int mid=(l+r)>>1;
    return max(querymx(beg,en,l,mid,node<<1),querymx(beg,en,mid+1,r,(node<<1)|1));
}
pair<int,int> querymn(int beg,int en,int l,int r,int node)
{
    if (l>en || r<beg) return make_pair(1e9,0);
    if (l>=beg && r<=en) return tree[node].mn;
    int mid=(l+r)>>1;
    return min(querymn(beg,en,l,mid,node<<1),querymn(beg,en,mid+1,r,(node<<1)|1));
}
int querylc(int beg,int en,int l,int r,int node)
{
    if (l>en || r<beg) return 0;
    if (l>=beg && r<=en)  return tree[node].lc;
    int mid=(l+r)>>1;
    return lca(querylc(beg,en,l,mid,node<<1),querylc(beg,en,mid+1,r,(node<<1)|1));
}
int main()
{
    scanf("%d%d",&n,&q);
    for (int i=2;i<=n;i++)
    {
        scanf("%d",&x);
        g[x].push_back(i);
        g[i].push_back(x);
    }
    dfs(1,0);
    build(1,n,1);
    while(q--)
    {
        scanf("%d%d",&l,&r);
        int mx=querymx(l,r,1,n,1).second,mn=querymn(l,r,1,n,1).second;
        lyz=lca(querylc(l,mx-1,1,n,1),querylc(mx+1,r,1,n,1));
        lyzz=lca(querylc(l,mn-1,1,n,1),querylc(mn+1,r,1,n,1));
        if(dep[lyz]<dep[lyzz])
        {
            printf("%d %d\n",mn,dep[lyzz]-1);
        }
        else
        {
            printf("%d %d\n",mx,dep[lyz]-1);
        }
    }
    return 0;
}