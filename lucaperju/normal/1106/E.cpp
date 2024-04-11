#include <bits/stdc++.h>

using namespace std;
long long v[100005][201],n,k,care[100005],viz[100005],heap[100005],elemx;
void baga(long long val)/**\################################################################################HEAP*/
{
    heap[++elemx]=val;
    long long poz=elemx;
    while(poz>1 && heap[poz]<heap[poz/2])
    {
        swap(heap[poz],heap[poz/2]);
        poz>>=1;
    }
}
void scoate ()
{
    long long poz=1;
    swap(heap[1],heap[elemx]);
    --elemx;
    while(poz*1LL*2+1<=elemx && heap[poz]>min(heap[poz*1LL*2],heap[poz*1LL*2+1]))
    {
        if(heap[poz*1LL*2]<heap[poz*1LL*2+1])
        {
            swap(heap[poz*1LL*2],heap[poz]);
            poz<<=1;
        }
        else
        {
            swap(heap[poz*1LL*2+1],heap[poz]);
            poz<<=1;
            ++poz;
        }
    }
    if(poz*1LL*2==elemx && heap[poz]>heap[poz*1LL*2])
        swap(heap[poz],heap[poz*1LL*2]);
}
vector <long long> fv[100005];
struct ura
{
    long long a,b,c,d;
}x[100005];
long long idk (long long pz, long long cat) /// ############################################################################ FUNCTIE
{
    if(pz>n)
        return 0;
    if(v[pz][cat]!=-1)
        return v[pz][cat];
    if(cat)
    {
        if(care[pz]==0)
            v[pz][cat]=idk(pz+1,cat);
        else
            v[pz][cat]=min(idk(pz+1,cat-1),x[care[pz]].d+idk(x[care[pz]].c+1,cat));
    }
    else
    {
        if(care[pz]==0)
            v[pz][cat]=idk(pz+1,cat);
        else
            v[pz][cat]=x[care[pz]].d+idk(x[care[pz]].c+1,cat);
    }
    return v[pz][cat];
}
bool cmp (ura a, ura b)
{
    if(a.d>b.d)
        return true;
    if(a.d<b.d)
        return false;
    if(a.c>b.c)
        return true;
    return false;
}
int main()/**\#########################################################################################MAIN*/
{
    long long i,j,s=0,cur=0,pz,m,ok=0;
    cin>>n>>m>>k;
    for(i=1;i<=n;++i)
        for(j=0;j<=m;++j)
            v[i][j]=-1;
    for(i=1;i<=k;++i)
        cin>>x[i].a>>x[i].b>>x[i].c>>x[i].d;
    sort(x+1,x+k+1,cmp);
    for(i=1;i<=k;++i)
    {
        fv[x[i].a].push_back(i);
        fv[x[i].b+1].push_back(-i);
    }
    for(i=1;i<=n;++i)
    {
        for(j=0;j<fv[i].size();++j)
        {
            if(fv[i][j]>0)
            {
                baga(fv[i][j]);
                viz[fv[i][j]]=1;
            }
            else
                viz[-fv[i][j]]=0;
        }
        while(viz[heap[1]]==0 && elemx)
            scoate();
        if(elemx)
            care[i]=heap[1];
    }
    cout<<idk(1,m);
    return 0;
}