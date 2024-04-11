#include <bits/stdc++.h>

using namespace std;
struct ura
{
    long long i,j;
}v[200005];
bool sf[200005];
long long d[200005],k;
bool cmp (ura a, ura b)
{
    if(a.i<b.i)
        return true;
    if(a.i>b.i)
        return false;
    return a.j<b.j;
}
long long sfst[200005],sfdr[200005],st[200005],dr[200005];
long long idk (long long pz)
{
    if(pz==k || dr[v[pz].i]==k)
        return 0;
    if(d[pz]!=-1)
        return d[pz];
    long long mn=999999999999LL;
    mn=min(mn,idk(dr[v[pz].i]+1)+min(v[pz].j-sfst[v[pz].j]+abs(v[dr[v[dr[v[pz].i]+1].i]].j-sfst[v[pz].j]),sfdr[v[pz].j]-v[pz].j+abs(v[dr[v[dr[v[pz].i]+1].i]].j-sfdr[v[pz].j]))+v[dr[v[dr[v[pz].i]+1].i]].j-v[dr[v[pz].i]+1].j);
    mn=min(mn,idk(dr[v[dr[v[pz].i]+1].i])+min(v[pz].j-sfst[v[pz].j]+abs(v[dr[v[pz].i]+1].j-sfst[v[pz].j]),sfdr[v[pz].j]-v[pz].j+abs(v[dr[v[pz].i]+1].j-sfdr[v[pz].j]))+v[dr[v[dr[v[pz].i]+1].i]].j-v[dr[v[pz].i]+1].j);
    d[pz]=mn;
    return mn;
}
int main()
{
    ios_base::sync_with_stdio(0);
    long long t,i,j=0,cnt=1,mn=2,n,m,is,js,ib,jb,s=0,a,b,mx=0,cur=0,q;
    cin>>n>>m>>k>>q;
    for(i=1;i<=k;++i)
        cin>>v[i].i>>v[i].j;
    for(i=1;i<=q;++i)
    {
        cin>>a;
        sf[a]=true;
    }
    for(i=1;i<=n;++i)
        st[i]=dr[i]=-1;
    sort(v+1,v+k+1,cmp);
    for(i=1;i<=k;++i)
    {
        if(v[i].i!=v[i-1].i)
        {
            dr[v[i-1].i]=i-1;
            st[v[i].i]=i;
        }
        d[i]=-1;
    }
    d[0]=-1;
    v[0].i=1;
    v[0].j=1;
    dr[v[k].i]=k;
    st[1]=0;
    if(dr[1]==-1)
        dr[1]=0;
    long long pz=-99999999999LL;
    for(i=1;i<=m;++i)
    {
        if(sf[i])
            pz=i;
        sfst[i]=pz;
    }
    pz=99999999999LL;
    for(i=m;i>=1;--i)
    {
        if(sf[i])
            pz=i;
        sfdr[i]=pz;
    }
    if(dr[1]==0)
        s=idk(0);
    else
        s=idk(dr[1])+v[dr[1]].j-1;
    cout<<s+v[k].i-1;
    return 0;
}