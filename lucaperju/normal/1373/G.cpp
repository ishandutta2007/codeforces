#include <bits/stdc++.h>
using namespace std;
map<int,int>mp[200003];
int getupd (int x, int y)
{
    if(mp[x][y])
    {
        mp[x][y]=0;
        return -1;
    }
    mp[x][y]=1;
    return 1;
}
struct node
{
    int l,r,notempty;
};
node join (node a, node b)
{
    node rz;
    rz.notempty=(a.notempty|b.notempty);
    rz.r=b.r+max(0,a.r-b.l);
    rz.l=a.l+max(0,b.l-a.r);
    return rz;
}
node aint[1600004];
void upd (int nod, int l, int r, int pz, int val)
{
    if(l==r)
    {
        if(val==1)
        {
            if(aint[nod].l)
            {
                aint[nod].l=0;
                aint[nod].notempty=1;
                return;
            }
            ++aint[nod].r;
            return;
        }
        if(aint[nod].r==0)
        {
            aint[nod].l=1;
            aint[nod].notempty=0;
            return;
        }
        --aint[nod].r;
        return;
    }
    int mid=((l+r)>>1);
    if(pz<=mid)
        upd(nod<<1,l,mid,pz,val);
    else
        upd((nod<<1)|1,mid+1,r,pz,val);
    aint[nod]=join(aint[nod<<1],aint[(nod<<1)|1]);
}
void build (int nod, int l, int r)
{
    aint[nod].l=(r-l+1);
    if(l==r)
        return;
    int mid=(l+r)/2;
    build(nod<<1,l,mid);
    build((nod<<1)|1,mid+1,r);
}
node query (int nod, int l, int r, int ql, int qr)
{
    if(ql<=l && r<=qr)
        return aint[nod];
    int mid=(l+r)/2;
    if(ql<=mid && mid<qr)
        return join(query(nod*2,l,mid,ql,qr),query(nod*2+1,mid+1,r,ql,qr));
    if(ql<=mid)
        return query(nod*2,l,mid,ql,qr);
    if(mid<qr)
        return query(nod*2+1,mid+1,r,ql,qr);
}
multiset<int>gay;
int main()
{
    ios_base::sync_with_stdio(false);
    int n,i,j,k,m;
    cin>>n>>k>>m;
    build(1,1,n<<1);
    for(i=1;i<=m;++i)
    {
        int x,y;
        cin>>x>>y;
        int a=getupd(x,y);
        x=y+max(k-x,x-k);
        upd(1,1,n<<1,x,a);
        if(a==1)
            gay.insert(-x);
        else
            gay.erase(gay.find(-x));
        if(gay.empty())
        {
            cout<<"0\n";
            continue;
        }
        int mxc=-(*gay.lower_bound(-2*n));
        cout<<max(query(1,1,n<<1,1,mxc).r+mxc-n,0)<<'\n';
    }
}
/**
 ^        *
 |       /|
 |      / |
 |   \|/  |
y|    X   |
 |        |
 |        |
 ----------->
      x   k
*/