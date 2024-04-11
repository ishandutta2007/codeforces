#include <bits/stdc++.h>
using namespace std;
int X;
struct ura
{
    int val,cnt;
};
struct node
{
    long long s;
    vector<ura>l;
    vector<ura>r;
}aint[400003];
int v[100003];
void join (node* res, node* l, node* r)
{
    res->s=l->s+r->s;
    for(int i=0;i<l->r.size();++i)
        for(int j=0;j<r->l.size();++j)
            if(X <= (l->r[i].val | r->l[j].val))
                res->s += l->r[i].cnt *1LL* r->l[j].cnt;
    res->l=l->l;
    int i=res->l.size()-1;
    for(int j=0;j<r->l.size();++j)
    {
        ura x={res->l[i].val | r->l[j].val, r->l[j].cnt};
        if(x.val==res->l[i].val)
            res->l[i].cnt+=x.cnt;
        else
        {
            res->l.push_back(x);
            ++i;
        }
    }
    res->r=r->r;
    i=res->r.size()-1;
    for(int j=0;j<l->r.size();++j)
    {
        ura x={res->r[i].val | l->r[j].val, l->r[j].cnt};
        if(x.val==res->r[i].val)
            res->r[i].cnt+=x.cnt;
        else
        {
            res->r.push_back(x);
            ++i;
        }
    }
}
void build (int nod, int l, int r)
{
    if(l==r)
    {
        aint[nod].l.push_back({v[l],1});
        aint[nod].r.push_back({v[r],1});
        if(v[l]>=X)
            aint[nod].s=1;
        else
            aint[nod].s=0;
        return;
    }
    int mid=(l+r)/2;
    build(nod*2,l,mid);
    build(nod*2+1,mid+1,r);
    join(&aint[nod],&aint[nod*2],&aint[nod*2+1]);
}
void upd (int nod, int l, int r, int pz, int val)
{
    if(l==r)
    {
        v[pz]=val;
        aint[nod].l.clear();
        aint[nod].r.clear();
        aint[nod].l.push_back({v[l],1});
        aint[nod].r.push_back({v[r],1});
        if(v[l]>=X)
            aint[nod].s=1;
        else
            aint[nod].s=0;
        return;
    }
    int mid=(l+r)/2;
    if(pz<=mid)
        upd(nod*2,l,mid,pz,val);
    else
        upd(nod*2+1,mid+1,r,pz,val);
    join(&aint[nod],&aint[nod*2],&aint[nod*2+1]);
}
node query (int nod, int l, int r, int ql, int qr)
{
    if(ql<=l && r<=qr)
        return aint[nod];
    int mid=(l+r)/2;
    if(qr<=mid)
        return query(nod*2,l,mid,ql,qr);
    if(mid<ql)
        return query(nod*2+1,mid+1,r,ql,qr);
    node lc,rc,x;
    lc=query(nod*2,l,mid,ql,qr);
    rc=query(nod*2+1,mid+1,r,ql,qr);
    join(&x,&lc,&rc);
    return x;
}
int main()
{
    ios_base::sync_with_stdio(false);
    long long t,i,j,n,m;
    cin>>n>>m>>X;
    for(i=1;i<=n;++i)
        cin>>v[i];
    build(1,1,n);
    for(i=1;i<=m;++i)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(a==1)
            upd(1,1,n,b,c);
        else
        {
            node x=query(1,1,n,b,c);
            cout<<x.s<<'\n';
        }
    }
}