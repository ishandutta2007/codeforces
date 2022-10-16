#include <bits/stdc++.h>
using namespace std;
struct ura
{
    int outl,outr,bsth,hl,hr,inv;
    int Routl,Routr,Rbsth,Rhl,Rhr;
}aint[4000006];
char v[500005];
ura emptynode={0,0,0,0,0,0,0,0,0,0,0};
char vr[500005];
int n;
void revers (int node)
{
    swap(aint[node].outl,aint[node].Routl);
    swap(aint[node].outr,aint[node].Routr);
    swap(aint[node].hl,aint[node].Rhl);
    swap(aint[node].hr,aint[node].Rhr);
    swap(aint[node].bsth,aint[node].Rbsth);
}
ura merge (int f1, int f2, int s1, int s2)
{
    ura merged=emptynode;
    /// outl
    if(aint[f1].outl==s1)
        merged.outl=s1+aint[f2].outl;
    else
        merged.outl=aint[f1].outl;
    /// outr
    if(aint[f2].outr==s2)
        merged.outr=s2+aint[f1].outr;
    else
        merged.outr=aint[f2].outr;
    /// hl
    if(aint[f1].hl+aint[f1].outl<s1 && aint[f1].hl)
        merged.hl=aint[f1].hl;
    else if(aint[f1].hl)
        merged.hl=aint[f1].hl+aint[f2].outl;
    else
    {
        if(aint[f2].outl && aint[f1].outr)
            merged.hl=aint[f1].outr+aint[f2].outl;
        else if(aint[f2].hl)
            merged.hl=aint[f1].outr+aint[f2].hl;
    }
    /// hr
    if(aint[f2].hr+aint[f2].outr<s2 && aint[f2].hr)
        merged.hr=aint[f2].hr;
    else if(aint[f2].hr)
        merged.hr=aint[f2].hr+aint[f1].outr;
    else
    {
        if(aint[f1].outr && aint[f2].outl)
            merged.hr=aint[f2].outl+aint[f1].outr;
        else if(aint[f1].hr)
            merged.hr=aint[f2].outl+aint[f1].hr;
    }
    /// bsth
    merged.bsth=max(merged.bsth,merged.hl);
    merged.bsth=max(merged.bsth,merged.hr);
    merged.bsth=max(merged.bsth,aint[f1].bsth);
    merged.bsth=max(merged.bsth,aint[f2].bsth);
    if(aint[f1].outr && aint[f2].outl)
        merged.bsth=max(merged.bsth,aint[f1].outr+aint[f2].outl);
    if(!aint[f1].outr && aint[f1].hr)
        merged.bsth=max(merged.bsth,aint[f1].hr+aint[f2].outl);
    if(!aint[f2].outl && aint[f2].hl)
        merged.bsth=max(merged.bsth,aint[f1].outr+aint[f2].hl);
    /// Routl
    if(aint[f1].Routl==s1)
        merged.Routl=s1+aint[f2].Routl;
    else
        merged.Routl=aint[f1].Routl;
    /// Routr
    if(aint[f2].Routr==s2)
        merged.Routr=s2+aint[f1].Routr;
    else
        merged.Routr=aint[f2].Routr;
    /// Rhl
    if(aint[f1].Rhl+aint[f1].Routl<s1 && aint[f1].Rhl)
        merged.Rhl=aint[f1].Rhl;
    else if(aint[f1].Rhl)
        merged.Rhl=aint[f1].Rhl+aint[f2].Routl;
    else
    {
        if(aint[f2].Routl && aint[f1].Routr)
            merged.Rhl=aint[f1].Routr+aint[f2].Routl;
        else if(aint[f2].Rhl)
            merged.Rhl=aint[f1].Routr+aint[f2].Rhl;
    }
    /// Rhr
    if(aint[f2].Rhr+aint[f2].Routr<s2 && aint[f2].Rhr)
        merged.Rhr=aint[f2].Rhr;
    else if(aint[f2].Rhr)
        merged.Rhr=aint[f2].Rhr+aint[f1].Routr;
    else
    {
        if(aint[f1].Routr && aint[f2].Routl)
            merged.Rhr=aint[f2].Routl+aint[f1].Routr;
        else if(aint[f1].Rhr)
            merged.Rhr=aint[f2].Routl+aint[f1].Rhr;
    }
    /// Rbsth
    merged.Rbsth=max(merged.Rbsth,merged.Rhl);
    merged.Rbsth=max(merged.Rbsth,merged.Rhr);
    merged.Rbsth=max(merged.Rbsth,aint[f1].Rbsth);
    merged.Rbsth=max(merged.Rbsth,aint[f2].Rbsth);
    if(aint[f1].Routr && aint[f2].Routl)
        merged.Rbsth=max(merged.Rbsth,aint[f1].Routr+aint[f2].Routl);
    if(!aint[f1].Routr && aint[f1].Rhr)
        merged.Rbsth=max(merged.Rbsth,aint[f1].Rhr+aint[f2].Routl);
    if(!aint[f2].Routl && aint[f2].Rhl)
        merged.Rbsth=max(merged.Rbsth,aint[f1].Routr+aint[f2].Rhl);
    return merged;
}
void recompute (int nod, int st, int dr)
{
    int mid=(st+dr)/2;
    int f1=nod*2,f2=nod*2+1;
    int s1=mid-st+1,s2=dr-mid;
    aint[nod]=merge(f1,f2,s1,s2);
}
void build (int nod, int st, int dr)
{
    if(st==dr)
    {
        if(v[st]=='<')
            aint[nod]={1,0,0,0,0,0,0,1,0,0,0};
        else
            aint[nod]={0,1,0,0,0,0,1,0,0,0,0};
        return;
    }
    int mid=(st+dr)/2;
    build(nod*2,st,mid);
    build(nod*2+1,mid+1,dr);
    recompute(nod,st,dr);
}
void update (int nod, int st, int dr, int stu, int dru, int stprec=0, int drprec=0)
{
    if(aint[nod].inv)
    {
        revers(nod);
        aint[nod*2].inv=1-aint[nod*2].inv;
        aint[nod*2+1].inv=1-aint[nod*2+1].inv;
        aint[nod].inv=0;
    }
    if(stu<=st && dr<=dru)
    {
        if(dr-st+1==n)
        {
            revers(nod);
            aint[nod*2].inv=1-aint[nod*2].inv;
            aint[nod*2+1].inv=1-aint[nod*2+1].inv;
            return;
        }
        revers(nod);
      //  recompute(nod/2,stprec,drprec);
        aint[nod*2].inv=1-aint[nod*2].inv;
        aint[nod*2+1].inv=1-aint[nod*2+1].inv;
        return;
    }
    int mid=(st+dr)/2;
    if(stu<=mid)
        update(nod*2,st,mid,stu,dru,st,dr);
    if(dru>mid)
        update(nod*2+1,mid+1,dr,stu,dru,st,dr);
    nod=nod*2;
    if(aint[nod].inv)
    {
        revers(nod);
        aint[nod*2].inv=1-aint[nod*2].inv;
        aint[nod*2+1].inv=1-aint[nod*2+1].inv;
        aint[nod].inv=0;
    }
    nod/=2;
    nod=nod*2+1;
    if(aint[nod].inv)
    {
        revers(nod);
        aint[nod*2].inv=1-aint[nod*2].inv;
        aint[nod*2+1].inv=1-aint[nod*2+1].inv;
        aint[nod].inv=0;
    }
    nod/=2;
    recompute(nod,st,dr);
}
ura query (int nod, int st, int dr, int stu, int dru)
{
    if(aint[nod].inv)
    {
        revers(nod);
        aint[nod*2].inv=1-aint[nod*2].inv;
        aint[nod*2+1].inv=1-aint[nod*2+1].inv;
        aint[nod].inv=0;
    }
    if(stu<=st && dr<=dru)
        return aint[nod];
    int mid=(st+dr)/2;
    if(stu<=mid && dru>mid)
    {
        //return merge(query(nod*2,st,mid,stu,dru),query(nod*2+1,mid+1,dr,stu,dru)); I'm dumb
        ura l=query(nod*2,st,mid,stu,dru);
        ura r=query(nod*2+1,mid+1,dr,stu,dru);
        aint[4000004]=l;
        aint[4000005]=r;
        int f1=4000004;
        int f2=4000005;
        int s1=mid-max(stu,st)+1;
        int s2=min(dru,dr)-mid;
        return merge(f1,f2,s1,s2);
    }
    if(stu<=mid)
        return query(nod*2,st,mid,stu,dru);
    if(dru>mid)
        return query(nod*2+1,mid+1,dr,stu,dru);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long m,i,j;
    cin>>n>>m;
    cin>>(v+1);
    for(i=1;i<=n;++i)
        vr[i]='>'+'<'-v[i];
    for(i=0;i<=4000005;++i)
        aint[i]=emptynode;
    build(1,1,n);
    for(i=1;i<=m;++i)
    {
        int a,b;
        cin>>a>>b;
        update(1,1,n,a,b);
        ura idk=query(1,1,n,a,b);
        cout<<max(max(idk.bsth,idk.outl),idk.outr)<<'\n';
    }
    return 0;
}