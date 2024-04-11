#include <bits/stdc++.h>
using namespace std;
long long aint[1048580];
long long v[262150];
int lazy[20];
void build (int nod, int l, int r)
{
    if(l==r)
        aint[nod]=v[l];
    else
    {
        int mid=(l+r)/2;
        build(nod*2,l,mid);
        build(nod*2+1,mid+1,r);
        aint[nod]=aint[nod*2]+aint[nod*2+1];
    }
}
long long query (int nod, int l, int r, int ql, int qr, int level)
{
    if(ql<=l && r<=qr)
        return aint[nod];
    int mid=(l+r)/2;
    int fst=nod*2;
    int fdr=nod*2+1;
    if(lazy[level])
        swap(fst,fdr);
    long long rz=0;
    if(ql<=mid)
        rz+=query(fst,l,mid,ql,qr,level+1);
    if(qr>mid)
        rz+=query(fdr,mid+1,r,ql,qr,level+1);
    return rz;
}
void update (int nod, int l, int r, int pz, int val, int level)
{
    if(l==r)
    {
        aint[nod]=val;
        return;
    }
    int mid=(l+r)/2;
    int fst=nod*2;
    int fdr=fst+1;
    if(lazy[level])
        swap(fst,fdr);
    if(pz<=mid)
        update(fst,l,mid,pz,val,level+1);
    else
        update(fdr,mid+1,r,pz,val,level+1);
    aint[nod]=aint[fst]+aint[fdr];
}
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m,i;
    cin>>n>>m;
    for(i=1;i<=(1<<n);++i)
        cin>>v[i];
    build(1,1,(1<<n));
    for(i=1;i<=m;++i)
    {
        int a,b,c;
        cin>>a;
        if(a==1)
        {
            cin>>b>>c;
            update(1,1,(1<<n),b,c,1);
        }
        if(a==4)
        {
            cin>>b>>c;
            cout<<query(1,1,(1<<n),b,c,1)<<'\n';
        }
        if(a==3)
        {
            cin>>b;
            int pz=n-b;
            lazy[pz]=1-lazy[pz];
        }
        if(a==2)
        {
            cin>>b;
            int pz=n-b+1;
            for(int j=pz;j<=19;++j)
                lazy[j]=1-lazy[j];
        }
    }
}