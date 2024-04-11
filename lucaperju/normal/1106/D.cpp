#include <bits/stdc++.h>

using namespace std;
int viz[100005],cnt,st[100005],n,heap[100005],elemx;
vector<int>v[100005];
void baga(long long val)
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
    while(poz*2+1<=elemx && heap[poz]>min(heap[poz*2],heap[poz*2+1]))
    {
        if(heap[poz*2]<heap[poz*2+1])
        {
            swap(heap[poz*2],heap[poz]);
            poz<<=1;
        }
        else
        {
            swap(heap[poz*2+1],heap[poz]);
            poz<<=1;
            ++poz;
        }
    }
    if(poz*2==elemx && heap[poz]>heap[poz*2])
        swap(heap[poz],heap[poz*2]);
}
int main()
{
    long long i,j=1,k,s=0,cur,pz,m,ok=0;
    cin>>n>>m;
    for(i=1;i<=m;++i)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    baga(1);
    viz[1]=1;
    for(int y=1;y<=n;++y)
    {
        pz=heap[1];
        scoate();
        st[++s]=pz;
        for(i=0;i<v[pz].size();++i)
        {
            int nn=v[pz][i];
            if(!viz[nn])
            {
                baga(nn);
                viz[nn]=1;
            }
        }
    }
    for(i=1;i<=n;++i)
        cout<<st[i]<<' ';
    return 0;
}