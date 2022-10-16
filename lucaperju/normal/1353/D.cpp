#include <bits/stdc++.h>

using namespace std;
int v[200005];
struct ura
{
  int l,st,dr;
}heap[200005];
int elemx=0;
void baga (int st, int dr, int l)
{
    heap[++elemx]={l,st,dr};
    int pz=elemx;
    while(pz>1)
    {
        if(heap[pz].l>heap[pz/2].l || heap[pz].l==heap[pz/2].l && heap[pz].st<heap[pz/2].st)
        {
            swap(heap[pz],heap[pz/2]);
            pz>>=1;
        }
        else
            break;
    }
}
void scoate()
{
    swap(heap[1],heap[elemx]);
    --elemx;
    int pz=1;
    while(pz*2<=elemx)
    {
        int fiu=pz*2;
        if(fiu+1<=elemx && heap[fiu+1].l>heap[fiu].l || heap[fiu].l==heap[fiu+1].l && heap[fiu].st>heap[fiu+1].st)
            ++fiu;
        if(heap[pz].l<heap[fiu].l || heap[pz].l==heap[fiu].l && heap[pz].st>heap[fiu].st)
        {
            swap(heap[pz],heap[fiu]);
            pz=fiu;
        }
        else
            break;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long m,n,i,t,j,k,mx,p,mxx=0;
    cin>>t;
    while(t--)
    {
        cin>>n;
        elemx=0;
        baga(1,n,n);
        for(i=1;i<=n;++i)
        {
            int st=heap[1].st;
            int dr=heap[1].dr;
            v[(st+dr)/2]=i;
            scoate();
            int mid=(st+dr)/2;
            baga(st,mid-1,mid-st);
            baga(mid+1,dr,dr-mid);
        }
        for(i=1;i<=n;++i)
            cout<<v[i]<<' ';
        cout<<'\n';
    }
    return 0;
}