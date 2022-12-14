#include<bits/stdc++.h>
using namespace std;
int n,q,a[1111111],l[1111111],r[1111111],lazy[4444444],sz;
long long tree[4444444],ans[1111111];
vector<pair<int,int> > v1[1111111],v2[1111111]; 
void push(int node,int x,int s)
{
    tree[node]=tree[node]+1ll*s*x;
    lazy[node]+=x;
}
void pushdown(int node,int s)
{
    if (lazy[node])
    {
        push(node<<1,lazy[node],s);
        push((node<<1)|1,lazy[node],s);
        lazy[node]=0;
    }
}
void pushup(int node)
{
    tree[node]=tree[node<<1]+tree[(node<<1)|1];
}
void update(int beg,int en,int l,int r,int node,int x)
{
    if (l>en || r<beg) return;
    if (l>=beg && r<=en) 
    {
        push(node,x,r-l+1);
        return;
    }
    pushdown(node,(r-l+1)>>1);
    int mid=(l+r)>>1;
    update(beg,en,l,mid,node<<1,x);
    update(beg,en,mid+1,r,(node<<1)|1,x);
    pushup(node);
}
long long query(int beg,int en,int l,int r,int node)
{
    if (l>en || r<beg) return 0ll;
    if (l>=beg && r<=en) return tree[node];
    pushdown(node,(r-l+1)>>1);
    int mid=(l+r)>>1;
    return query(beg,en,l,mid,node<<1)+query(beg,en,mid+1,r,(node<<1)|1);
}
deque<pair<int,int> > qq;
pair<int,int> add;
int main()
{
    scanf("%d%d",&n,&q);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=q;i++)
    {
        scanf("%d",&l[i]);
    }
    for (int i=1;i<=q;i++)
    {
        scanf("%d",&r[i]);
    }
    for (int i=1;i<=q;i++)
    {
        v1[l[i]].push_back(make_pair(r[i],i));
        v2[r[i]].push_back(make_pair(l[i],i));
    }
    sz=1;
    while(sz<n) sz*=2;
    for (int i=1;i<=n;i++)
    {
        add=make_pair(a[i],i);
        while(!qq.empty())
        {
            if (qq.back().first<add.first) qq.pop_back();
            else break;
        }
        if (qq.empty()) update(1,i,1,sz,1,1);
        else update(qq.back().second+1,i,1,sz,1,1);
        qq.push_back(add);
        for (int j=0;j<v2[i].size();j++)
        {
            ans[v2[i][j].second]=query(v2[i][j].first,i,1,sz,1);
        }
    }
    memset(tree,0,sizeof(tree));
    memset(lazy,0,sizeof(lazy));
    qq.clear();
    for (int i=n;i>=1;i--)
    {
        add=make_pair(a[i],i);
        while(!qq.empty())
        {
            if (qq.back().first<add.first) qq.pop_back();
            else break;
        }
        if (qq.empty()) update(i,n,1,sz,1,1);
        else update(i,qq.back().second-1,1,sz,1,1);
        qq.push_back(add);
        for (int j=0;j<v1[i].size();j++)
        {
            ans[v1[i][j].second]+=query(i,v1[i][j].first,1,sz,1);
        }
    }
    for (int i=1;i<=q;i++) printf("%lld ",ans[i]-(r[i]-l[i]+1));
    printf("\n");
    return 0;
}