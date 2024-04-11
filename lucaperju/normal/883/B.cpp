#include <bits/stdc++.h>
using namespace std;
vector<int>v[200003];
vector<int>vr[200003];
struct ura
{
    int pz,vmin,vmax;
};
int rzf[200003];
int fix[200003];
ura vc[200003];
int fv[200003];
int viz[200003],k;
int hasfixed[200003];
void dfsi (int pz)
{
    viz[pz]=1;
    int mxc=0;
    for(int i=0;i<v[pz].size();++i)
    {
        int nn=v[pz][i];
        if(viz[nn] && vc[nn].vmin==0)
        {
            cout<<-1;
            exit(0);
        }
        if(!viz[nn])
            dfsi(nn);
        mxc=max(mxc,vc[nn].vmin);
    }
    if(fix[pz])
        vc[pz].vmin=fix[pz];
    else
        vc[pz].vmin=1+mxc;
}
void dfsup (int pz)
{
    viz[pz]=1;
    int mnc=k+1;
    for(int i=0;i<vr[pz].size();++i)
    {
        int nn=vr[pz][i];
        if(!viz[nn])
            dfsup(nn);
        mnc=min(mnc,vc[nn].vmax);
    }
    if(fix[pz])
        vc[pz].vmax=fix[pz];
    else
        vc[pz].vmax=mnc-1;
}
bool cmp (ura a, ura b)
{
    return a.vmin<b.vmin;
}
int elemx;
int heap[200003];
bool cmp1 (int a, int b)
{
    return vc[a].vmax<vc[b].vmax;
}
void insert (int val)
{
    heap[++elemx]=val;
    int pz=elemx;
    while(pz>1 && cmp1(heap[pz],heap[pz>>1]))
    {
        swap(heap[pz],heap[pz>>1]);
        pz>>=1;
    }
}
void del ()
{
    swap(heap[1],heap[elemx]);
    --elemx;
    int pz=1;
    while((pz<<1)<=elemx)
    {
        int fiu=(pz<<1);
        if(fiu+1<=elemx && cmp1(heap[fiu+1],heap[fiu]))
            ++fiu;
        if(cmp1(heap[fiu],heap[pz]))
        {
            swap(heap[pz],heap[fiu]);
            pz=fiu;
        }
        else break;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t,i,j,n,m;
    cin>>n>>m>>k;
    for(i=1;i<=n;++i)
    {
        cin>>fix[i];
        vc[i].pz=i;
    }
    for(i=1;i<=m;++i)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        vr[b].push_back(a);
    }
    for(i=1;i<=n;++i)
        if(!viz[i])
            dfsi(i);
    for(i=1;i<=n;++i)
        if(vc[i].vmin>k)
        {
            cout<<-1;
            return 0;
        }
    for(i=1;i<=n;++i)
        viz[i]=0;
    for(i=1;i<=n;++i)
        if(!viz[i])
            dfsup(i);
    for(i=1;i<=n;++i)
        if(vc[i].vmax<1 || vc[i].vmax<vc[i].vmin)
        {
            cout<<-1;
            return 0;
        }
    sort(vc+1,vc+n+1,cmp);
    j=1;
    for(int kc=1;kc<=k;++kc)
    {
        while(j<=n && vc[j].vmin==kc)
            insert(j++);
        int ok=0;
        while(elemx>0 && vc[heap[1]].vmax==kc)
        {
            ok=1;
            rzf[vc[heap[1]].pz]=kc;
            del();
        }
        if(ok)
            continue;
        if(elemx==0)
        {
            cout<<-1;
            return 0;
        }
        rzf[vc[heap[1]].pz]=kc;
        del();
    }
    while(elemx>0)
    {
        rzf[vc[heap[1]].pz]=k;
        del();
    }
    int ok=1;
    for(i=1;i<=n;++i)
        ++fv[rzf[i]];
    for(i=1;i<=n;++i)
    {
        for(j=0;j<v[i].size();++i)
        {
            if(rzf[i]<=rzf[v[i][j]])
                ok=0;
        }
    }
    for(i=1;i<=k;++i)
        if(!fv[i])
            ok=0;
    if(!ok)
    {
        cout<<-1;
        return 0;
    }
    for(i=1;i<=n;++i)
        cout<<rzf[i]<<' ';
}