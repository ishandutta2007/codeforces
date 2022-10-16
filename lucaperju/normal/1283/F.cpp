#include <bits/stdc++.h>
using namespace std;
int elemx,v[200005],fv[200005];
struct ura
{
    int a,vf;
}heap[200005];
void baga (int a, int vf)
{
    heap[++elemx].a=a;
    heap[elemx].vf=vf;
    int pz=elemx;
    while(pz>1)
    {
        if(heap[pz/2].a>heap[pz].a)
        {
            swap(heap[pz],heap[pz/2]);
            pz>>=1;
        }
        else
            break;
    }
}
void scoate ()
{
    swap(heap[1],heap[elemx]);
    --elemx;
    int pz=1;
    while(pz*2<=elemx)
    {
        int fiu=pz*2;
        if(fiu+1<=elemx && heap[fiu+1].a<heap[fiu].a)
            ++fiu;
        if(heap[fiu].a<heap[pz].a)
        {
            swap(heap[fiu],heap[pz]);
            pz=fiu;
        }
        else
            break;
    }
}
int p[200005];
int main()
{
    long long n,t,i,j,k=0,pas=1<<20,m,mx=0,sc,rz=0;
    cin>>n;
    for(i=1;i<n;++i)
    {
        cin>>v[i];
        ++fv[v[i]];
        if(fv[v[i]]==1)
            p[i]=1;
    }
    cout<<v[1]<<'\n';
    for(i=1;i<=n;++i)
        if(!fv[i])
            baga(i,i);
    for(i=n-1;i>=1;--i)
    {
        cout<<v[i]<<' '<<heap[1].vf<<'\n';
        int an=max(heap[1].a,v[i]);
        scoate();
        if(p[i])
        baga(an,v[i]);
    }
    return 0;
}