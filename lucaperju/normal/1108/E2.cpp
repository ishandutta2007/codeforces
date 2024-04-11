#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int v[200005];
vector <int> st[200005];
vector <int> dr[200005];
int aa[305],bb[305];
int arb[400005],lazy[400005];
void propag (int nod, int st, int dr)
{
    if(lazy[nod])
    {
        arb[nod]+=lazy[nod];
        if(st!=dr)
        {
            lazy[nod*2]+=lazy[nod];
            lazy[nod*2+1]+=lazy[nod];
        }
        lazy[nod]=0;
    }
}
void update (int nod, int st, int dr, int st1, int dr1, int val)
{
    if(st1<=st && dr1>=dr)
    {
        lazy[nod]+=val;
        propag(nod,st,dr);
    //    if(st==dr)
    //        arb[nod]+=lazy[nod],lazy[nod]=0;
        return;
    }
    else
    {
        propag(nod,st,dr);
        int mid=(st+dr)/2;
        if(st1<=mid) update(nod*2,st,mid,st1,dr1,val);
        if(dr1>=mid+1) update(nod*2+1,mid+1,dr,st1,dr1,val);
        arb[nod]=min(arb[nod*2]+lazy[nod*2],arb[nod*2+1]+lazy[nod*2+1]);
    }
}
int query (int nod, int st, int dr, int st1, int dr1)
{
    propag(nod,st,dr);
    if(st1<=st && dr1>=dr)
        return arb[nod];
    int mid=(st+dr)/2,mn=999999999;
    if(st1<=mid) mn=min(query(nod*2,st,mid,st1,dr1),mn);
    if(dr1>=mid+1) mn=min(query(nod*2+1,mid+1,dr,st1,dr1),mn);
    return mn;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie();cout.tie();
    int n,k,i,j=0,cnt=0,s=0,pzs=1,psj=1,cur=0,pz,m,val,mx=-1,cntc,cntf,a,b;
    cin>>n>>m;
    for(i=1;i<=n;++i)
    {
        cin>>v[i];
        update(1,1,n,i,i,v[i]);
    }
    for(i=1;i<=m;++i)
    {
        cin>>a>>b;
        dr[b].push_back(a);
        st[a].push_back(b);
        update(1,1,n,a,b,-1);
        aa[i]=a;
        bb[i]=b;
    }
    for(k=1;k<=n;++k)
    {
        cntc=0;
        for(j=0;j<st[k].size();++j)
            update(1,1,n,k,st[k][j],1);
        int mn=query(1,1,n,1,n);
        for(j=0;j<dr[k].size();++j)
            update(1,1,n,dr[k][j],k,-1);
        if(v[k]-mn>mx)
        {
            mx=v[k]-mn;
            pz=k;
            cntf=cntc;
        }
    }
    cout<<mx<<'\n';
    for(j=1;j<=m;++j)
    {
        if(aa[j]>pz || bb[j]<pz)
        {
            ++cntf;
        }
    }
    cout<<cntf<<'\n';
    for(j=1;j<=m;++j)
    {
        if(aa[j]>pz || bb[j]<pz)
        {
            cout<<j<<' ';
        }
    }
    return 0;
}